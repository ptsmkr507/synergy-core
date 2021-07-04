/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2002 Chris Schoeneman
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
 
#pragma once

#include "common/IInterface.h"
#include "synergy/IApp.h"
#include "base/String.h"

class IAppUtil : public IInterface {
public:
    virtual void adoptApp(IApp* app) = 0;
    virtual IApp& app() const = 0;
    virtual int run(int argc, char** argv) = 0;
    virtual void beforeAppExit() = 0;
    virtual void startNode() = 0;
    virtual std::vector<String> getKeyboardLayoutList() = 0;
    virtual void getKeyboardLayoutsDiff(const String& compressedLanguages,
                                        std::vector<String>& missedLang,
                                        std::vector<String>& supportedLang) = 0;
    virtual void showMessageBox(const String& title, const String& text) = 0;
    virtual void showNotification(const String& title, const String& text) const = 0;
};
