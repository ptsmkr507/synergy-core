/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2015-2016 Symless Ltd.
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "server/ClientProxy1_7.h"
#include "server/Server.h"
#include "synergy/AppUtil.h"
#include "synergy/ProtocolUtil.h"
#include "base/TMethodEventJob.h"
#include "base/Log.h"

//
// ClientProxy1_7
//

ClientProxy1_7::ClientProxy1_7(const String& name, synergy::IStream* stream, Server* server, IEventQueue* events) :
    ClientProxy1_6(name, stream, server, events),
    m_events(events)
{

}

ClientProxy1_7::~ClientProxy1_7()
{

}

void
ClientProxy1_7::secureInputNotification(const String& app)
{
    LOG((CLOG_DEBUG2 "send secure input notification to \"%s\" %s", getName().c_str(), app.c_str()));
    ProtocolUtil::writef(getStream(), kMsgDSecureInputNotification, &app);
}
