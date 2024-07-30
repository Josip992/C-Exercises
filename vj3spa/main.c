#include <stdio.h>
#include <stdlib.h>
#include "stl.h"

int main()
{

	FILE* fp = fopen("primjerbin.stl", "rb");
	if (!fp)
	{
		return 1;
	}
	Objekt3D* objekt3d = stvori3dObjekt(fp);
	fclose(fp);


	fp = fopen("mojprimjerbin.stl", "wb+");
	if (!fp)
	{
		return 2;
	}
	zapisi_binarno(objekt3d, fp);
	fclose(fp);

    fp = fopen("mojprimjertxt.stl", "w+");
	if (!fp)
	{
		return 3;
	}
	zapisi_tekstualno(objekt3d, fp);
	fclose(fp);

	brisi_objekt3d(objekt3d);

	return 0;

}

