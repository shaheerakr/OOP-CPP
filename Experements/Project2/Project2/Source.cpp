#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<string>
#include <conio.h>
#include <windows.h>
#include <time.h>
//#include "rlutil.h"
#include <dos.h>
//#include <dir.h>
using namespace std;

void addSong();
void delSong();
void listSong();
void searchSong();
void changePassword();
void Exit();
void gotoxy(int, int);
void menu();
void currentTime();
void delay(int);
void heading();
void textcolor(int);
void setColor();
void structure();
int password();
int checkExistence(char[]);
int fetch();
void songInfo(int);
int nameSearch(char[]);
void sortString();

struct music
{
	char name[500], artist[250], genre[100], length[50], year[50], album[250];

}song, songTemp;
struct musicTmp
{
	char name[100][500], artist[100][250], genre[100][100], length[100][50], year[100][50], album[100][250];

}songTmp;
long int size = sizeof(song);
FILE *fp;

int main()
{
	if (password())
	{
		fp = fopen("SONG.txt", "r+");
		if (fp == NULL)
		{
			fp = fopen("SONG.txt", "w+");
			if (fp == NULL)
			{
				printf("can not open file");
				exit(0);
			}
		}
		menu();
		fclose(fp);
		return 0;
	}
	else
		main();
}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
void setColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}

void currentTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	gotoxy(20, 22);
	setColor(3);
	printf("%s", asctime(timeinfo));
	setColor(0);

}

void delay(int number_of_seconds)
{
	int milli_seconds = 75 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}

int checkExistence(char nameCheck[500]) //return 1 on success
{
	int lim = fetch();
	int i = 0;
	while (i <= lim)
	{
		if (strcmpi(nameCheck, songTmp.name[i]) == 0) return 1;
		i++;
	}
	return 0;
}

int fetch()     //fetch all data in file and store it in a structure(musicTemp ke variable songTmp) of two dimensional array of characters
{
	int i = 0;
	rewind(fp);
	while (fread(&songTemp, sizeof(song) , 1, fp) == 1)
	{
		strcpy(songTmp.name[i], songTemp.name);
		strcpy(songTmp.album[i], songTemp.album);
		strcpy(songTmp.artist[i], songTemp.artist);
		strcpy(songTmp.genre[i], songTemp.genre);
		strcpy(songTmp.length[i], songTemp.length);
		strcpy(songTmp.year[i], songTemp.year);
		i++;
	}
	return i - 1;
}

void songInfo(int choice)       //after fetch you can use this to print data by giving the index
{
	system("cls");
	structure();
	gotoxy(15, 4);
	printf("%s", songTmp.name[choice]);
	gotoxy(10, 6);
	printf("album: %s", songTmp.album[choice]);
	gotoxy(10, 8);
	printf("artist: %s", songTmp.artist[choice]);
	gotoxy(10, 10);
	printf("genre: %s", songTmp.genre[choice]);
	gotoxy(10, 12);
	printf("length: %s", songTmp.length[choice]);
	gotoxy(10, 14);
	printf("year: %s", songTmp.year[choice]);
	gotoxy(10, 16);
	printf("press enter to continue");
	getch();

}

int nameSearch(char check[500])     //return index of array on which value is stored on success
{
	int lim = fetch();
	int i = 0;
	while (i <= lim)
	{
		if (strcmpi(check, songTmp.name[i]) == 0)
			return i;
		i++;
	}
	return 0;

}

void sortString()       //sai nai chal raha
{
	int lim = fetch();
	int i = 0, j = 0;
	static char swap[500];
	static char clear[500];
	for (i = 0; i <= lim; i++)
	{
		for (j = i + 1; j <= lim; j++)
		{
			if (strcmpi(songTmp.name[i], songTmp.name[j])>0)
			{
				strcpy(swap, clear);
				strcpy(swap, songTmp.name[i]);
				strcpy(songTmp.name[i], songTmp.name[j]);
				strcpy(songTmp.name[j], swap);
				strcpy(swap, clear);
				strcpy(swap, songTmp.album[i]);
				strcpy(songTmp.album[i], songTmp.album[j]);
				strcpy(songTmp.album[j], swap);
				strcpy(swap, clear);
				strcpy(swap, songTmp.artist[i]);
				strcpy(songTmp.artist[i], songTmp.artist[j]);
				strcpy(songTmp.artist[j], swap);
				strcpy(swap, clear);
				strcpy(swap, songTmp.genre[i]);
				strcpy(songTmp.genre[i], songTmp.genre[j]);
				strcpy(songTmp.genre[j], swap);
				strcpy(swap, clear);
				strcpy(swap, songTmp.length[i]);
				strcpy(songTmp.length[i], songTmp.length[j]);
				strcpy(songTmp.length[j], swap);
				strcpy(swap, clear);
				strcpy(swap, songTmp.year[i]);
				strcpy(songTmp.year[i], songTmp.year[j]);
				strcpy(songTmp.year[j], swap);
			}
		}
	}
	fflush(fp);
	rewind(fp);
	for (i = 0; i <= lim; i++)
	{
		strcpy(songTmp.name[i], songTemp.name);
		strcpy(songTmp.album[i], songTemp.album);
		strcpy(songTmp.artist[i], songTemp.artist);
		strcpy(songTmp.length[i], songTemp.length);
		strcpy(songTmp.year[i], songTemp.year);
		fwrite(&songTemp, sizeof(song), 1, fp);
		fseek(fp, sizeof(song), SEEK_END);
	}
}

void heading()
{
	gotoxy(15, 2);
	setColor(3);
	printf("Database Management System for Music Playlist");
	setColor(0);
}

void structure()
{
	int i;
	setColor(4);
	for (i = 0; i<24; i++)
	{
		gotoxy(0, i);
		printf("||");
	}
	for (i = 2; i<76; i++)
	{
		gotoxy(i, 0);
		printf("||");
	}
	for (i = 0; i<24; i++)
	{
		gotoxy(77, i);
		printf("||");
	}
	for (i = 2; i<76; i++)
	{
		gotoxy(i, 23);
		printf("||");
	}
	setColor(0);
	delay(1);
	heading();
	delay(1);
	currentTime();
}

int password()
{
	system("cls");
	structure();
	int i;
	FILE *ft;
	ft = fopen("pass.txt", "r+");
	if (ft == NULL)
	{
		ft = fopen("pass.txt", "w+");
		if (ft == NULL)
		{
			printf("can not open file");
			exit(1);
		}

	}
	static char pass[50], check[50];
	char display[50] = "**************Enter Password**************";
	gotoxy(16, 4);
	for (i = 0; i <= strlen(display); i++)
	{
		printf("%c", display[i]);
		delay(1);
	}
	i = 0;
	gotoxy(30, 6);
	while (1)
	{
		pass[i] = getch();
		if (pass[i] == '\r') break;
		else printf("*");
		i++;
	}
	rewind(ft);
	while (fread(&check, sizeof(check), 1, ft) == 1)
	{
		if (strncmp(pass, check, strlen(pass) - 1) == 0)
		{
			gotoxy(20, 8);
			printf("Access Granted!");
			gotoxy(20, 10);
			printf("Press enter to continue");
			getch();
			return 1;
		}
		else
		{
			gotoxy(20, 8);
			printf("Access denied!");
			gotoxy(20, 10);
			printf("Press enter to continue");
			getch();
			return 0;

		}
	}
	return 0;
}

void menu()
{
	int choice;
	while (1)
	{
		char really;
		system("cls");
		structure();
		gotoxy(10, 4);
		delay(1);
		setColor(3);
		printf("Enter the number corresponding the option you want to select");
		setColor(0);
		gotoxy(10, 6);
		delay(1);
		printf("1. Add Song");
		gotoxy(10, 8);
		delay(1);
		printf("2. Modify Song");
		gotoxy(10, 10);
		delay(1);
		printf("3. Delete Song");
		gotoxy(10, 12);
		delay(1);
		printf("4. List Song");
		gotoxy(10, 14);
		delay(1);
		printf("5. Search Song");
		gotoxy(10, 16);
		delay(1);
		printf("6. Change Password");
		gotoxy(10, 18);
		delay(1);
		printf("0. Exit");
		gotoxy(10, 20);
		delay(1);
		printf("Enter your choice: ");
		fflush(stdin);
		choice = getche();
		switch (choice)
		{
		case '1':
			gotoxy(10, 20);
			printf("Do you REALLY want to add song? (Y/N)");
			really = getche();
			if (really == 'y')
			{
				fseek(fp, 0, SEEK_END);
				addSong();
				//sortString();
			}
			else
				menu();
			break;
		case '2':
			delSong();
			fp = fopen("SONG.txt", "r+");
			if (fp == NULL)
			{
				fp = fopen("SONG.txt", "w+");
				if (fp == NULL)
				{
					printf("can not open file");
					exit(0);
				}
			}
			addSong();
			//sortString();
			break;
		case '3':
			delSong();
			fp = fopen("SONG.txt", "r+");
			if (fp == NULL)
			{
				fp = fopen("SONG.txt", "w+");
				if (fp == NULL)
				{
					printf("can not open file");
					exit(0);
				}
			}
			//sortString();
			break;
		case '4':
			listSong();
			break;
		case '5':
			searchSong();
			break;
		case '0':
			Exit();
			break;
		case '6':
			changePassword();
			break;
		default:
			printf("\n  Please Enter from the options in the menu");
			delay(20);
			menu();
		}
	}
}

void addSong()
{
	char another = 'y';
	while (another == 'y')
	{
		system("cls");
		structure();
		gotoxy(15, 4);
		delay(1);
		setColor(3);
		printf("Enter information regarding song");
		setColor(0);
		gotoxy(10, 6);
		delay(1);
		printf("Enter name: ");
		gets(song.name);
		gotoxy(10, 8);
		delay(1);
		printf("Enter artist name: ");
		gets(song.artist);
		gotoxy(10, 10);
		delay(1);
		printf("Enter album name: ");
		gets(song.album);
		gotoxy(10, 12);
		delay(1);
		printf("Enter genre of song: ");
		gets(song.genre);
		gotoxy(10, 14);
		delay(1);
		printf("Enter track length: ");
		gets(song.length);
		gotoxy(10, 16);
		delay(1);
		printf("Enter year of release: ");
		gets(song.year);
		char songName[500];
		strcpy(songName, song.name);
		if (checkExistence(songName))
		{
			gotoxy(10, 18);
			delay(1);
			printf("Your song already exist!");
		}
		else
		{
			fwrite(&song, sizeof(song), 1, fp);
			gotoxy(10, 18);
			delay(1);
			printf("Your song was successfully added!");
		}
		fflush(stdin);
		gotoxy(10, 20);
		delay(1);
		printf("do you want to add another song(y/n)?");
		another = getche();
	}
}

void listSong()
{
	system("cls");
	structure();
	int i = 0, choice = 0, lim;
	gotoxy(10, 4);
	delay(1);
	setColor(3);
	printf("Enter the number corresponding the option you want to select");
	setColor(0);
	delay(1);
	lim = fetch();
	while (i <= lim)
	{
		gotoxy(10, 6 + i);
		printf("%d. %s", i + 1, songTmp.name[i]);
		i++;
		delay(1);
	}
	gotoxy(10, i + 10);
	printf("Press 0 to exit");
	gotoxy(10, i + 7);
	printf("your choice: ");
	fflush(stdin);
	scanf("%d", &choice);
	if (choice == 0)
	{
		menu();
	}
	else
	{
		choice--;
		songInfo(choice);
	}
}

void delSong()
{
	system("cls");
	structure();
	int lim = fetch();
	int i = 0, choice;
	static char ch[10];
	static char tmp[500];
	FILE *ft;
	ft = fopen("TEMP.txt", "w");
	gotoxy(10, 4);
	delay(1);
	setColor(3);
	printf("Enter the number corresponding the option you want to select");
	setColor(0);
	delay(1);
	while (i <= lim)
	{
		gotoxy(10, i + 6);
		printf("%d. %s", i + 1, songTmp.name[i]);
		i++;
		delay(1);
	}
	gotoxy(10, i + 10);
	printf("Press 0 for menu");
	gotoxy(10, i + 8);
	printf("your choice: ");
	gets(ch);
	choice = atoi(ch);

	if (choice == 0)
		menu();


	strcpy(tmp, songTmp.name[choice - 1]);
	rewind(fp);
	while (fread(&song, sizeof(song), 1, fp) == 1)
	{
		if (strcmpi(tmp, song.name) != 0)
			fwrite(&song, sizeof(song), 1, ft);
	}
	fclose(fp);
	fclose(ft);
	remove("SONG.txt");
	rename("TEMP.txt", "SONG.txt");


}

void searchSong()
{
	system("cls");
	structure();
	char ch;
	int i, j = 0;
	int lim = fetch();
	static char tmp[500];
	gotoxy(10, 4);
	delay(1);
	setColor(3);
	printf("Enter the number corresponding the option you want to select");
	setColor(0);
	gotoxy(10, 6);
	printf("1. by Name");
	gotoxy(10, 8);
	printf("2. by Artist");
	gotoxy(10, 10);
	printf("3. by Album");
	gotoxy(10, 12);
	printf("4. by Track length");
	gotoxy(10, 14);
	printf("5. by Genre");
	gotoxy(10, 16);
	printf("6. by Year of release");
	gotoxy(10, 18);
	printf("your choice: ");
	ch = getche();
	system("cls");
	structure();
	gotoxy(10, 4);
	printf("Enter: ");
	gets(tmp);
	int choice;
	int flag = 1;
	int sel[100];
	switch (ch)
	{
	case '1':
		gotoxy(10, 6);
		choice = nameSearch(tmp);
		if (choice)
		{
			songInfo(choice);
		}
		else
		{
			printf("This song does not exist");
			gotoxy(10, 8);
			printf("Press enter to continue");
			getch();
		}
		break;

	case '2':
		gotoxy(10, 6);
		printf("Select the option corresponding the song name to open");
		for (i = 0; i <= lim; i++)
		{
			if (strcmpi(songTmp.artist[i], tmp) == 0)
			{
				gotoxy(10, 8 + j);
				printf("%d. %s", j + 1, songTmp.name[i]);
				sel[j] = i;
				j++;
				flag = 0;
			}
		}
		if (flag)
		{
			gotoxy(10, 8);
			printf("This Artist does not exist");
			gotoxy(10, 10);
			printf("Press enter to continue");
			getch();
		}
		else
		{
			gotoxy(10, 8 + j);
			printf("Your choice: ");
			scanf("%d", &choice);
			songInfo(sel[choice - 1]);
		}
		break;

	case '3':
		gotoxy(10, 6);
		printf("Select the option corresponding the song name to open");
		for (i = 0; i <= lim; i++)
		{
			if (strcmpi(songTmp.album[i], tmp) == 0)
			{
				gotoxy(10, 8 + j);
				printf("%d. %s", j + 1, songTmp.name[i]);
				sel[j] = i;
				j++;
				flag = 0;
			}
		}
		if (flag)
		{
			gotoxy(10, 8);
			printf("This Album does not exist");
			gotoxy(10, 10);
			printf("Press enter to continue");
			getch();
		}
		else
		{
			gotoxy(10, 8 + j);
			printf("Your choice: ");
			scanf("%d", &choice);
			songInfo(sel[choice - 1]);
		}
		break;

	case '4':
		gotoxy(10, 6);
		printf("Select the option corresponding the song name to open");
		for (i = 0; i <= lim; i++)
		{
			if (strcmpi(songTmp.genre[i], tmp) == 0)
			{
				gotoxy(10, 8 + j);
				printf("%d. %s", j + 1, songTmp.name[i]);
				sel[j] = i;
				j++;
				flag = 0;
			}
		}
		if (flag)
		{
			gotoxy(10, 8);
			printf("This Track length does not exist");
			gotoxy(10, 10);
			printf("Press enter to continue");
			getch();
		}
		else
		{
			gotoxy(10, 8 + j);
			printf("Your choice: ");
			scanf("%d", &choice);
			songInfo(sel[choice - 1]);
		}
		break;

	case '5':
		gotoxy(10, 6);
		printf("Select the option corresponding the song name to open");
		for (i = 0; i <= lim; i++)
		{
			if (strcmpi(songTmp.length[i], tmp) == 0)
			{
				gotoxy(10, 8 + j);
				printf("%d. %s", j + 1, songTmp.name[i]);
				sel[j] = i;
				j++;
				flag = 0;
			}
		}
		if (flag)
		{
			gotoxy(10, 8);
			printf("This Genre does not exist");
			gotoxy(10, 10);
			printf("Press enter to continue");
			getch();
		}
		else
		{
			gotoxy(10, 8 + j);
			printf("Your choice: ");
			scanf("%d", &choice);
			songInfo(sel[choice - 1]);
		}
		break;

	case '6':
		gotoxy(10, 6);
		printf("Select the option corresponding the song name to open");
		for (i = 0; i <= lim; i++)
		{
			if (strcmpi(songTmp.year[i], tmp) == 0)
			{
				gotoxy(10, 8 + j);
				printf("%d. %s", j + 1, songTmp.name[i]);
				sel[j] = i;
				j++;
				flag = 0;
			}
		}
		if (flag)
		{
			gotoxy(10, 8);
			printf("This Year of release does not exist");
			gotoxy(10, 10);
			printf("Press enter to continue");
			getch();
		}
		else
		{
			gotoxy(10, 8 + j);
			printf("Your choice: ");
			scanf("%d", &choice);
			songInfo(sel[choice - 1]);
		}
		break;
	}
}

void changePassword()
{
	FILE *ft;
	static char passwordOld[50], passwordNew[50], passwordTmp[50];
	system("cls");
	structure();
	ft = fopen("Pass.txt", "r+");
	if (ft == NULL)
	{
		ft = fopen("pass.txt", "w+");
		if (ft == NULL)
			printf("can not open file");
	}
	gotoxy(10, 4);
	printf("Enter old password:");
	fflush(stdin);
	gets(passwordOld);
	rewind(ft);
	while (fread(&passwordTmp, sizeof(passwordTmp), 1, ft) == 1)
	{
		if (strcmp(passwordOld, passwordTmp) == 0)
		{
			gotoxy(10, 6);
			printf("Enter new password: ");
			fflush(stdin);
			gets(passwordNew);
			rewind(ft);
			fwrite(&passwordNew, sizeof(passwordNew), 1, ft);
			gotoxy(10, 8);
			printf("Password successfully changed!");
			gotoxy(10, 10);
			printf("press enter to continue");
			getch();
			fflush(stdin);
		}
		else
		{
			gotoxy(10, 6);
			printf("Wrong Password!");
			getch();
			break;

		}
	}
}

void Exit()
{
	system("cls");
	printf("Good Bye!");
	exit(0);
}
