PORTNAME=	kwayland
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 Client and Server library wrapper for the Wayland libraries

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		cmake compiler:c++11-lib gettext gl kde:5 pkgconfig qt:5 \
		tar:xz
USE_GL=		egl
USE_KDE=	ecm:build plasma-wayland-protocols:build
USE_QT=		concurrent core gui wayland \
		buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
