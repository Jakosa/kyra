/*  Copyright (C) 2011 Twl
	(http://www.github.com/twl)

	Project: http://www.github.com/twl/kyra
*/

#pragma once
#pragma warning(disable: 4512) // triggered within Boost.


#if defined(_WIN32)
#include "targetver.h"
#endif

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>


#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/signal.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/assert.hpp>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/unordered_map.hpp>
#include <boost/regex.hpp>

/* project */
#include "irc/irc_replies.hpp"
#include "irc/irc_message.hpp"
#include "irc/irc_connection.hpp"

