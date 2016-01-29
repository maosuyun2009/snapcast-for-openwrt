/***
    This file is part of snapcast
    Copyright (C) 2015  Johannes Pohl

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#ifndef TIME_DEFS_H
#define TIME_DEFS_H

#include <chrono>
#include <sys/time.h>

namespace chronos
{
	typedef std::chrono::high_resolution_clock hrc;
	typedef std::chrono::time_point<hrc> time_point_hrc;
	typedef std::chrono::seconds sec;
	typedef std::chrono::milliseconds msec;
	typedef std::chrono::microseconds usec;
	typedef std::chrono::nanoseconds nsec;

	inline static void addUs(timeval& tv, int us)
	{
		if (us < 0)
		{
			timeval t;
			t.tv_sec = -us / 1000000;
			t.tv_usec = (-us % 1000000);
			timersub(&tv, &t, &tv);
			return;
		}
		tv.tv_usec += us;
		tv.tv_sec += (tv.tv_usec / 1000000);
		tv.tv_usec %= 1000000;
	}

	inline static long getTickCount()
	{
		struct timespec now;
		clock_gettime(CLOCK_MONOTONIC, &now);
		return now.tv_sec*1000 + now.tv_nsec / 1000000;
	}

	template <class Rep, class Period>
	inline std::chrono::duration<Rep, Period> abs(std::chrono::duration<Rep, Period> d)
	{
		Rep x = d.count();
		return std::chrono::duration<Rep, Period>(x >= 0 ? x : -x);
	}

	template <class ToDuration, class Rep, class Period>
	inline int64_t duration(std::chrono::duration<Rep, Period> d)
	{
		return std::chrono::duration_cast<ToDuration>(d).count();
	}
}


#endif


