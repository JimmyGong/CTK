/*=========================================================================

  Library:   CTK
 
  Copyright (c) 2010  Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 
=========================================================================*/
/*=========================================================================

   Program: ParaView
   Module:    $RCSfile: pqSettings.h,v $

   Copyright (c) 2005-2008 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2. 

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/

/// \file ctkSettings.h
///
/// \date 02/03/2010

#ifndef __ctkSettings_h
#define __ctkSettings_h

// Qt includes
#include <QSettings>

// CTK includes
#include "CTKWidgetsExport.h"

class QDialog;
class QMainWindow;

/// ctkSettings is a QSettings that additionally can save and restore the 
/// state (position/size) of QMainWindow and QDialogs.
class CTK_WIDGETS_EXPORT ctkSettings : public QSettings
{
  Q_OBJECT

public:
  ctkSettings(
    const QString& organization,
    const QString& application,
    QObject* p);
    
  void saveState(const QMainWindow& window, const QString& key);
  void saveState(const QDialog& dialog, const QString& key);
  
  void restoreState(const QString& key, QMainWindow& window);
  void restoreState(const QString& key, QDialog& dialog);

  /// Calling this method will cause the modified signal to be emited.
  void alertSettingsModified();

signals:
  void modified();
};

#endif
