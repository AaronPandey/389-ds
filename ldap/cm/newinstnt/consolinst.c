/** BEGIN COPYRIGHT BLOCK
 * Copyright 2001 Sun Microsystems, Inc.
 * Portions copyright 1999, 2001-2003 Netscape Communications Corporation.
 * All rights reserved.
 * END COPYRIGHT BLOCK **/
//////////////////////////////////////////////////////////////////////////////
// CONSOLINST.c - Brandx Directory Server Installation Plug-In 
//
//
#include <windows.h>
#include <commctrl.h>
#include <nssetup.h>

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <process.h>
#include <memory.h>
#include <regstr.h>
#include <ldap.h>
#include "resource.h"
#include "consolinst.h"

#define NUM_PROP_PAGES 1

#define INDEX_FIRST_PAGE 0
#define INDEX_LAST_PAGE  0


static MODULEINFO mi = {
  NULL,           // m_hModule
  NULL,           // m_hwndParent
  NS_WIZERROR,    // m_nResult
};

//////////////////////////////////////////////////////////////////////////////
// _DialogProcs
//
// The dialog procedure for a single property page.  You will need to create
// one of these for each property page used in the property sheet.  This
// procedure processes dialog messages sent to your property page by Windows.
// See the Windows SDK documentation for more information about this function.
//



//////////////////////////////////////////////////////////////////////////////
// TMPL_PreInstall
//
// This function is called by the installation framework before asking the
// user any questions.  Here you should determine if all of the requisites
// for installing this component are being met.  If this operation succeeds
// return TRUE, otherwise display an error message and return FALSE to abort
// installation.
//

BOOL __declspec(dllexport)
CONSOLINST_PreInstall(LPCSTR lpszInstallPath)
{
  // TODO: Add code to check for pre-installation requirements.
  
  
  return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// CONSOLINST_AskOptions
//
// This function is called by the installation framework to query the user for
// information about your component.  Here you should ask all of the questions
// required to install your component as a series of wizard property sheets.
//

INT __declspec(dllexport)
CONSOLINST_AskOptions(HWND hwndParent, INT nDirection)
{
  PROPSHEETPAGE psp[NUM_PROP_PAGES];
  UINT uStartPage;
  INT nNumPages;

  // TODO: Initialize a property page for each dialog template/resource
  // required to query the user for options related to your server
  // installation.  Don't forget to increment the count of pages contained
  // in NUM_PROP_PAGES at the top of this file.

  

  if( SILENTMODE == MODE)
  {
     mi.m_nResult = NS_WIZNEXT;
  }else{

  if(EXPRESSMODE == MODE)
  {

  }else if( (NORMALMODE == MODE) || (CUSTOMMODE == MODE) ){
      /* ask for server settings, SuitespotID and Unrestricted User */
  }

  /* add additional pages for custom mode */
  if( (CUSTOMMODE == MODE) )
  {
 
  }

  // Must initialize the result to an error code before calling WizardDialog
  mi.m_nResult = NS_WIZERROR;

  // Set the first page to display based on the direction we are travelling
  uStartPage = (nDirection == NS_WIZBACK) ? INDEX_LAST_PAGE : INDEX_FIRST_PAGE;

  // Call WizardDialog to display the set of property pages
  if (WizardDialog(mi.m_hModule, hwndParent, psp, nNumPages, uStartPage) < 0)
  {
    mi.m_nResult = NS_WIZERROR;
  }

  }
  return mi.m_nResult;
}

//////////////////////////////////////////////////////////////////////////////
// CONSOLINST_GetSummary
//
// This function is called by the installation framework after all questions,
// for all components, have been asked.  Here you should provide a detailed
// summary explaining all of the choices selected by the user.
//
// IMPORTANT NOTE: Each line MUST end in a carriage return/line feed
// combination ("\r\n") as this string is placed in an edit control.  Edit
// controls do not properly handle single "\n" end-of-line characters.
//

VOID __declspec(dllexport)
CONSOLINST_GetSummary(LPSTR lpszSummary)
{
   
  // TODO: Add code to fill in the summary information entered by the user
    char *psz = lpszSummary;

    *psz = '\0';
}

//////////////////////////////////////////////////////////////////////////////
// CONSOLINST_WriteGlobalCache
//
// This function is called by the installation framework when the user clicks
// Next at the summary screen.  Here you should write all information entered
// by the user into the installation cache for use during silent installation.
// Data written to this section of the file may be interpreted by the
// framework.  If this operation succeeds return TRUE, otherwise display an
// error message and return FALSE to indicate an error.
//

BOOL __declspec(dllexport)
CONSOLINST_WriteGlobalCache(LPCSTR lpszCacheFileName, LPCSTR lpszSectionName)
{
  // TODO: Add code to write data to the cache file (INI format) under the
  // specified section name.
 

  return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// CONSOLINST_WriteLocalCache
//
// This function is called by the installation framework when the user clicks
// Next at the summary screen.  Here you should write all information entered
// by the user into the installation cache for use during silent installation.
// Data written to this file is not interpreted by the framework, and may
// consist of any values that you will need to perform the installation (not
// just values entered by the user). If this operation succeeds return TRUE,
// otherwise display an error message and return FALSE to indicate an error.
//

BOOL __declspec(dllexport)
CONSOLINST_WriteLocalCache(LPCSTR lpszCacheFileName, LPCSTR lpszSectionName)
{
  // TODO: Add code to write data to the cache file (INI format) under the
  // specified section name.
  
  
  return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// CONSOLINST_ReadGlobalCache
//
// This function is called by the installation framework during silent install
// to initialize your data from the cache file you created above. Here you
// should read any information stored in the installation cache's global
// section that you need. If this operation succeeds return TRUE, otherwise
// display an error message and return FALSE to indicate an error.
//

BOOL __declspec(dllexport)
CONSOLINST_ReadGlobalCache(LPCSTR lpszCacheFileName, LPCSTR lpszSectionName)
{
 

  return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// CONSOLINST_ReadLocalCache
//
// This function is called by the installation framework during silent install
// to intialize your data from the local section of the cache created above.
// Here you should read any information stored in the installation cache's
// local section that you need.  If this operation succeeds return TRUE,
// otherwise display an error message and return FALSE to indicate an error.
//

BOOL __declspec(dllexport)
CONSOLINST_ReadLocalCache(LPCSTR lpszCacheFileName, LPCSTR lpszSectionName)
{
  // TODO: Add code to read data from the cache file (INI format) under the
  // specified section name.

  
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// CONSOLINST_Install
//
// The framework calls this function to perform installation.  Here you should
// define the file sets that are required to place your files on the
// destination disk.  You should not however perform the extraction, as the
// calling level will do that once the file sets for all products have been
// defined.  This ensures that the progress indicator shows the results for
// the entire range of user selections as a whole.  If the function
// successfully defines the file set return TRUE, otherwise return FALSE to
// indicate an error.
//

BOOL __declspec(dllexport)
CONSOLINST_Install(VOID)
{
   	HFILESET hfs;
    UINT uFlags;
    CHAR szSavedPath[MAX_PATH];
    CHAR szDirName[MAX_PATH];
    BOOL bResult = FALSE;

    hfs = FileSetCreate(CON_ID_DIR);

    if (hfs == INVALID_FILESET_HANDLE)
        return FALSE;

	uFlags = FS_UPDATE_VERSION | FS_SHAREDFILE;
	FileSetAddArchive(hfs, CON_JAR, "*.*", CON_MESSAGE,
					  uFlags);

    FileSetClose(hfs);

 return TRUE;
   
}

//////////////////////////////////////////////////////////////////////////////
// CONSOLINST_PostInstall
//
// The framework calls this function to perform post-installation
// configuration.  Here you should set values in any product configuration
// files, install services, add registry keys, start servers, and anything
// else that can only be done once the binaries are layed down on the disk.
// If the function succeeds return TRUE, otherwise return FALSE to indicate
// an error.
//

BOOL __declspec(dllexport)
CONSOLINST_PostInstall(VOID)
{
  // TODO: Add code to perform configuration.
    BOOL bRC = TRUE;

    return bRC;
}



//////////////////////////////////////////////////////////////////////////////
// PreUninst
//
// 
// Do things before uninstalling like turn off the server
// 
// 
// 
//

BOOL __declspec(dllexport)
CONSOLINST_PreUnInstall(LPCSTR pszServerRoot)
{
    BOOL bRC = TRUE;				 

    return bRC;
}

//////////////////////////////////////////////////////////////////////////////
// PostUninst
//
// 
// Clean up registry keys etc
// 
//
//
//
BOOL __declspec(dllexport)
CONSOLINST_PostUnInstall(LPCSTR pszServerRoot)
{

    BOOL bRC = TRUE;
	return bRC;
}


