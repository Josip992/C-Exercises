#include <stdio.h>
#include <stdlib.h>
#include "stl.h"


Objekt3D* stvori3dObjekt(FILE* fp)
{
	Objekt3D* noviObjekt = (Objekt3D*)malloc(sizeof(Objekt3D));
	if (!noviObjekt)
	{
		return NULL;
	}
	fseek(fp, 80, SEEK_SET);
	fread((&noviObjekt->broj_trokuta), sizeof(unsigned int), 1, fp); //zapisi u broj trokuta u novom objektu 2 bajta 1 put u fp
	noviObjekt->niz_trokutova = (Trokut*)malloc(sizeof(Trokut) * noviObjekt->broj_trokuta);

	if (!noviObjekt->niz_trokutova)
	{
		return NULL;
	}
	int i = 0;
	while (!feof(fp))
	{
		fread((&noviObjekt->niz_trokutova[i]), 50, 1, fp); // spremi vrijednosti koje dobijes u sljedecih 50 bytova u trokut koji se nalazi u objektu
		i++;
	}
	return noviObjekt;
}

void zapisi_binarno(Objekt3D* objekt3d, FILE* fp)
{
	int niz[20] = {0};
	
	fwrite(niz, sizeof(int), 20, fp); // sta pisemo,koje velicine, koliko puta i gdje
	fwrite(&objekt3d->broj_trokuta, sizeof(unsigned int), 1, fp);
	for (int i = 0; i < objekt3d->broj_trokuta; i++)
	{
		fwrite(&objekt3d->niz_trokutova[i], 50, 1, fp);
	}
}

void zapisi_tekstualno(Objekt3D* objekt3d, FILE* fp)
{

	fprintf(fp, "solid OpenSCAD_Model \n");
	for (int i = 0; i < objekt3d->broj_trokuta; i += 1)
	{
		fprintf(fp, "facet normal %f, %f, %f\n", objekt3d->niz_trokutova[i].nj, objekt3d->niz_trokutova[i].ni, objekt3d->niz_trokutova[i].nk);
		fprintf(fp, "outer loop\n");

		for (int j = 0; j < 3; j += 1)
		{
			fprintf(fp, "vertex %f, %f, %f\n", objekt3d->niz_trokutova[i].vrhovi[j].x, objekt3d->niz_trokutova[i].vrhovi[j].y, objekt3d->niz_trokutova[i].vrhovi[j].z);

		}

		fprintf(fp, "endloop\n");
		fprintf(fp, "endfacet\n");
	}
	fprintf(fp, "endsolid OpenSCAD_Model\n");

}

void brisi_objekt3d(Objekt3D* objekt3d)
{

	free(objekt3d->niz_trokutova);
	free(objekt3d);
}



