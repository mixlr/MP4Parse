/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina - www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

#include "MP4.File.h"

#include "MP4.STSZ.h"
#include "MP4.STTS.h"
#include "MP4.STSD.h"
#include "MP4.MDAT.h"
#include "MP4.STCO.h"

using namespace MP4;

std::string File::description( void )
{
    std::string s;
    std::multimap< std::string, Atom * >::iterator it;
    
    s += "MP4 File:\n";
    
    for( it = this->_children.begin(); it != this->_children.end(); ++it )
    {
        s.append( ( ( Atom * )( it->second ) )->description() );
    }
    
    return s;
}

bool File::initialiseM4ADecoding()
{
    std::string atom = "STCO";
    Atom *stco = findChild( atom );
    uint32_t dataOffset = 0;
    if ( stco && stco->isValid() )
    {
        dataOffset = ( ( MP4::STCO* )stco )->getDataOffset();
    }
    else
    {
        return false;
    }

    atom = "STSZ";
    Atom *stsz = findChild( atom );
    std::vector< uint32_t > *sampleSizes = NULL;
    if ( stsz && stsz->isValid() )
    {
        sampleSizes = ( ( MP4::STSZ* )stsz )->getSampleSizes();
    }
    else
    {
        return false;
    }

    atom = "STSD";
    Atom *stsd = findChild( atom );
    uint32_t aot, sampleRate, channelConfig;
    if ( stsd && stsd->isValid() )
    {
        aot = ( ( MP4::STSD* )stsd )->getAOT();
        sampleRate = ( ( MP4::STSD* )stsd )->getSampleRate();
        channelConfig = ( ( MP4::STSD* )stsd )->getChannelConfig();
    }
    else
    {
        return false;
    }

    atom = "STTS";
    Atom *stts = findChild( atom );
    TimeData *sampleTimes = NULL;
    uint32_t totalTime = 0;
    if ( stts  && stts->isValid() )
    {
        sampleTimes = ( ( MP4::STTS* )stts )->getSampleTimes();
        totalTime = ( ( MP4::STTS* )stts )->getTotalTime();
    }
    else
    {
        return false;
    }

    atom = "MDAT";
    Atom *mdat = findChild( atom );
    if ( mdat && mdat->isValid() )
    {
        m_aacData = ( MP4::MDAT* )mdat;
        return m_aacData->initialiseAACGenerator( dataOffset, sampleSizes, sampleTimes, aot, sampleRate, channelConfig );
    }
    else
    {
        return false;
    }
}

bool File::generateAACFrame( char *frameOut )
{
    if ( m_aacData )
    {
        return m_aacData->generateAACFrame( frameOut );
    }
    else
    {
        return false;
    }
}

bool File::seek( int offsetSeconds, int sampleRate )
{
    if ( m_aacData )
    {
        return m_aacData->seek( offsetSeconds, sampleRate );
    }
    else
    {
        return false;
    }
}
