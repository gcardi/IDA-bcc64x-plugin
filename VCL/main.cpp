//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you.
//   If you are using the static version of the RTL, add #include<usebormm.h>
//   to one of the source files for your DLL

#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <kernwin.hpp>

#include <memory>

#include "FormMain.h"

//using std::make_unique;
using std::unique_ptr;

#pragma comment( lib, "ida" )

//--------------------------------------------------------------------------

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//--------------------------------------------------------------------------

struct plugin_ctx_t : public plugmod_t
{
	plugin_ctx_t() : frm_{ new TfrmMain( nullptr ) } {}
	virtual bool idaapi run(size_t) override;

    unique_ptr<TfrmMain> frm_ {};
};
//--------------------------------------------------------------------------

bool idaapi plugin_ctx_t::run(size_t)
{
	msg("Hello VCL, world! (C++)\n");

	frm_->ShowModal();

	return true;
}
//--------------------------------------------------------------------------

static plugmod_t *idaapi init()
{
  return new plugin_ctx_t;
}
//--------------------------------------------------------------------------


plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  PLUGIN_UNL            // Unload the plugin immediately after calling 'run'
  | PLUGIN_MULTI,       // The plugin can work with multiple idbs in parallel
  init,                 // initialize
  nullptr,
  nullptr,
  nullptr,              // long comment about the plugin
  nullptr,              // multiline help about the plugin
  "Hello, VCL world",       // the preferred short name of the plugin
  nullptr,              // the preferred hotkey to run the plugin
};
//--------------------------------------------------------------------------

