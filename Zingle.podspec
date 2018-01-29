Pod::Spec.new do |s|
  s.name                  = "Zingle"
  s.version               = "1.0.0"
  s.summary               = "Zingle Messaging SDK"
  s.description           = "Zingle is a multi-channel communications platform that allows the sending, receiving, and automating of conversations between a business and a customer.  The Zingle Messaging SDK provides Zingle customers (businesses) a chat interface for use in their own native iOS applications, allowing users to communicate via Zingle without requiring them to use SMS or another external channel." 
  s.homepage              = "https://github.com/Zingle/zingle-chat-ios"
  s.author                = { "Jason Neel" => "jneel@zingleme.com" }
  s.source 	              = { :git => "https://github.com/Zingle/zingle-chat-ios.git", :tag => s.version.to_s }
  s.license               = { :type => "Commercial", :text => "https://www.zingle.me/terms-of-use" }
  s.source_files          = "Zingle.framework/Headers/Zingle.h", "Zingle.framework/Headers/ZNGSettings.h", "Zingle.framework/Headers/ZNGUser.h", "Zingle.framework/Headers/ZNGConversation.h", "Zingle.framework/Headers/ZNGMessage.h", "Zingle.framework/Headers/ZNGMessageAction.h", "Zingle.framework/Headers/ZNGConversationActivity.h", "Zingle.framework/Headers/ZNGCoordinates.h"
  s.preserve_paths        = "Zingle.framework/*"
  s.module_map            = "Zingle.framework/Modules/module.modulemap"
  s.frameworks            = "Zingle", "CoreText", "SystemConfiguration", "CoreTelephony", "Foundation", "CoreGraphics", "UIKit", "QuartzCore", "AssetsLibrary", "Photos", "AVFoundation", "CFNetwork"
  s.library               = "icucore"
  s.vendored_frameworks   = "Zingle.framework"
  s.requires_arc          = true
  s.platform              = :ios
  s.ios.deployment_target = '8.0'
end
