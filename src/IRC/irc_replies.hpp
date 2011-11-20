/*  Copyright (C) 2011 Twl
	(http://www.github.com/twl)

	Project: http://www.github.com/twl/kyra
*/

#ifndef _KYRA_IRC_REPLIES
#define _KYRA_IRC_REPLIES

#pragma once

namespace kyra
{
	namespace irc
	{
		namespace replies
		{
			static const std::string successful_auth = "001";
			static const std::string motd = "372";
			static const std::string motd_start = "375";
			static const std::string motd_end = "376";
			static const std::string notice = "NOTICE";
			static const std::string privmsg = "PRIVMSG";
			static const std::string nick = "NICK";
			static const std::string join = "JOIN";
			static const std::string leave = "PART";
			static const std::string quit = "QUIT";

			static const std::string ping = "PING";
			static const std::string pong = "PONG";

			static const std::string kill = "KILL";
			static const std::string kick = "KICK";
			static const std::string mode = "MODE";
			static const std::string reply_404 = "404";
			static const std::string nick_error = "433";
			static const std::string channel_ban = "474";
			static const std::string no_channel_password = "475";
			static const std::string reply_319 = "319";

			static const std::string unknown = "002";
			static const std::string unknown1 = "003";
			static const std::string unknown2 = "004";
			static const std::string unknown3 = "005";
			static const std::string unknown4 = "042";
			static const std::string unknown5 = "251";
			static const std::string unknown6 = "252";
			static const std::string unknown7 = "253";
			static const std::string unknown8 = "254";
			static const std::string unknown9 = "255";
			static const std::string unknown10 = "265";
			static const std::string unknown11 = "266";
			static const std::string unknown12 = "332";
			static const std::string unknown13 = "333";
			static const std::string unknown14 = "353";
			static const std::string unknown15 = "366";
			static const std::string unknown16 = "412";
			static const std::string unknown17 = "439";
			static const std::string unknown18 = "462";
			static const std::string unknown19 = "451";

			static const std::string whois = "310";
			static const std::string whois1 = "311";
			static const std::string whois2 = "312";
			static const std::string whois3 = "317";
			static const std::string whois4 = "318";
			static const std::string whois5 = "338";
			static const std::string whois6 = "301";
			static const std::string whois7 = "307";
			static const std::string whois8 = "671";
			static const std::string whois9 = "672";
		}
	}
}

#endif