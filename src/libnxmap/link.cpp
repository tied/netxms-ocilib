/*
** NetXMS - Network Management System
** Network Maps Library
** Copyright (C) 2003-2010 Victor Kirhenshtein
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
** File: link.cpp
**
**/

#include "libnxmap.h"


/**
 * Constructor
 */
NetworkMapLink::NetworkMapLink(UINT32 e1, UINT32 e2, int type)
{
	m_element1 = e1;
	m_element2 = e2;
	m_type = type;
	m_name = NULL;
	m_connectorName1 = NULL;
	m_connectorName2 = NULL;
	m_config = _tcsdup(_T("\0"));
	m_flags = 0;
}


/**
 * Constuctor: create link object from NXCP message
 */
NetworkMapLink::NetworkMapLink(NXCPMessage *msg, UINT32 baseId)
{
	m_type = msg->getFieldAsUInt16(baseId);
	m_name = msg->getFieldAsString(baseId + 1);
	m_connectorName1 = msg->getFieldAsString(baseId + 2);
	m_connectorName2 = msg->getFieldAsString(baseId + 3);
	m_element1 = msg->getFieldAsUInt32(baseId + 4);
	m_element2 = msg->getFieldAsUInt32(baseId + 5);
	m_config = msg->getFieldAsString(baseId + 6);
	m_flags = msg->getFieldAsUInt32(baseId + 7);
}


/**
 * Map link destructor
 */
NetworkMapLink::~NetworkMapLink()
{
	safe_free(m_name);
	safe_free(m_connectorName1);
	safe_free(m_connectorName2);
	safe_free(m_config);
}


/**
 * Set name
 */
void NetworkMapLink::setName(const TCHAR *name)
{
	safe_free(m_name);
	m_name = (name != NULL) ? _tcsdup(name) : NULL;
}


/**
 * Set connector 1 name
 */
void NetworkMapLink::setConnector1Name(const TCHAR *name)
{
	safe_free(m_connectorName1);
	m_connectorName1 = (name != NULL) ? _tcsdup(name) : NULL;
}

/**
 * Set config(color, bendPoints, dciList, objectStatusList, routing)
 */
void NetworkMapLink::setConfig(const TCHAR *name)
{
	safe_free(m_config);
	m_config = (name != NULL) ? _tcsdup(name) : NULL;
}

/**
 * Set connector 2 name
 */
void NetworkMapLink::setConnector2Name(const TCHAR *name)
{
	safe_free(m_connectorName2);
	m_connectorName2 = (name != NULL) ? _tcsdup(name) : NULL;
}

/**
 * Fill NXCP message
 */
void NetworkMapLink::fillMessage(NXCPMessage *msg, UINT32 baseId)
{
	msg->setField(baseId, (WORD)m_type);
	msg->setField(baseId + 1, getName());
	msg->setField(baseId + 2, getConnector1Name());
	msg->setField(baseId + 3, getConnector2Name());
	msg->setField(baseId + 4, m_element1);
	msg->setField(baseId + 5, m_element2);
	msg->setField(baseId + 6, m_config);
   msg->setField(baseId + 7, m_flags);
}


