/***************************************************************************
                          kdiff3.h  -  description
                             -------------------
    begin                : March 26 17:44 CEST 2002
    copyright            : (c) 2008 by Valentin Rusu
    email                : kde at rusu.info
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef GUIUTILS_H
#define GUIUTILS_H

#include <QObject>
#include <kactioncollection.h>

namespace KDiff3 {

   template <class T>
   T* createAction( 
     const QString& text, 
     const QObject* receiver, 
     const char* slot, 
     KActionCollection* ac, 
     const QString &actionName);
   
   template <>
   inline QAction * createAction<QAction>( 
                   const QString& text, 
                   const QObject* receiver, 
                   const char* slot, 
                   KActionCollection* ac, 
                   const QString &actionName)    {
      Q_ASSERT( ac != nullptr );
      QAction * theAction = ac->addAction( actionName );
      theAction->setText( text );
      QObject::connect( theAction, SIGNAL( triggered() ), receiver, slot );
      return theAction;
   }
   template <>
   inline KToggleAction* createAction<KToggleAction>( 
                   const QString& text, 
                   const QObject* receiver, 
                   const char* slot, 
                   KActionCollection* ac, 
                   const QString &actionName)    {
      Q_ASSERT( ac != nullptr );
      KToggleAction* theAction = new KToggleAction(ac);
      ac->addAction( actionName, theAction );
      theAction->setText( text );
      QObject::connect( theAction, SIGNAL( triggered(bool) ), receiver, slot );
      return theAction;
   }
   
   template <class T>
   T* createAction( 
     const QString& text, 
     const QKeySequence& shortcut, 
     const QObject* receiver, 
     const char* slot, 
     KActionCollection* ac, 
     const QString &actionName) 
   {
      T* theAction = createAction<T>( text, receiver, slot, ac, actionName );
      ac->setDefaultShortcut(theAction, shortcut);
      return theAction;
   }
   template <class T>
   T* createAction(
      const QString& text,
      const QIcon& icon,
      const QObject* receiver,
      const char* slot,
      KActionCollection* ac,
      const QString &actionName)
   {
      T* theAction = createAction<T>( text, receiver, slot, ac, actionName );
      theAction->setIcon( icon );
      return theAction;
   }
   template <class T>
   T* createAction(
      const QString& text,
      const QIcon& icon,
      const QString& iconText,
      const QObject* receiver,
      const char* slot,
      KActionCollection* ac,
      const QString &actionName)
   {
      T* theAction = createAction<T>( text, receiver, slot, ac, actionName );
      theAction->setIcon( icon );
      theAction->setIconText( iconText );
      return theAction;
   }
   template <class T>
   T* createAction(
     const QString& text,
     const QIcon& icon,
     const QKeySequence& shortcut,
     const QObject* receiver,
     const char* slot,
     KActionCollection* ac,
     const QString &actionName)
   {
      T* theAction = createAction<T>( text, shortcut, receiver, slot, ac, actionName );
      theAction->setIcon( icon );
      return theAction;
   }
   template <class T>
   T* createAction(
         const QString& text,
         const QIcon& icon,
         const QString& iconText,
         const QKeySequence& shortcut,
         const QObject* receiver,
         const char* slot,
         KActionCollection* ac,
         const QString &actionName)
   {
      T* theAction = createAction<T>( text, shortcut, receiver, slot, ac, actionName );
      theAction->setIcon( icon );
      theAction->setIconText( iconText );
      return theAction;
   }
}

#endif
