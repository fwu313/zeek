
#pragma once

#include <plugin/Plugin.h>

namespace plugin {
namespace Demo_Hooks {

class Plugin : public zeek::plugin::Plugin
{
protected:

	std::pair<bool, zeek::IntrusivePtr<Val>> HookFunctionCall(
		const Func* func, Frame* frame, zeek::Args* args) override;

	void MetaHookPre(zeek::plugin::HookType hook,
	                 const zeek::plugin::HookArgumentList& args) override;
	void MetaHookPost(zeek::plugin::HookType hook,
	                  const zeek::plugin::HookArgumentList& args,
	                  zeek::plugin::HookArgument result) override;

	// Overridden from plugin::Plugin.
	plugin::Configuration Configure() override;
};

extern Plugin plugin;

}
}
