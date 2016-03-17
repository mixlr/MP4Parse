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
#ifndef _MP4_STSD_H_
#define _MP4_STSD_H_
#pragma once

#include "mp4.h"
#include "MP4.DataAtom.h"
#include "MP4.BinaryStream.h"

namespace MP4
{
    class STSD : DataAtom
    {
        private:

           uint32_t m_aot;
           uint32_t m_sampleRate;
           uint32_t m_channelConfig;

           int32_t readTagLength( MP4::BinaryStream * stream, uint8_t tag, uint32_t &paddingOut );
           bool    readBoxType( MP4::BinaryStream * stream, std::string name );

           bool     m_valid;

        protected:
            
            
        public:
            
            STSD( void );
            
            std::string description( void );
            void processData( MP4::BinaryStream * stream, size_t length );

            uint32_t getAOT() { return m_aot; }
            uint32_t getSampleRate () { return m_sampleRate; }
            uint32_t getChannelConfig () { return m_channelConfig; }

            virtual bool isValid() { return m_valid; }
    };
}

#endif /* _MP4_STSD_H_ */
