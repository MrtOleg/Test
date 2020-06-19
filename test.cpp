#include <stdio.h>
#include <conio.h>
#include <Magick++.h>


using namespace Magick;
using namespace std;


int main(int argc, char **argv) {
	try {
		InitializeMagick(*argv);
		Image image[20],img;
		setlocale(LC_CTYPE,"Russian");
		int ParE = 0, id = 0, idS=0,idB=-1,idR=-1,i = 0, j = 0, ParC = 0,Nsim1[20], Nsim2[20],ParEnd=0;
		int WRz, HRz;
		char In1[20][100], In2[20][100], Com[10] = { "" }, Par1[100], Par2[100], Str[100],sim=0,Name[100],NameF[100];
		while (ParEnd == 0)
		{
			printf(">>");
			sim = 0;
			i = 0;
			while (sim != '\n')
			{
				sim = getchar();
				Str[i++] = sim;
			}
			i = 0;
			j = 0;
			ParC = 0;
			ParE = 0;
			while (1)
			{
				if (((Str[i] != ' ') && (Str[i] != '\n')) && (ParC == 0))
				{
					Com[j++] = Str[i++];
				}
				else if (ParC == 0)
				{
					Com[j] = Str[i++];
					if (Com[0] == ' ')
					{
						continue;
					}
					if (Com[0] == '\n')
					{
						printf("Не правильный формат ввода\n");
						break;
					}
					j = 0;
					ParC = 7;
					if (((Com[0] == 'l') && (Com[1] == 'o') && (Com[2] == 'a') && (Com[3] == 'd') && (Com[4] == ' ')) || ((Com[0] == 'l') && (Com[1] == 'd') && (Com[2] == ' ')))
						ParC = 1;
					else if (((Com[0] == 's') && (Com[1] == 't') && (Com[2] == 'o') && (Com[3] == 'r') && (Com[4] == 'e') && (Com[5] == ' ')) || ((Com[0] == 's') && (Com[1] == ' ')))
						ParC = 2;
					else if (((Com[0] == 'b') && (Com[1] == 'l') && (Com[2] == 'u') && (Com[3] == 'r') && (Com[4] == ' ')))
						ParC = 3;
					else if (((Com[0] == 'r') && (Com[1] == 'e') && (Com[2] == 's') && (Com[3] == 'i') && (Com[4] == 'z') && (Com[5] == 'e') && (Com[6] == ' ')))
						ParC = 4;
					else if (((Com[0] == 'h') && (Com[1] == 'e') && (Com[2] == 'l') && (Com[3] == 'p') && (Com[4] == '\n')) || ((Com[0] == 'h') && (Com[1] == '\n')))
						ParC = 5;
					else if (((Com[0] == 'e') && (Com[1] == 'x') && (Com[2] == 'i') && (Com[3] == 't') && (Com[4] == '\n')) || ((Com[0] == 'q') && (Com[1] == '\n')) || ((Com[0] == 'q') && (Com[1] == 'u') && (Com[2] == 'i') && (Com[3] == 't') && (Com[4] == '\n')))
						ParC = 6;
				}
				else if (ParC == 1)
				{
					if (((Str[i] != ' ')&&(Str[i] != '\n')) && (ParE == 0))
					{
						In1[id][j++] = Str[i++];
					}
					else if (ParE == 0)
					{
						In1[id][j] = Str[i++];
						if (In1[id][0] == ' ')
						{
							continue;
						}
						if ((In1[id][0] == '\n')|| (In1[id][j] == '\n'))
						{
							printf("Не правильный формат ввода\n");
							break;
						}
						Nsim1[id] = j;
						ParE = 1;
						j = 0;
					}
					if (ParE == 1)
					{
						if ((Str[i] != '\n')&&(Str[i] != ' '))
							In2[id][j++] = Str[i++];
						else
						{
							if ((j==0)&&(Str[i] == ' '))
							{
								i++;
								continue;
							}
							if ((j == 0) && (Str[i] == '\n'))
							{
								printf("Не правильный формат ввода\n");
								break;
							}
							In2[id][j] = '\0';
							Nsim2[id] = j;
							ParC = 0;
							ParE = 0;
							i = 0;
							j = 0;
							image[id].read(In2[id]);
							id++;
							break;
						}
					}
				}
				else if (ParC == 2)
				{
					if (((Str[i] != ' ') && (Str[i] != '\n')) && (ParE == 0))
					{
						Name[j++] = Str[i++];
					}
					else if (ParE == 0)
					{
						Name[j] = Str[i++];
						if (Name[0] == ' ')
						{
							continue;
						}
						if ((Name[0] == '\n')||(Name[j] == '\n'))
						{
							printf("Не правильный формат ввода\n");
							break;
						}
						int ParY = 0;
						for (int k = 0; k < id; k++)
						{
							ParY = 0;
							for (int l = 0; l <= Nsim1[k]; l++)
							{
								if (Name[l] != In1[k][l])
									ParY = 1;
							}
							if (ParY == 0)
							{
								idS = k;
								break;
							}
						}
						if (ParY == 1)
						{
							printf("Изображение с таким именем не загруженно\n");
							break;
						}
						ParE = 1;
						j = 0;
					}
					if (ParE == 1)
					{
						if (Str[i] != '\n')
							NameF[j++] = Str[i++];
						else
						{
							if ((j == 0) && (Str[i] == ' '))
							{
								i++;
								continue;
							}
							if ((j == 0) && (Str[i] == '\n'))
							{
								printf("Не правильный формат ввода\n");
								break;
							}
							NameF[j] = '\0';
							ParC = 0;
							ParE = 0;
							i = 0;
							j = 0;
							image[idS].write(NameF);
							break;
						}
					}
				}
				else if (ParC == 3)
				{
					if (((Str[i] != ' ') && (Str[i] != '\n')) && (ParE == 0))
					{
						Name[j++] = Str[i++];
					}
					else if (ParE == 0)
					{
						Name[j] = Str[i++];
						if (Name[0] == ' ')
						{
							continue;
						}
						if ((Name[0] == '\n') || (Name[j] == '\n'))
						{
							printf("Не правильный формат ввода\n");
							break;
						}
						int ParY = 0;
						for (int k = 0; k < id; k++)
						{
							ParY = 0;
							for (int l = 0; l <= Nsim1[k]; l++)
							{
								if (Name[l] != In1[k][l])
									ParY = 1;
							}
							if (ParY == 0)
							{
								idS = k;
								break;
							}
						}
						if (ParY == 1)
						{
							printf("Изображение с таким именем не загруженно\n");
							break;
						}
						ParE = 1;
						j = 0;
					}
					if (ParE == 1)
					{
						if ((Str[i] != '\n') && (Str[i] != ' '))
							In1[id][j++] = Str[i++];
						else
						{
							if ((j == 0) && (Str[i] == ' '))
							{
								i++;
								continue;
							}
							if ((j == 0) && (Str[i] == '\n'))
							{
								printf("Не правильный формат ввода\n");
								break;
							}
							In1[id][j] = Str[i++];
							Nsim1[id] = j;
							ParE = 2;
							j = 0;
							image[id].read(In2[idS]);
						}
					}
					if (ParE == 2)
					{
						char SRad[5];
						double Rad;
						if ((Str[i] != '\n') && (Str[i] != ' '))
							SRad[j++] = Str[i++];
						else
						{
							if ((j == 0) && (Str[i] == ' '))
							{
								i++;
								continue;
							}
							if ((j == 0) && (Str[i] == '\n'))
							{
								printf("Не правильный формат ввода\n");
								break;
							}
							SRad[j] = '\0';
							sscanf_s(SRad, "%lf", &Rad);
							if (idB == -1)
							{
								idB = id;
								id++;
							}
							
							image[idB].blur(0,double(Rad));
							//image[id++].blur(20,5);
							break;
						}
					}
				}
				else if (ParC == 4)
				{
					if (((Str[i] != ' ') && (Str[i] != '\n')) && (ParE == 0))
					{
						Name[j++] = Str[i++];
					}
					else if (ParE == 0)
					{
						Name[j] = Str[i++];
						if (Name[0] == ' ')
						{
							continue;
						}
						if ((Name[0] == '\n') || (Name[j] == '\n'))
						{
							printf("Не правильный формат ввода\n");
							break;
						}
						int ParY = 0;
						for (int k = 0; k < id; k++)
						{
							ParY = 0;
							for (int l = 0; l <= Nsim1[k]; l++)
							{
								if (Name[l] != In1[k][l])
									ParY = 1;
							}
							if (ParY == 0)
							{
								idS = k;
								break;
							}
						}
						if (ParY == 1)
						{
							printf("Изображение с таким именем не загруженно\n");
							break;
						}
						ParE = 1;
						j = 0;
					}
					if (ParE == 1)
					{
						if ((Str[i] != '\n') && (Str[i] != ' '))
							In1[id][j++] = Str[i++];
						else
						{
							if ((j == 0) && (Str[i] == ' '))
							{
								i++;
								continue;
							}
							if ((j == 0) && (Str[i] == '\n'))
							{
								printf("Не правильный формат ввода\n");
								break;
							}
							In1[id][j] = Str[i++];
							Nsim1[id] = j;
							ParE = 2;
							j = 0;
							image[id].read(In2[idS]);
						}
					}
					if (ParE == 2)
					{
						char Sdan[5];
						if ((Str[i] != '\n') && (Str[i] != ' '))
							Sdan[j++] = Str[i++];
						else
						{
							if ((j == 0) && (Str[i] == ' '))
							{
								i++;
								continue;
							}
							if ((j == 0) && (Str[i] == '\n'))
							{
								printf("Не правильный формат ввода\n");
								break;
							}
							Sdan[j] = '\0';
							sscanf_s(Sdan, "%d", &WRz);
							ParE = 3;
							i++;
							j = 0;
						}
					}
					if (ParE == 3)
					{
						char Sdan[5];
						if ((Str[i] != '\n') && (Str[i] != ' '))
							Sdan[j++] = Str[i++];
						else
						{
							if ((j == 0) && (Str[i] == ' '))
							{
								i++;
								continue;
							}
							if ((j == 0) && (Str[i] == '\n'))
							{
								printf("Не правильный формат ввода\n");
								break;
							}
							Sdan[j] = '\0';
							sscanf_s(Sdan, "%d", &HRz);
							if (idR == -1)
							{
								idR = id;
								id++;
							}
							image[idR].resize(Geometry(WRz, HRz));
							break;
						}
					}
				}
				else if (ParC == 5)
				{
				    printf("\n load (ld) <name> <filename> - Загрузка изображения в формате JPG \n <name>-имя изображения, по имени оно доступно в других командах \n <filename> -имя файла для загрузки\n");
					printf("\n store (s) <name> <filename> - Сохранение изображения в формате jpg \n <name>-имя изображения \n <filename> -имя файла для сохранения\n");
					printf("\n blur <from_name> <to_name> <size> - Сглаживание изображение \n <from_name> - имя изображения \n <to_name> -имя изображения \n <size> - размер сглаживаемой области\n");
					printf("\n resize <from_name> <to_name> - Изменение размера изображения \n <from_name> -имя изображения \n <to_name> -имя изображения \n <new_width> <new_height> - новые размеры\n");
					printf("\n help (h) - Выводит справку о поддерживаемых командах\n");
					printf("\n exit (quit, q) - выход\n");
					break;
				}
				else if (ParC == 6)
				{
					ParEnd = 1;
					break;
				}
				else if(ParC == 7)
				{
					printf("Нет такой команды\n");
					break;
				}
			}
		}
			
	}
	catch (Magick::Exception & error) {
		printf("Caught Magick++ exception: %s", error.what());
	}
	return 0;
}
