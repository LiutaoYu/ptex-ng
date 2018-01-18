/*************************************************************************
** Directory.hpp                                                        **
**                                                                      **
** This file is part of dvisvgm -- a fast DVI to SVG converter          **
** Copyright (C) 2005-2018 Martin Gieseking <martin.gieseking@uos.de>   **
**                                                                      **
** This program is free software; you can redistribute it and/or        **
** modify it under the terms of the GNU General Public License as       **
** published by the Free Software Foundation; either version 3 of       **
** the License, or (at your option) any later version.                  **
**                                                                      **
** This program is distributed in the hope that it will be useful, but  **
** WITHOUT ANY WARRANTY; without even the implied warranty of           **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         **
** GNU General Public License for more details.                         **
**                                                                      **
** You should have received a copy of the GNU General Public License    **
** along with this program; if not, see <http://www.gnu.org/licenses/>. **
*************************************************************************/

#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <string>
#ifdef _WIN32
	#include "windows.hpp"
#else
	#include <dirent.h>
#endif

class Directory {
	public:
		enum EntryType {ET_FILE, ET_DIR, ET_FILE_OR_DIR};

	public:
		Directory ();
		Directory (const std::string &path);
		~Directory ();
		bool open (std::string path);
		void close ();
		const char* read (EntryType type=ET_FILE_OR_DIR);

	private:
		std::string _dirname;
#ifdef _WIN32
		bool _firstread;
		HANDLE _handle;
		WIN32_FIND_DATA _fileData;
#else
		DIR *_dir;
		struct dirent *_dirent;
#endif
};

#endif
