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
#ifndef _MP4_MDAT_H_
#define _MP4_MDAT_H_
#pragma once

#include "mp4.h"
#include "MP4.DataAtom.h"
#include "MP4.BinaryStream.h"
#include "MP4.STTS.h"

namespace MP4
{
    class MDAT : DataAtom
    {
        private:
            
            void generateADTS( char *adtsHeader, uint64_t sampleSize, uint32_t aot, uint32_t sampleRate, uint32_t channelConfig ) const;
            bool seekAACFrame( uint32_t sampleIdx );

            MP4::BinaryStream*  _stream;
            size_t              _length;

            bool                      m_initialised;
            uint32_t                  m_dataOffset;
            std::vector< uint32_t >*  m_sampleSizes;
            TimeData*                 m_sampleTimes;
            uint32_t                  m_aot;
            uint32_t                  m_sampleRate;
            uint32_t                  m_channelConfig;
            uint32_t                  m_sampleIdx;

            const static int          m_kSampleRates[];
        protected:
            
            
        public:
            
            MDAT( void );
            
            std::string description( void );
            void processData( MP4::BinaryStream * stream, size_t length );
            bool initialiseAACGenerator( uint32_t dataOffset, std::vector< uint32_t > *sampleSizes, TimeData *sampleTimes,
                                         uint32_t aot, uint32_t sampleRate, uint32_t channelConfig );
            bool generateAACFrame( char *frameOut );
            bool seek( int offsetSeconds, int sampleRate );
    };
}

#endif /* _MP4_MDAT_H_ */
