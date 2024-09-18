#ifndef GPSBABEL_BABELEXPORT_H
#define GPSBABEL_BABELEXPORT_H

#include "main.h"

class BabelExport
{
public:
	static void WriteFile(const QString &inFormat, const QString &inFilePath, const QString &outFormat, const QString &outFilePath, char type = 'w')
	{
		babel_export_fun(inFormat, inFilePath, outFormat, outFilePath, type);
	}

	static void WriteMultipleFiles(const QString &inFormat, QList<QString> &inFilePaths, const QString &outFormat, const QString &outFilePath, char type = 'w')
	{
		babel_multiple_export_fun(inFormat, inFilePaths, outFormat, outFilePath, type);
	}

	static void GetRoutesData(const QString &inFormat, const QString &inFilePath, RouteList &routeList, char type = 'w')
	{
		babel_read_routes(inFormat, inFilePath, routeList, type);
	}
};


#endif //GPSBABEL_BABELEXPORT_H
