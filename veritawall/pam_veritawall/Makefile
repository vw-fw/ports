PORTNAME=	pam_veritawall
PORTVERSION=	19.1.3
CATEGORIES=	sysutils

MAINTAINER=	nitish.patel@veritawall.com
COMMENT=	Veritawall shared authentication system using PAM

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	veritawall

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/lib/*.a

.include <bsd.port.mk>
