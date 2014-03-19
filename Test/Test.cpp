#include <stdio.h>
#include "..\Diagram.h"


static void ReadFileIntoDiagram(FILE* pFile,CDiagram& cDiagram);


int main()
{
    FILE* pFile = fopen("Test.txt","rt");
    CDiagram cDiagram(4,"Type ID","Shape ID","Color ID","Num of Items");
    ReadFileIntoDiagram(pFile,cDiagram);
    fclose(pFile);
    printf(cDiagram);
    return 0;
}


static void ReadFileIntoDiagram(FILE* pFile,CDiagram& cDiagram)
{
    char aBuf1[16];
    int iNumOfTypes;
    fscanf(pFile,"%s%d",aBuf1,&iNumOfTypes);
    for (int i=0; i<iNumOfTypes; i++)
    {
        char aBuf2[16],aBuf3[16];
        int iTypeID,iNumOfShapes;
        fscanf(pFile,"%s%d%s%d",aBuf2,&iTypeID,aBuf3,&iNumOfShapes);
        for (int j=0; j<iNumOfShapes; j++)
        {
            char aBuf4[16],aBuf5[16];
            int iShapeID,iNumOfColors;
            fscanf(pFile,"%s%d%s%d",aBuf4,&iShapeID,aBuf5,&iNumOfColors);
            for (int k=0; k<iNumOfColors; k++)
            {
                char aBuf6[16],aBuf7[16];
                int iColorID,iNumOfItems;
                fscanf(pFile,"%s%d%s%d",aBuf6,&iColorID,aBuf7,&iNumOfItems);
                if (j == 0 && k == 0)
                    cDiagram.AddRow(4,iTypeID,iShapeID,iColorID,iNumOfItems);
                else if (k == 0)
                    cDiagram.AddRow(3,iShapeID,iColorID,iNumOfItems);
                else
                    cDiagram.AddRow(2,iColorID,iNumOfItems);
            }
        }
    }
    cDiagram.Close();
}
