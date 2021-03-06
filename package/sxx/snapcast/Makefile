#
# Copyright (C) 2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/target.mk

PKG_NAME:=snapcast
PKG_VERSION:=1_0_0
PKG_RELEASE:=$(PKG_SOURCE_VERSION)
PKG_USE_MIPS16:=0

include $(INCLUDE_DIR)/package.mk

define Package/snapcast/Default
  SECTION:=sxx
  CATEGORY:=Sxx
	TITLE:=snapcast
	DEPENDS:=+boost +boost-system +boost-program_options +libavahi-client 
endef

define Package/snapcast/description/Default
  A collection of multiroom functions
endef

define Package/snapcast
  $(call Package/snapcast/Default)
  TITLE+= packages
endef

define Package/snapcast/description
	$(call Package/snapcast/description/Default)
	This Package provide for multiroom function
	Include Server and Client
endef

define Package/snapserver
	$(call Package/snapcast/Default)
	TITLE+= snapserver
	#DEPENDS+=
	HIDDEN:=1
endef

define Package/snapclient
	$(call Package/snapcast/Default)
	TILE+=snapclient
	DEPENDS+= +alsa-lib
	HIDDEN:=1
endef

define Package/snapserver/description
	$(call Package/snapcast/description/Default)
	Multiroom server program.
endef

define Package/snapclient/description
	$(call Package/snapcast/description/Default)
	Multiroom client program.
endef

define Package/snapcast/config
     menu "Select snapcast Options"
     	depends on PACKAGE_snapcast
     comment "Choose server or client to compile"
	    config PACKAGE_snapserver
	    	prompt "Compile snapserver"
	    	help
	    		Compile multiroom server.
	    	default n

	    config PACKAGE_snapclient
	    	prompt "Compile snapclient."
	    	help
	    		Compile multiroom client.
	    	default n
    endmenu
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) -r src/common/ $(PKG_BUILD_DIR)
	$(CP) -r src/message/ $(PKG_BUILD_DIR)
	$(if $(CONFIG_PACKAGE_snapserver), \
		$(CP) -r src/server/ $(PKG_BUILD_DIR),)
	$(if $(CONFIG_PACKAGE_snapclient), \
		$(CP) -r src/client/ $(PKG_BUILD_DIR),)
endef

define Build/Compile
	$(if $(CONFIG_PACKAGE_snapserver), \
		$(call Build/Compile/Default, -C server),)

	$(if $(CONFIG_PACKAGE_snapclient), \
		$(call Build/Compile/Default, -C client),)
endef

define Package/snapcast/Default/install
	true
endef
define Package/snapserver/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/server/snapserver $(1)/usr/bin/
endef

define Package/snapclient/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/client/snapclient $(1)/usr/bin/
endef

$(eval $(call BuildPackage,snapserver))
$(eval $(call BuildPackage,snapclient))
$(eval $(call BuildPackage,snapcast))
