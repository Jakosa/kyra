/*  Copyright (C) 2011 Twl
	(http://www.github.com/twl)

	Project: http://www.github.com/twl/kyra
*/

#ifndef _KYRA_IRC_CON
#define _KYRA_IRC_CON

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "stdafx.h"
#include "irc/irc_message.hpp"

namespace kyra
{
	namespace irc
	{
		struct status
		{
			static const int not_connected = 0;
			static const int resolving = 1;
			static const int connected = 2;
			static const int registering = 3;
			static const int registered = 4;
		};

		typedef boost::function<void (message const&)> opcode_handler;

		class connection : public boost::enable_shared_from_this<connection>
		{
		public:

			connection(boost::asio::io_service& ios, std::string ircHost, unsigned short port, std::string nick, std::string user);
			~connection();

			std::string irc_host() const;
			void irc_host(std::string);
			int status() const;

			void raw_write(std::string data);

			void connect();
			void disconnect();
			void finishSending();
			void send(int priority, std::string const& message);
			void flush();

			void run();

			boost::function<void ()> on_connect;
			boost::function<void (const std::string&)> on_message;
			boost::function<void ()> on_disconnect;
			
			void addHandler(std::string opcode, opcode_handler handler);

		protected:
			void handle_resolve(boost::system::error_code const&, boost::asio::ip::tcp::resolver::iterator);
			void handle_connect(boost::system::error_code const&);
			void handle_read(boost::system::error_code const&, std::size_t);

			void handle_data(std::string const&);

			void handle_message(std::string);

			void handle_registered(message const&);
			void handle_ping(message const&);
		private:

			void receive();
			void receive_finished(boost::system::error_code const& ec);
			void send();
			void send_finished(boost::system::error_code const& ec);

			boost::asio::io_service& io_service;
			boost::asio::ip::tcp::resolver resolver;
			boost::asio::ip::tcp::socket socket;
			boost::asio::streambuf inc_buffer;

			std::priority_queue<net_message> out_queue;
			net_message current_message;

			std::string m_irc_host;
			unsigned short m_irc_port;
			std::string m_nick;
			std::string m_user;

			std::string lastLine;
			bool sending;

			int connection_status;
			bool sent_registering_packets;
			
			boost::unordered_map<std::string, opcode_handler> handlers;
			
		};
	}
}

#endif