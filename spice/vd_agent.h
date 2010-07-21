/*
   Copyright (C) 2009 Red Hat, Inc.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:

       * Redistributions of source code must retain the above copyright
         notice, this list of conditions and the following disclaimer.
       * Redistributions in binary form must reproduce the above copyright
         notice, this list of conditions and the following disclaimer in
         the documentation and/or other materials provided with the
         distribution.
       * Neither the name of the copyright holder nor the names of its
         contributors may be used to endorse or promote products derived
         from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS "AS
   IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
   TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
   PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _H_VD_AGENT
#define _H_VD_AGENT

#include <spice/types.h>

#include <spice/start-packed.h>

typedef struct SPICE_ATTR_PACKED VDAgentMessage {
    uint32_t protocol;
    uint32_t type;
    uint64_t opaque;
    uint32_t size;
    uint8_t data[0];
} VDAgentMessage;

#define VD_AGENT_PROTOCOL 1
#define VD_AGENT_MAX_DATA_SIZE 2048
#define VD_AGENT_CLIPBOARD_MAX_SIZE_DEFAULT 1024
#define VD_AGENT_CLIPBOARD_MAX_SIZE_ENV "SPICE_CLIPBOARD_MAX_SIZE"

enum {
    VD_AGENT_MOUSE_STATE = 1,
    VD_AGENT_MONITORS_CONFIG,
    VD_AGENT_REPLY,
    VD_AGENT_CLIPBOARD,
};

typedef struct SPICE_ATTR_PACKED VDAgentMonConfig {
    uint32_t height;
    uint32_t width;
    uint32_t depth;
    int32_t x;
    int32_t y;
} VDAgentMonConfig;

enum {
    VD_AGENT_CONFIG_MONITORS_FLAG_USE_POS = (1 << 0),
};

typedef struct SPICE_ATTR_PACKED VDAgentMonitorsConfig {
    uint32_t num_of_monitors;
    uint32_t flags;
    VDAgentMonConfig monitors[0];
} VDAgentMonitorsConfig;

#define VD_AGENT_LBUTTON_MASK (1 << 1)
#define VD_AGENT_MBUTTON_MASK (1 << 2)
#define VD_AGENT_RBUTTON_MASK (1 << 3)
#define VD_AGENT_UBUTTON_MASK (1 << 4)
#define VD_AGENT_DBUTTON_MASK (1 << 5)

typedef struct SPICE_ATTR_PACKED VDAgentMouseState {
    uint32_t x;
    uint32_t y;
    uint32_t buttons;
    uint8_t display_id;
} VDAgentMouseState;

typedef struct SPICE_ATTR_PACKED VDAgentReply {
    uint32_t type;
    uint32_t error;
} VDAgentReply;

enum {
    VD_AGENT_SUCCESS = 1,
    VD_AGENT_ERROR,
};

//FIXME: size required?
typedef struct SPICE_ATTR_PACKED VDAgentClipboard {
    uint32_t type;
    uint8_t data[0];
} VDAgentClipboard;

enum {
    VD_AGENT_CLIPBOARD_UTF8_TEXT = 1,
};


#include <spice/end-packed.h>

#endif /* _H_VD_AGENT */
