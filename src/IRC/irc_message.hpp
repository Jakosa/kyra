/*  Copyright (C) 2011 Twl
	(http://www.github.com/twl)

	Project: http://www.github.com/twl/kyra
*/

#ifndef _KYRA_IRC_MESSAGE
#define _KYRA_IRC_MESSAGE

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "stdafx.h"

namespace kyra
{
	namespace irc
	{
		class connection;

		struct message
		{
			std::string hostmask;
			std::string opcode;
			std::string channel;
			std::string args;	

			// split from :abyss!abyss@abyss.the.host
			std::string nick; // abyss
			std::string user; // abyss
			std::string host; // abyss.the.host

			std::string full;
			boost::shared_ptr<connection> connection;
		};

		struct net_message
		{
			net_message()
			{
				priority = 0;
				message = "";
			}
			
			net_message(int priority, std::string msg)
			{
				this->priority = priority;
				message = msg + "\r\n";
			}

			int priority;
			std::string message;

			bool operator <(const net_message& other) const
			{
				return priority < other.priority;
			}
		};
	}
}

#endif