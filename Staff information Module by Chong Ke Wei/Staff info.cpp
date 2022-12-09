#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
# pragma warning(disable:4996)

struct Date
{
	int day;
	char month[10];
	int year;
}birth;

struct Staffinfo
{
	char idCode;
	int idNum;
	char staffId[6], staffName[31], password[21], gender;
	struct Date birth;
	char email[31], phoneNum[13], position[21];
}staff;

void line();
void error();
void staffModule(char staffId[6]);
void addStaff();
void searchStaff();
void modifyStaff(char staffId[6]);
void staffInfo();
void displayStaff();
void hidepw(char password[21]);
void main()
{
	//open file 
	FILE*rstaffInfo = fopen("StaffInfo.bin", "rb");
	FILE*wstaffInfo = fopen("StaffInfo.bin", "ab");
	//check if the file was exist or not
	if (rstaffInfo == NULL)
	{
		printf("%45s The StaffInfo.bin file cannot open!!!", "");
		system("pause");
		exit(-1);
	}

	line();
	printf("\t\t   _____ _         __  __   _                 _          _____           _                 \n"
		"\t\t  / ____| |       / _|/ _| | |               (_)        / ____|         | |                \n"
		"\t\t | (___ | |_ __ _| |_| |_  | |     ___   __ _ _ _ __   | (___  _   _ ___| |_ ___ _ __ ___  \n"
		"\t\t  \\___ \\| __/ _` |  _|  _| | |    / _ \\ / _` | | '_ \\   \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n"
		"\t\t  ____) | || (_| | | | |   | |___| (_) | (_| | | | | |  ____) | |_| \\__ \\ ||  __/ | | | | |\n"
		"\t\t |_____/ \\__\\__,_|_| |_|   |______\\___/ \\__, |_|_| |_| |_____/ \\__, |___/\\__\\___|_| |_| |_|\n"
		"\t\t                                         __/ |                  __/ |                      \n"
		"\t\t                                        |___/                  |___/                       \n\n");
	line();

	staff.idCode = 'S';
	staff.idNum = 1;
	strcpy(staff.staffId, "S0001");
	strcpy(staff.password, "ckw012345");
	strcpy(staff.staffName, "Chong Ke Wei");
	staff.gender = 'F';
	staff.birth = { 4,"MARCH",2001 };
	strcpy(staff.email, "kewei2001@hotmail.com");
	strcpy(staff.phoneNum, "011-16920255");
	strcpy(staff.position, "Administator\n");
	//fwrite(&staff, sizeof(staff), 1, wstaffInfo);

	char staffId[6], password[21];
	int i, total;

	do {
		i = 0;
		total = 0;
		printf("%45s Please login to your account:\n", "");
		printf("%45s ID>>>", "");
		scanf("%s", &staffId);
		while (fread(&staff, sizeof(staff), 1, rstaffInfo) != 0)
		{
			++total;
			while (strcmp(staff.staffId, staffId) != 0)
			{
				++i;
				break;
			}
			if (strcmp(staff.staffId, staffId) == 0)
				break;
		}
		if (i != total)
		{
			printf("%45s password>>>", "");
			hidepw(password);
			if (strcmp(staff.password, password) == 0)
			{
				printf("\n%45s Login successful!\n\n", "");
				printf("%45s", "");
				system("pause");
				system("cls");
				staffModule(staffId);
				break;

			}
			else
			{
				error();
				printf("%45s Password incorrect! Please login again.\n", "");
			}
			break;
		}

		else
		{
			printf("%45s The staff ID do not exist! Please reenter.\n", "");
		}
	} while (i == total);
		fclose(rstaffInfo);
		fclose(wstaffInfo);
		system("pause");
}

void line()
{
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void error()
{
	line();
	printf("\t\t\t\t\t     ___ ___ ___  ___  ___   _ \n"
		"\t\t\t\t\t    | __| _ \\ _ \\/ _ \\| _ \\ | |\n"
		"\t\t\t\t\t    | _||   /   / (_) |   / |_|\n"
		"\t\t\t\t\t    |___|_|_\\_|_\\\\___/|_|_\\ (_)\n\n");
	line();
}

void staffModule(char staffId[6])
{
	//declaration
	char validation;
	int task;

	printf("\t\t\t____    __    ____  _______  __        ______   ______   .___  ___.  _______ \n"
		"\t\t\t\\   \\  /  \\  /   / |   ____||  |      /      | /  __  \\  |   \\/   | |   ____|\n"
		"\t\t\t \\   \\/    \\/   /  |  |__   |  |     |  ,----'|  |  |  | |  \\  /  | |  |__   \n"
		"\t\t\t  \\            /   |   __|  |  |     |  |     |  |  |  | |  |\\/|  | |   __|  \n"
		"\t\t\t   \\    /\\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ \n"
		"\t\t\t    \\__/  \\__/     |_______||_______| \\______| \\______/  |__|  |__| |_______|\n\n");
	line();
	printf("%50s Hye,%s!=)\n\n", "", staff.staffName);
	printf("%35s    Enter the number to perform the following tasks.\n\n", "");
	printf("%45s *  *  *  *  *  *  *  *  *  *  *\n\n"
		"%45s *  1.Adding new staff.        *\n\n"
		"%45s *  2.Searching for a staff.   *\n\n"
		"%45s *  3.Modify your profile.     *\n\n"
		"%45s *  4.Display all staff info.  *\n\n"
		"%45s *  *  *  *  *  *  *  *  *  *  * \n\n", "", "", "", "", "", "");
	printf("%45s Please enter your choice:", "");
	scanf("%d%c", &task, &validation);
	while (isdigit(validation) == 0 && validation != '\n')
	{
		error();
		printf("\n%45s Please enter only digit!\n", "");
		line();
		printf("%45s Please enter your choice:", "");
		scanf("%d%c", &task, &validation);
	}
	switch (task)
	{
	case 1:
		system("cls");
		addStaff();
		break;
	case 2:
		system("cls");
		searchStaff();
		break;
	case 3:
		system("cls");
		modifyStaff(staffId);
		break;
	case 4:
		system("cls");
		displayStaff();
		break;
	default:
		while (task != 1 && task != 2 && task != 3 && task != 4)
		{
			error();
			printf("\n%30s    Invalid number!Please enter the number between (1-4).\n\n", "");
			line();
			printf("%45s Please enter your choice:", "");
			scanf("%d", &task);
		}
	}
}
void addStaff()
{
	//open file 
	FILE*wstaffInfo = fopen("StaffInfo.bin", "ab");
	FILE*rstaffInfo = fopen("StaffInfo.bin", "rb");
	//check if the file was exist or not
	if (wstaffInfo == NULL || rstaffInfo == NULL)
	{
		printf("%45s The StaffInfo.bin file cannot open!!!\n", "");
		system("pause");
		exit(-1);
	}
	line();
	printf("\t\t\t\t\t        _____  ________  ________   \n"
		"\t\t\t\t\t       /  _  \\ \\______ \\ \\______ \\  \n"
		"\t\t\t\t\t      /  /_\\  \\ |    |  \\ |    |  \\ \n"
		"\t\t\t\t\t     /    |    \\|    `   \\|    `   \\\n"
		"\t\t\t\t\t     \\____|__  /_______  /_______  /\n"
		"\t\t\t\t\t             \\/        \\/        \\/ \n\n"); 
	line();

	//declaration for information
	char password[21], confirmPW[21], gender, store[5], choice, validation;
	int month,last=0;

	do
	{
		while (fread(&staff, sizeof(staff), 1, rstaffInfo) != 0)
		{
			//find the last number of the staff id
			if (staff.idNum > last)
			{
				last = staff.idNum;
			}
			else
				continue;
		}
			if (last < 10)
			{
				staff.idNum = last + 1;
				staff.idCode = 'S';
				strcpy(staff.staffId, "S000");
				sprintf(store, "%d", last + 1);
				strcat(staff.staffId, store);
			}
			else if (last < 100)
			{
				staff.idNum = last + 1;
				staff.idCode = 'S';
				strcpy(staff.staffId, "S00");
				sprintf(store, "%d", last + 1);
				strcat(staff.staffId, store);
			}
			else if (last < 1000)
			{
				staff.idNum = last + 1;
				staff.idCode = 'S';
				strcpy(staff.staffId, "S0");
				sprintf(store, "%d", last + 1);
				strcat(staff.staffId, store);
			}
			else if (last < 10000)
			{
				staff.idNum = last + 1;
				staff.idCode = 'S';
				strcpy(staff.staffId, "S");
				sprintf(store, "%d", last + 1);
				strcat(staff.staffId, store);
			}
			printf("%45s Staff ID>>>%s\n", "", staff.staffId);
		printf("%45s Name>>>", "");
		scanf("%[^\n]", &staff.staffName);
		rewind(stdin);
		do
		{
			printf("%45s Password>>>", "");
			hidepw(password);
			rewind(stdin);
			printf("%45s Please confirm your password>>>", "");
			hidepw(confirmPW);
			rewind(stdin);
			if (strcmp(password, confirmPW) == 0)
			{
				strcpy(staff.password, password);
			}
			else
			{
				printf("%45s The password was not match! Please reenter your password.\n\n", "");
			}
		} while (strcmp(password, confirmPW) != 0);
		do
		{
			printf("%45s Gender(F=female,M=male)>>>", "");
			scanf("%c", &gender);
			rewind(stdin);
			if (toupper(gender) != 'F'&&toupper(gender) != 'M')
			{
				printf("%45s Invalid input,Please enter the correct alphabet!\n\n", "");
			}
			else
			{
				staff.gender = gender;
			}
		} while (toupper(gender) != 'F'&&toupper(gender) != 'M');
		printf("%45s Birth date:\n", "");
		printf("%45s Year>>>", "");
		scanf("%d", &staff.birth.year);
		rewind(stdin);
		while (staff.birth.year < 1 || staff.birth.year>2019)
		{
			printf("%45s Please enter a valid year!\n", "");
			printf("%45s Year>>>", "");
			scanf("%d", &staff.birth.year);
			rewind(stdin);
		}
		do
		{
		printf("%45s Month(1-12)>>>", "");
		scanf("%d", &month);
		rewind(stdin);
		switch (month)
		{
		case 1:
			strcpy(staff.birth.month, "January");
			break;
		case 2:
			strcpy(staff.birth.month, "February");
			break;
		case 3:
			strcpy(staff.birth.month, "March");
			break;
		case 4:
			strcpy(staff.birth.month, "April");
			break;
		case 5:
			strcpy(staff.birth.month, "May");
			break;
		case 6:
			strcpy(staff.birth.month, "June");
			break;
		case 7:
			strcpy(staff.birth.month, "July");
			break;
		case 8:
			strcpy(staff.birth.month, "August");
			break;
		case 9:
			strcpy(staff.birth.month, "September");
			break;
		case 10:
			strcpy(staff.birth.month, "October");
			break;
		case 11:
			strcpy(staff.birth.month, "November");
			break;
		case 12:
			strcpy(staff.birth.month, "December");
			break;
		default:
			printf("%45s Please enter the number between 1 to 12 only!\n", "");
			break;
		}
		}while (month < 1 || month>12);

		switch (month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			printf("%45s Day(1-31)>>>", "");
			scanf("%d", &staff.birth.day);
			rewind(stdin);
			while (staff.birth.day < 1 || staff.birth.day>31)
			{
				printf("%45s Please enter the correct day!(1-31)\n", "");
				printf("%45s Day(1-31)>>> ", "");
				scanf("%d", &staff.birth.day);
				rewind(stdin);
			}
			break;
		case 4: case 6: case 9: case 11:
			printf("%45s Day(1-30)>>>", "");
			scanf("%d", &staff.birth.day);
			rewind(stdin);
			while (staff.birth.day < 1 || staff.birth.day>30)
			{
				printf("%45s Please enter the correct day!(1-30)\n", "");
				printf("%45s Day(1-30)>>> ", "");
				scanf("%d", &staff.birth.day);
				rewind(stdin);
			}
			break;
		case 2:
			if (staff.birth.year % 2 == 0)
			{
				printf("%45s Day(1-29)>>>", "");
				scanf("%d", &staff.birth.day);
				rewind(stdin);
				while (staff.birth.day < 1 || staff.birth.day>29)
				{
					printf("%45s Please enter the correct day!(1-29)\n", "");
					printf("%45s Day(1-29)>>> ", "");
					scanf("%d", &staff.birth.day);
					rewind(stdin);
				}
			}
			else
			{
				printf("%45s Day(1-28)>>>", "");
				scanf("%d", &staff.birth.day);
				rewind(stdin);
				while (staff.birth.day < 1 || staff.birth.day>28)
				{
					printf("%45s Please enter the correct day!(1-28)\n", "");
					printf("%45s Day(1-28)>>> ", "");
					scanf("%d", &staff.birth.day);
					rewind(stdin);
				}
			}
		}
		printf("%45s E-mail>>>", "");
		scanf("%s", &staff.email);
		rewind(stdin);
		printf("%45s Phone number>>>", "");
		scanf("%s", &staff.phoneNum);
		rewind(stdin);
		printf("%45s Position>>>", "");
		scanf("%s", &staff.position);
		rewind(stdin);
		fwrite(&staff, sizeof(staff), 1, wstaffInfo);
		printf("Any staff information to add?(Y=yes,N=no)");
		scanf("%c%c", &choice, &validation);
		while (isdigit(validation) != 0 || validation != '\n')
		{
			error();
			printf("\n%45s Please enter character only!\n", "");
			line();
			printf("%45s Any staff information to add?(Y=yes,N=no)","");
			scanf("%c%c", &choice, &validation);
		}
		if (toupper(choice) == 'N')
		{
			printf("The new staff information added sucessfully!\n");
			system("pause");
			system("cls");
			fclose(wstaffInfo);
			fclose(rstaffInfo);
		}
	} while (toupper(choice) == 'Y');
}

void searchStaff()
{
	//open file 
	FILE*rstaffInfo = fopen("StaffInfo.bin", "rb");
	//check if the file was exist or not
	if (rstaffInfo == NULL)
	{
		printf("%45s The StaffInfo.bin file cannot open!!!\n", "");
		system("pause");
		exit(-1);
	}
	line();
	printf("\t\t\t        _______. _______     ___      .______        ______  __    __  \n"
		"\t\t\t       /       ||   ____|   /   \\     |   _  \\      /      ||  |  |  | \n"
		"\t\t\t      |   (----`|  |__     /  ^  \\    |  |_)  |    |  ,----'|  |__|  | \n"
		"\t\t\t       \\   \\    |   __|   /  /_\\  \\   |      /     |  |     |   __   | \n"
		"\t\t\t   .----)   |   |  |____ /  _____  \\  |  |\\  \\----.|  `----.|  |  |  | \n"
		"\t\t\t   |_______/    |_______/__/     \\__\\ | _| `._____| \\______||__|  |__| \n\n");
	line();

	char staffId[6],choice,validation;
	int i = 0, total = 0;
	do
	{
		printf("\n%45s Please enter the staff ID.>>>", "");
		scanf("%s", &staffId);
		rewind(stdin);
		while (fread(&staff, sizeof(staff), 1, rstaffInfo) != 0)
		{
			total++;
			while (strcmp(staff.staffId, staffId) != 0)
			{
				i++;
				break;
			}
		}
		if (i != total)
		{
			printf("\n%45s Staff ID     : %s \n", "", staff.staffId);
			printf("%45s Name         : %s \n", "", staff.staffName);
			printf("%45s Gender       : %c \n", "", staff.gender);
			printf("%45s Birth date   : %d %s %d \n", "", staff.birth.day, staff.birth.month, staff.birth.year);
			printf("%45s E-mail       : %s \n", "", staff.email);
			printf("%45s Phone number : %s \n", "", staff.phoneNum);
			printf("%45s Position     : %s \n", "", staff.position);
			//printf("%45s", "");
		}
		else
		{
			printf("%45s The staff ID you had entered is not exist!\n", "");
			printf("%45s Do you want to continue to search?(Y=yes,N=No)>>>", "");
			scanf("%c%c", &choice, &validation);
			while (isdigit(validation) != 0 || validation != '\n')
			{
				error();
				printf("\n%45s Please enter character only!\n", "");
				line();
				printf("%45s Do you want to continue to search?(Y=yes,N=No)>>>", "");
				scanf("%c%c", &choice, &validation);
			}
			if (choice == 'N')
			{
			}
			else
			{

			}
		}
		printf("%45s Any staff to search?(Y=yes,N=no)", "");
		scanf("%c%c",&choice,&validation);
		while (isdigit(validation) != 0 || validation != '\n')
		{
			error();
			printf("\n%45s Please enter character only!\n", "");
			line();
			printf("%45s Any staff to search?(Y=yes,N=no)", "");
			scanf("%c%c", &choice, &validation);
		}
		if (choice == 'N')
		{
			system("cls");
		}
	} while (choice == 'Y');
}

void modifyStaff(char staffId[6])
{
	//open file 
	FILE*wstaffInfo = fopen("StaffInfo.bin", "ab");
	FILE*rstaffInfo = fopen("StaffInfo.bin", "rb");
	//check if the file was exist or not
	if (wstaffInfo == NULL || rstaffInfo == NULL)
	{
		printf("%45s The StaffInfo.bin file cannot open!!!\n", "");
		system("pause");
		exit(-1);
	}
	line();
	printf("\t\t\t\t       ___ ___   ___   ___    ____  _____  __ __ \n"
		"\t\t\t\t      |   |   | /   \\ |   \\  |    ||     ||  |  |\n"
		"\t\t\t\t      | _   _ ||     ||    \\  |  | |   __||  |  |\n"
		"\t\t\t\t      |  \\_/  ||  O  ||  D  | |  | |  |_  |  ~  |\n"
		"\t\t\t\t      |   |   ||     ||     | |  | |   _] |___, |\n"
		"\t\t\t\t      |   |   ||     ||     | |  | |  |   |     |\n"
		"\t\t\t\t      |___|___| \\___/ |_____||____||__|   |____/ \n\n");
	line();

	char password[21], confirmPW[21], gender,validation, choice, confirm;
	int num, criteria[6], month, i = 0, total = 0;

	while (fread(&staff, sizeof(staff), 1, rstaffInfo) != 0)
	{
		total++;
		while (strcmp(staff.staffId, staffId) != 0)
		{
			i++;
			break;
		}
	}
	if (i != total)
	{
		printf("\n%45s Staff ID     : %s \n", "", staff.staffId);
		printf("%45s Password     : %s \n", "", staff.password);
		printf("%45s Name         : %s \n", "", staff.staffName);
		printf("%45s Gender       : %c \n", "", staff.gender);
		printf("%45s Birth date   : %d %s %d \n", "", staff.birth.day, staff.birth.month, staff.birth.year);
		printf("%45s E-mail       : %s \n", "", staff.email);
		printf("%45s Phone number : %s \n", "", staff.phoneNum);
		printf("%45s Position     : %s \n", "", staff.position);
		//printf("%45s", "");
	}
	else
	{

	}
	staffInfo();
	printf("%45s How many information you wanted to modify?(1-7)","");
	scanf("%d%c",&num,&validation);
	rewind(stdin);
	while (isdigit(validation) == 0 && validation != '\n')
	{
		error();
		printf("\n%45s Please enter only digit!\n", "");
		line();
		printf("%45s How many information you wanted to modify?(1-6)", "");
		scanf("%d%c", &num, &validation);
	}
	while (num < 0 || num>7)
	{
		printf("%45s Please enter the digit between 1 to 7 only.\n", "");
		printf("%45s How many information you wanted to modify?(1-7)", "");
		scanf("%d%c", &num, &validation);
	}
	printf("%45s Please select the digit of the criteria you wanted to modify:\n", "");
	for (i = 0; i < (num - 1); i++)
	{
		printf("%45s", "");
		scanf("%d%c", &criteria[i], &validation);
		rewind(stdin);
		while (isdigit(validation) == 0 && validation != '\n')
		{
			error();
			printf("\n%45s Please enter only digit!\n", "");
			line();
			printf("%45s Please select the digit of the criteria you wanted to modify>>> ", "");
			scanf("%d%c", &criteria[i], &validation);
			rewind(stdin);
		}
		while (criteria[i] < 0 || criteria[i]>7)
		{
			printf("%45s Please enter the digit between 1 to 7 only.\n", "");
			printf("%45s Please select the digit of the criteria you wanted to modify>>> ", "");
			scanf("%d%c", &criteria[i], &validation);
			rewind(stdin);
		}
	}
	printf("\n%45s Please enter the new information.\n", "");
	for (i = 0; i < (num - 1); i++)
	{
		switch (criteria[i])
		{
		case 1:
			printf("%45s Name>>>", "");
			scanf("%[^\n]", &staff.staffName);
			rewind(stdin);
			break;
		case 2:
			do
			{
				printf("%45s New password>>>", "");
				scanf("%s", &password);
				rewind(stdin);
				printf("%45s Please confirm your password>>>", "");
				scanf("%s", &confirmPW);
				rewind(stdin);
				if (strcmp(password, confirmPW) == 0)
				{
					strcpy(staff.password, password);
				}
				else
				{
					printf("%45s The password was not match! Please reenter your password.\n\n", "");
				}
			} while (strcmp(password, confirmPW) != 0);
			break;
		case 3:
			do
			{
				printf("%45s Gender(F=female,M=male)>>>", "");
				scanf("%c", &gender);
				rewind(stdin);
				if (toupper(gender) != 'F'&&toupper(gender) != 'M')
				{
					printf("%45s Invalid input,Please enter the correct alphabet!\n\n", "");
				}
				else
				{
					staff.gender = gender;
				}
			} while (toupper(gender) != 'F'&&toupper(gender) != 'M');
			break;
		case 4:
			printf("%45s Birth date:\n", "");
			printf("%45s Year>>>", "");
			scanf("%d", &staff.birth.year);
			rewind(stdin);
			while (staff.birth.year <1 || staff.birth.year>2019)
			{
				printf("%45s Please enter a valid year!\n", "");
				printf("%45s Year>>>", "");
				scanf("%d", &staff.birth.year);
				rewind(stdin);
			}
			do
			{
				printf("%45s Month(1-12)>>>", "");
				scanf("%d", &month);
				rewind(stdin);
				switch (month)
				{
				case 1:
					strcpy(staff.birth.month, "January");
					break;
				case 2:
					strcpy(staff.birth.month, "February");
					break;
				case 3:
					strcpy(staff.birth.month, "March");
					break;
				case 4:
					strcpy(staff.birth.month, "April");
					break;
				case 5:
					strcpy(staff.birth.month, "May");
					break;
				case 6:
					strcpy(staff.birth.month, "June");
					break;
				case 7:
					strcpy(staff.birth.month, "July");
					break;
				case 8:
					strcpy(staff.birth.month, "August");
					break;
				case 9:
					strcpy(staff.birth.month, "September");
					break;
				case 10:
					strcpy(staff.birth.month, "October");
					break;
				case 11:
					strcpy(staff.birth.month, "November");
					break;
				case 12:
					strcpy(staff.birth.month, "December");
					break;
				default:
					printf("%45s Please enter the number between 1 to 12 only!\n", "");
					printf("%45s Month(1-12)>>>", "");
					scanf("%d", &month);
					rewind(stdin);
					break;
				}
			} while (month < 1 || month>12);

			switch (month)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				printf("%45s Day(1-31)>>>", "");
				scanf("%d", &staff.birth.day);
				rewind(stdin);
				while (staff.birth.day < 0 || staff.birth.day>31)
				{
					printf("%45s Please enter the correct day!(1-31)\n", "");
					printf("%45s Day(1-31)>>> ", "");
					scanf("%d", &staff.birth.day);
					rewind(stdin);
				}
				break;
			case 4: case 6: case 9: case 11:
				printf("%45s Day(1-30)>>>", "");
				scanf("%d", &staff.birth.day);
				rewind(stdin);
				while (staff.birth.day < 1 || staff.birth.day>30)
				{
					printf("%45s Please enter the correct day!(1-30)\n", "");
					printf("%45s Day(1-30)>>> ", "");
					scanf("%d", &staff.birth.day);
					rewind(stdin);
				}
				break;
			case 2:
				if (staff.birth.year % 2 == 0)
				{
					printf("%45s Day(1-29)>>>", "");
					scanf("%d", &staff.birth.day);
					rewind(stdin);
					while (staff.birth.day < 1 || staff.birth.day>29)
					{
						printf("%45s Please enter the correct day!(1-29)\n", "");
						printf("%45s Day(1-29)>>> ", "");
						scanf("%d", &staff.birth.day);
						rewind(stdin);
					}
				}
				else
				{
					printf("%45s Day(1-28)>>>", "");
					scanf("%d", &staff.birth.day);
					rewind(stdin);
					while (staff.birth.day < 1 || staff.birth.day>28)
					{
						printf("%45s Please enter the correct day!(1-28)\n", "");
						printf("%45s Day(1-28)>>> ", "");
						scanf("%d", &staff.birth.day);
						rewind(stdin);
					}
				}
			}
		case 5:
			printf("%45s E-mail>>>", "");
			scanf("%s", &staff.email);
			rewind(stdin);
			break;
		case 6:
			printf("%45s Phone number>>>", "");
			scanf("%s", &staff.phoneNum);
			rewind(stdin);
			break;
		case 7:
			printf("%45s Position>>>", "");
			scanf("%s", &staff.position);
			rewind(stdin);
			break;
		}
		printf("\n%45s Modified information:\n", "");
		printf("\n%45s Staff ID     : %s \n", "", staff.staffId);
		printf("%45s Name         : %s \n", "", staff.staffName);
		printf("%45s Password     : %s \n", "", staff.password);
		printf("%45s Gender       : %c \n", "", staff.gender);
		printf("%45s Birth date   : %d %s %d \n", "", staff.birth.day, staff.birth.month, staff.birth.year);
		printf("%45s E-mail       : %s \n", "", staff.email);
		printf("%45s Phone number : %s \n", "", staff.phoneNum);
		printf("%45s Position     : %s \n\n", "", staff.position);
		printf("%45s Do the information correct?(Y=yes,N=no)>>>", "");
		scanf("%c%c", &confirm, &validation);
		while (isdigit(validation) != 0 || validation != '\n')
		{
			error();
			printf("\n%45s Please enter character only!\n", "");
			line();
			printf("%45s Do the information correct?(Y=yes,N=no)", "");
			scanf("%c%c", &confirm, &validation);
		}
		while (toupper(confirm) != 'Y'&&toupper(confirm) != 'N')
		{
			error();
			printf("%45s Please enter character Y or N only!(Y=yes,N=no)\n", "");
			printf("%45s Do the information correct?(Y=yes,N=no)", "");
			scanf("%c%c", &confirm, &validation);
		}
		if (toupper(confirm) == 'Y')
		{
			fwrite(&staff, sizeof(staff), 1, wstaffInfo);
		}
		else
		{

		}
	}
	
	printf("%45s ", "");
}

	/*switch (criteria[i])
	{
	case 1:
		printf("%45s Criteria to modify:\n Name\n", "");
		do {
			printf("%45s Any other criteria to modify?(Y=yes,N=no)>>>", "");
			scanf("%c%c", &choice, &validation);
			while (isdigit(validation) != 0 || validation != '\n')
			{
				error();
				printf("\n%45s Please enter character only!\n", "");
				line();
				printf("%45s Any other criteria to modify?(Y=yes,N=no)>>>", "");
				scanf("%c%c", &choice, &validation);
			}
			while (choice != 'Y'&&choice != 'N')
			{
				error();
				printf("%45s Please enter character Y or N only!(Y=yes,N=no)\n", "");
				printf("%45s Any other criteria to modify?(Y=yes,N=no)>>>", "");
				scanf("%c%c", &choice, &validation);
			}
			if (choice == 'N')
			{
				do
				{
					printf("%45s Please enter the new information.\n", "");
					printf("%45s Name>>>", "");
					scanf("%[^\n]", &staff.staffName);
					
					}
				} while (confirm == 'N');
			}
			if (choice == 'Y')
			{
				i++;

			}

	case 2:
		printf("%45s Criteria to modify:\n Gender\n", "");
	case 3:
		printf("%45s Criteria to modify:\n Birth date\n", "");
	case 4:
		printf("%45s Criteria to modify:\n E-mail\n", "");
	case 5:
		printf("%45s Criteria to modify:\n Phone number\n", "");
	case 6:
		printf("%45s Criteria to modify:\n Position\n", "");
	default:
		break;
		}*/

void staffInfo()
{
	printf("%45s 1.Name\n", "");
	printf("%45s 2.Password\n", "");
	printf("%45s 3.Gender\n", "");
	printf("%45s 4.Birth date\n", "");
	printf("%45s 5.E-mail\n", "");
	printf("%45s 6.Phone number\n", "");
	printf("%45s 7.Position\n", "");
}
void displayStaff()
{
	//open file 
	FILE*rstaffInfo = fopen("StaffInfo.bin", "rb");
	//check if the file was exist or not
	if (rstaffInfo == NULL)
	{
		printf("%45s The StaffInfo.bin file cannot open!!!", "");
		system("pause");
		exit(-1);
	}
	line();
	printf("\t\t\t\t\t  ______ _____ ___________ _       _____   __\n"
		"\t\t\t\t\t  |  _  \\_   _/  ___| ___ \\ |     / _ \\ \\ / /\n"
		"\t\t\t\t\t  | | | | | | \\ `--.| |_/ / |    / /_\\ \\ V / \n"
		"\t\t\t\t\t  | | | | | |  `--. \\  __/| |    |  _  |\\ /  \n"
		"\t\t\t\t\t  | |/ / _| |_/\\__/ / |   | |____| | | || |  \n"
		"\t\t\t\t\t  |___/  \\___/\\____/\\_|   \\_____/\\_| |_/\\_/  \n\n");
		line();

	while (fread(&staff, sizeof(staff), 1, rstaffInfo) != 0)
	{
		//改成Tabular format
		printf("\n%45s Staff ID     : %s \n", "", staff.staffId);
		printf("%45s Name         : %s \n", "", staff.staffName);
		printf("%45s Gender       : %c \n", "", staff.gender);
		printf("%45s Birth date   : %d %s %d \n", "", staff.birth.day, staff.birth.month, staff.birth.year);
		printf("%45s E-mail       : %s \n", "", staff.email);
		printf("%45s Phone number : %s \n", "", staff.phoneNum);
		printf("%45s Position     : %s \n\n", "", staff.position);
		//printf("%45s", "");
	}

}

void hidepw(char password[21]) {
	int y = 0,x;
	while (y <= 20)
	{
		password[y] = getch();
		x = password[y];
		//if user press enter(ASCII value=13),stop the looping
		if (x == 13)
		{
			password[y] = '\0';
			printf("\n");
			break;
		}
		//if user press backspace(ASCII value=8),delete the previous character inserted
		else if (x == 8)
		{
			if (y > 0)
			{
				y--;
				printf("\b \b");
			}
		}
		//blankspace(ASCII value=32)
		else if (x == 32)
		{
			continue;
		}
		else
		{
			printf("*");
			y++;
		}
	}
}