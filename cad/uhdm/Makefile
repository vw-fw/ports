PORTNAME=	uhdm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.72
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Hardware Data Model
WWW=		https://github.com/chipsalliance/UHDM

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}orderedmultidict>0:devel/py-orderedmultidict@${PY_FLAVOR}

USES=		cmake:testing compiler:c++17-lang python:build tcl:86,build
USE_LDCONFIG=	${PREFIX}/lib/uhdm

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	${PORTNAME:tu}
GH_TUPLE=	capnproto:capnproto:928c839:capnproto/third_party/capnproto \
		google:googletest:58d77fa:googletest/third_party/googletest

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	UHDM_BUILD_TESTS
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD} -DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	UHDM_BUILD_TESTS

BINARY_ALIAS=	tclsh=${TCLSH}

.include <bsd.port.mk>
