/** 
 * @file teapot.h
 * @brief teapot viewer helper library
 *
 * Copyright (C) 2012 arminweatherwax (at) lavabit.com
 * You can use it under the following license:
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
 */

#ifndef TEAPOT_H
#define TEAPOT_H

#include "linden_common.h"
#include "llprocesslauncher.h"
#include "llsingleton.h"

#if LL_WINDOWS
#include <windows.h>
#endif

class Teapot
:public LLSingleton<Teapot>
{
public:
	Teapot();
	~Teapot();

	// this is under development and likely changing
	bool launchNewViewer(const std::vector<std::string>& args);
private:
	// this is under development and likely changing
	bool loadExternalApplication(const std::string& executable,
					const std::string& workingdir,
					const std::vector<std::string>& args,
					const bool zombify = false);
#if LL_WINDOWS
	typedef  HANDLE process_id_t;
#else
	typedef  pid_t process_id_t;
#endif
	struct process_info
	{
		LLProcessLauncher* mLauncher;
		bool mZombify;
	};

	std::map<process_id_t, process_info> mProcessMap;

};

#endif //TEAPOT_H
