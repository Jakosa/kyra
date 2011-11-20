/*  Copyright (C) 2011 Twl
	(http://www.github.com/twl)

	Project: http://www.github.com/twl/kyra
*/

#include "stdafx.h"



int main(/*int argc, char* argv[]*/)
{
	boost::asio::io_service io;
	boost::shared_ptr<kyra::irc::connection> conn(new kyra::irc::connection(io, "irc.x2x.cc", 6660, "Kyrax", "Kyrax"));
	conn->run();
	conn->connect();
	io.run();

	std::cin.get();
	return 0;
}

