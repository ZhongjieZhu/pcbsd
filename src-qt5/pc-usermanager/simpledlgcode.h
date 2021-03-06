/***************************************************************************
 *   Copyright (C) 2007 by Tim McCormick   *
 *   tim@pcbsd.org   *
 *                                                                         *
 *   Permission is hereby granted, free of charge, to any person obtaining *
 *   a copy of this software and associated documentation files (the       *
 *   "Software"), to deal in the Software without restriction, including   *
 *   without limitation the rights to use, copy, modify, merge, publish,   *
 *   distribute, sublicense, and/or sell copies of the Software, and to    *
 *   permit persons to whom the Software is furnished to do so, subject to *
 *   the following conditions:                                             *
 *                                                                         *
 *   The above copyright notice and this permission notice shall be        *
 *   included in all copies or substantial portions of the Software.       *
 *                                                                         *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       *
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    *
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. *
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR     *
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, *
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR *
 *   OTHER DEALINGS IN THE SOFTWARE.                                       *
 ***************************************************************************/
#ifndef SIMPLEDLGCODE_H
#define SIMPLEDLGCODE_H

#include "ui_SimpleDlg.h"
#include "usermanagerback.h"
#include "group.h"
#include "changepasscode.h"
#include "simpleaddcode.h"
#include <qcolor.h>
        
#include <qpixmap.h>

class SimpleDlgCode: public QDialog, private Ui::SimpleDlg {
Q_OBJECT
public:
    SimpleDlgCode() : QDialog()
    {
        setupUi(this);
    }
    void programInit(UserManagerBackend *back, QString);
    
private:
    UserManagerBackend *back;
    QPixmap userImage;
    Group *wheel;
    bool systemChange;
    ChangePassCode *changePassUi;
    SimpleAddCode *addUserUi;
    QString chroot;
    
public slots:
    void advancedPressed();
    void getUserDetails(const QString &username);
    void fullnameChanged();
    void canAdminChanged(bool on);
    void changePassword();
    void changeRootPassword();
    void removeUser();
    void refreshUsers();
    void addUser();
    
signals:
    void advancedView();
    void changed();
};

#endif
