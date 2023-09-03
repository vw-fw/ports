PORTNAME=	pam_opnsense
PORTVERSION=	19.1.3
CATEGORIES=	sysutils

MAINTAINER=	franco@opnsense.org
COMMENT=	Veritawall shared authentication system using PAM

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	opnsense

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/lib/*.a

.include <bsd.port.mk>
