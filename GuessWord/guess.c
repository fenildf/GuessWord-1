#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define EPS  1E-6                                                               //�궨��һ������С����������double�������ж�
#define ERROR_TIMES 15                                                          //ÿһ�غϴ��������ϵͳ����
#define PATH1 "E:\\C\\GuessWord\\material\\words.txt"                           //����·���궨�壬����Դ��ֲ��ͬ���Բ�ͬ�ļ���ʱ
#define PATH2 "E:\\C\\GuessWord\\material\\players.txt"                         // ���޸�·����ȷ��������������



char* randomExtract();             //--------------------------------------------------�����ȡ���ʺ���
void showWelcome();                //--------------------------------------------------��ӭ���溯������
void showMain();                   //--------------------------------------------------��ʾ���˵���������
void setNumber();                  //--------------------------------------------------���ú�������
void showSet();                    //--------------------------------------------------��ʾ���ò˵���������
void showSetSuccess();             //--------------------------------------------------��ʾ�޸ĳɹ���ʾ��Ϣ��������
void setName(char* name);         //--------------------------------------------------�޸������������
void showCheck();                  //--------------------------------------------------�鿴��Ϣ��������
void showRank();                   //--------------------------------------------------�鿴������������
void showAbout();                  //--------------------------------------------------�鿴��Ϸ��Ȩ��������
void quit();                       //--------------------------------------------------�˳����溯������
void sleep(clock_t wait);        //--------------------------------------------------��ʱ��������
void start();                      //--------------------------------------------------������һ����Ϸ�����е����жϺ���,aΪ���ƴ���
void showFailure();               //--------------------------------------------------ʧ�ܽ��溯������
void showSuccess(int correctTimes, int runTimes, double  duration);              //-----�ɹ����溯������,��ʾ��ҳɼ�
double score(int correctTimes, int runTimes);    //-------------------------------------����÷ֺ�������
void showTips();                   //--------------------------------------------------��ʾ��Ϣ��������
void scoreInput(char *name, double scores, double duration);  //-------------------------¼�������Ϣ��������
int compareScore();               //---------------------------------------------------�Ƚ���ҳɼ�����
void showEnter();                 //---------------------------------------------------��ʾ���ڽ�����Ϸ���溯������
void showTemporarySuccess(int Number);  //-------------------------------------------------��ʾĳһ�غϳɹ�
void showTemporaryFailure(int Number);  //-------------------------------------------------��ʾĳһ�غ�ʧ��


struct player                       //������һ����ҽṹ�壬���ڴ��������Ϣ
{
	char name[10];
	double score;
	double time;
};
typedef struct player player;


char name[] = "Player";
char word[10];
int  NUMBER = 2;                          //��Ϸ��Ļغ�������ҿ��趨
player allPlayer[20];                   //����һ����ҽṹ�����飬����������ҵ���Ϣ
player playerTemp;                      //����һ����ʱ��ҽṹ����������ڴ��������ҵ���Ϣ
char tempWord[100][20];               //����һ���ַ���ά���飬���ڴ���������µĵ��ʣ����������Ļ
int Number;



//������

int main() {
	showWelcome();
	return 0;
}


//��ʾ��ӭ����
void showWelcome() {

	system("CLS");                                                      //����

	printf("\n\n\n\n");
	printf("��������������*******************************************************\n");
	printf("��������������*******************************************************\n");
	printf("��������������*******************************************************\n");
	printf("��������������******************                   ******************\n");
	printf("��������������***************    ��ӭ����������Ϸ��  ****************\n");
	printf("��������������******************                   ******************\n");
	printf("��������������*******************************************************\n");
	printf("��������������*******************************************************\n");
	printf("��������������*******************************************************\n");
	printf("�������������� ");

	sleep((clock_t)2 * CLOCKS_PER_SEC);
	showMain();

}

//��ʾ���˵�����                    
void showMain() {
	char button;                                                          //�����û����������

	system("CLS");                                                           //����

	printf("\n\n\n\n");
	printf("��������������***********************������Ϸ************************\n");
	printf("��������������*                                                     *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*  1����      ʼ                                      *\n");
	printf("��������������*  2����      ��                                      *\n");
	printf("��������������*  3����      ��                                      *\n");
	printf("��������������*  4����      ��                                      *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("�������������� ");

	do {
		button = getchar();                                              //�û������������
		fflush(stdin);
		if (button != '1'&&button != '2'&&button != '3'&&button != '4') {
			printf("�������������� ����������������룡����\n�������������� ");
		}
	} while (button != '1'&&button != '2'&&button != '3'&&button != '4');


	if (button == '1') {                                                           //���ݲ���������Ӧ����
		start();
	}

	if (button == '2') {
		showSet();
	}
	if (button == '3') {
		showCheck();
	}

	if (button == '4') {
		quit();
	}

}


//��ʾ���ò˵�
void showSet() {
	char button;                                                               //�����û����������

	system("CLS");                                                                 //����

	printf("\n\n\n\n");
	printf("��������������*************************����**************************\n");
	printf("��������������*                                                     *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*  1���޸Ĳµ��ʵ���Ŀ                                *\n");
	printf("��������������*  2���޸�����                                        *\n");
	printf("��������������*  3������                                            *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("�������������� ");

	do {
		button = getchar();                                              //�û������������
		fflush(stdin);
		if (button == ' ') {
			showMain();
		}
		if (button <= '0' || button >= '4') {
			printf("�������������� ����������������룡����\n�������������� ");
		}
	} while (button != '1'&&button != '2'&&button != '3');


	if (button == '1') {                                                           //���ݲ���������Ӧ����
		setNumber();
	}

	if (button == '2') {
		setName(name);
	}
	if (button == '3') {
		showMain();
	}


}

//�޸Ĳ�Ĭ�ϲµ�����
void setNumber() {

	system("CLS");                                                                  //����

	printf("\n\n\n\n");
	printf("��������������******************�޸�Ĭ�����µ�����*******************\n");
	printf("��������������*                                                     *\n");
	printf("��������������*���޸�Ĭ�����µ��ʸ���                               *\n");
	printf("�������������� number=");
	scanf("%d", &NUMBER);
	showSetSuccess();
}

//��ʾ�޸ĳɹ�
void showSetSuccess() {
	char button;                                                                        //�����û����������

	system("CLS");

	printf("\n\n\n\n");
	printf("��������������*************************��ʾ**************************\n");
	printf("         ���� *                                                     *\n");
	printf("         ���� *                      �޸ĳɹ���                     *\n");
	printf("         ���� *                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("��������������*  1���������˵�                         2����ʼ��Ϸ  *\n");
	printf("�������������� ");



	do {
		fflush(stdin);
		button = getchar();                                                     //�û������������
		fflush(stdin);
		if (button <= '0' || button >= '3') {
			printf("�������������� ����������������룡����\n�������������� ");
		}
	} while (button != '1'&&button != '2');


	if (button == '1') {                                                           //���ݲ���������Ӧ����
		showMain();
	}
	if (button == '2') {
		start();
	}
}

//�޸��������

void setName(char* name) {
	char newName[20];

	system("CLS");                                                                 //����

	printf("\n\n\n\n");
	printf("��������������***********************�޸�����************************\n");
	printf("         ���� *                                                     *\n");
	printf("         ���� *   ����������                                        *\n");
	printf("��������������     newName:");

	scanf("%s", newName);                                                            //�û�����������       

	strcpy(name, newName);                                                           //����������

	showSetSuccess();                                                                  //��ʾ�޸ĳɹ�
}

//�鿴��Ϣ
void showCheck() {
	char button;                                                                 //�����û����������

	system("CLS");                                                                    //����  

	printf("\n\n\n\n");
	printf("��������������*************************�鿴**************************\n");
	printf("         ���� *                                                     *\n");
	printf("��������������*  1������                                            *\n");
	printf("��������������*  2������                                            *\n");
	printf("��������������*  3������                                            *\n");
	printf("         ���� *                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("�������������� ");

	do {
		button = getchar();                                                  //�û������������
		fflush(stdin);
		if (button != '1'&&button != '2'&&button != '3') {
			printf("�������������� ����������������룡����\n�������������� ");
		}
	} while (button != '1'&&button != '2'&&button != '3');

	if (button == '1') {                                                             //���ݲ���������Ӧ����                                                        
		showRank();
	}

	if (button == '2') {
		showAbout();
	}

	if (button == '3') {
		showMain();
	}
}

//�鿴����

void showRank() {

	int i = 0,                                                              //����һ��ѭ������
		playerNumber;                                                   //���ڴ����������   

	playerNumber = compareScore();

	system("CLS");                                                                    //����

	printf("\n\n\n\n");
	printf("��������������*************************����**************************\n");
	printf("         ���� *                                                     *\n");
	printf("         ���� *        ����            ��ʱ            �÷�         *\n");
	printf("         ���� *                                                     *\n");

	if (playerNumber>5) {

		printf("         ���� * NO.1: %-10s       %-6.2lf��         %6.2lf��     *\n", allPlayer[i].name, allPlayer[i].time, allPlayer[i].score, i++);
		printf("         ���� * NO.2: %-10s       %-6.2lf��         %6.2lf��     *\n", allPlayer[i].name, allPlayer[i].time, allPlayer[i].score, i++);
		printf("         ���� * NO.3: %-10s       %-6.2lf��         %6.2lf��     *\n", allPlayer[i].name, allPlayer[i].time, allPlayer[i].score, i++);
		printf("         ���� * NO.4: %-10s       %-6.2lf��         %6.2lf��     *\n", allPlayer[i].name, allPlayer[i].time, allPlayer[i].score, i++);
		printf("         ���� * NO.5: %-10s       %-6.2lf��         %6.2lf��     *\n", allPlayer[i].name, allPlayer[i].time, allPlayer[i].score);
		printf("         ���� *                                                     *\n");
		printf("��������������*******************************************************\n");
		printf("�������������� ");
		sleep((clock_t)6 * CLOCKS_PER_SEC);
		showCheck();

	}
	else {
		switch (playerNumber) {
		case 0:
			printf("         ���� *                     û�м�¼��                      *\n");
			printf("         ���� *                                                     *\n");
			printf("��������������*******************************************************\n");
			printf("�������������� ");
			sleep((clock_t)6 * CLOCKS_PER_SEC);
			showCheck();
			break;
		case 1:
			printf("         ���� * NO.1: %-10s       %-6.2lf��         %-6.2lf��    *\n", allPlayer[0].name, allPlayer[0].time, allPlayer[0].score);
			printf("         ���� *                                                     *\n");
			printf("��������������*******************************************************\n");
			printf("�������������� ");
			sleep((clock_t)6 * CLOCKS_PER_SEC);
			showCheck();
			break;
		case 2:
			printf("         ���� * NO.1: %-10s       %-6.2lf��         %-6.2lf��    *\n", allPlayer[0].name, allPlayer[0].time, allPlayer[0].score);
			printf("         ���� * NO.2: %-10s       %-6.2lf��         %-6.2lf��    *\n", allPlayer[1].name, allPlayer[1].time, allPlayer[1].score);
			printf("         ���� *                                                     *\n");
			printf("��������������*******************************************************\n");
			printf("�������������� ");
			sleep((clock_t)6 * CLOCKS_PER_SEC);
			showCheck();
			break;
		case 3:
			printf("         ���� * NO.1: %-10s       %-6.2lf��         %-6.2lf��    *\n", allPlayer[0].name, allPlayer[0].time, allPlayer[0].score);
			printf("         ���� * NO.2: %-10s       %-6.2lf��         %-6.2lf��    *\n", allPlayer[1].name, allPlayer[1].time, allPlayer[1].score);
			printf("         ���� * NO.3: %-10s       %-6.2lf��         %-6.2lf��    *\n", allPlayer[2].name, allPlayer[2].time, allPlayer[2].score);
			printf("         ���� *                                                     *\n");
			printf("��������������*******************************************************\n");
			printf("�������������� ");
			sleep((clock_t)6 * CLOCKS_PER_SEC);
			showCheck();
			break;
		case 4:
			printf("         ���� * NO.1: %-10s       %-6.2lf��        %-6.2lf��     *\n", allPlayer[0].name, allPlayer[0].time, allPlayer[0].score);
			printf("         ���� * NO.2: %-10s       %-6.2lf��        %-6.2lf��     *\n", allPlayer[1].name, allPlayer[1].time, allPlayer[1].score);
			printf("         ���� * NO.3: %-10s       %-6.2lf��        %-6.2lf��     *\n", allPlayer[2].name, allPlayer[2].time, allPlayer[2].score);
			printf("         ���� * NO.4: %-10s       %-6.2lf��        %-6.2lf��     *\n", allPlayer[3].name, allPlayer[3].time, allPlayer[3].score);
			printf("         ���� *                                                     *\n");
			printf("��������������*******************************************************\n");
			printf("�������������� ");
			sleep((clock_t)6 * CLOCKS_PER_SEC);
			showCheck();
			break;
		}
	}


}

//�鿴��Ȩ��Ϣ

void showAbout() {

	system("CLS");                                                                    //���� 

	printf("\n\n\n\n");
	printf("��������������*************************����**************************\n");
	printf("         ���� *                                                     *\n");
	printf("         ���� *        �汾��1.0.0                                  *\n");
	printf("         ���� *                                                     *\n");
	printf("         ���� *        �������Ž�ɭ  ����                           *\n");
	printf("         ���� *        �ر�����������Ϸ�������֣����������ã�       *\n");
	printf("         ���� *                  ���ܽ���Ȩ����������               *\n");
	printf("         ���� *                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("�������������� ");

	sleep((clock_t)6 * CLOCKS_PER_SEC);
	showCheck();


}


//�˳�ѯ��

void quit() {
	char button;                                                           //�����û����������

	system("CLS");                                                        //���� 

	printf("\n\n\n\n");
	printf("��������������*******************************************************\n");
	printf("��������������*******************************************************\n");
	printf("��������������*******************************************************\n");
	printf("��������������******************                   ******************\n");
	printf("��������������***************      ���Ҫ�˳���    ****************\n");
	printf("��������������******************                   ******************\n");
	printf("��������������*******************************************************\n");
	printf("��������������*******************************************************\n");
	printf("��������������*******************************************************\n");
	printf("��������������*  1����                                       2����  *\n");
	printf("�������������� ");


	do {
		button = getchar();                                               //�û������������
		fflush(stdin);
		if (button != '1') {
			printf("�������������� ����������������룡����\n�������������� ");
		}
	} while (button <= '0' || button >= '3');

	if (button == '1') {                                                             //���ݲ���������Ӧ����
		system("CLS");
		system("EXIT");
	}

	if (button == '2') {
		showMain();
	}
}

//�ɹ����溯��

void showSuccess(int correctTimes, int runTimes, double duration) {

	int i;

	system("CLS");                                                        //���� 

	printf("\n\n\n\n");
	printf("��������������*******************************************************\n");
	printf("��������������*                                                     *\n");
	printf("��������������*                    �¶Ե��� ��%s                   \n", tempWord[0]);

	for (i = 1; i<NUMBER; i++) {
		printf("��������������*                                %s                   \n", tempWord[i]);
	}
	printf("��������������*                                                     *\n");
	printf("��������������*                         (^o^)                       *\n");
	printf("��������������*  ���ˣ�%2d ��                                        *\n", runTimes);
	printf("��������������*  ��ʱ��%5.2lf ��              �÷֣�%5.2lf��          *\n", duration, score(correctTimes, runTimes));
	printf("��������������*                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("�������������� ");

	scoreInput(name, score(correctTimes, runTimes), duration);
	sleep((clock_t)6 * CLOCKS_PER_SEC);
	showTips();
}



//ʧ�ܽ��溯��

void showFailure() {

	int i;
	system("CLS");                                                        //���� 

	printf("\n\n\n\n");
	printf("��������������*******************************************************\n");
	printf("��������������*                                                     *\n");
	printf("��������������*                       ��Ϸʧ�ܣ���                  *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*                    ��ȷ�����ǣ�%s                   \n", tempWord[0]);

	for (i = 1; i<NUMBER; i++) {
		printf("��������������*                                %s                   \n", tempWord[i]);
	}
	printf("��������������*                                                     *\n");
	printf("��������������*                       ~~O(_)O~~                     *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("�������������� ");

	sleep((clock_t)6 * CLOCKS_PER_SEC);
	showTips();

}

//�����ȡ���ʺ���

char* randomExtract() {

	char wordTemp[5000];

	FILE *fp;                                                               //����һ���ļ�ָ�룬ָ���ļ���ĸ
	int i = 0;                                                                 //����һ��ѭ������
	int randomFigure;                                                        //����һ�����������           
	char ch;                                                                 //����һ���ַ����������ڶ�ȡ�ļ���ĸ


	srand(time(NULL));                                                        //����������� 
	randomFigure = rand() % 500 + 1;                                               //����һ�������


	fp = fopen(PATH1, "r");                                                       //���ļ�
	if (fp == 0) {
		printf("file error!\n");
		exit(1);
	}


	while ((ch = fgetc(fp)) != EOF) {                                        //��ȡ�ļ�
		wordTemp[i++] = ch;
	}
	wordTemp[i] = '\0';
	fclose(fp);                                                               //�ر��ļ�
																			  //  if

	while (wordTemp[randomFigure] != ' '&&wordTemp[randomFigure] != '\n') {                               //����Ӷ�ȡ���ı���ȡ���ʲ���������ĵ���
		randomFigure++;
	}
	randomFigure++;
	i = 0;
	while (wordTemp[randomFigure] != ' '&&wordTemp[randomFigure] != '\n') {
		word[i] = wordTemp[randomFigure];
		i++;
		randomFigure++;
	}
	word[i] = '\0';
	return word;                                                             //���ػ�õĵ���
}

//ʱ�亯������

void sleep(clock_t wait)
{
	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
}

//������һ����Ϸ�����е����жϺ���

void start() {

	char *ps;
	int length,
		i, k = 0,                                                            //ѭ������i,k
		runTimes = 1,                                                       //�´�ѭ������  
		flag, flag1 = 0,                                                       //��־����

		correctTimes = 0,
		number,                                                         //���ƻغ���
		tempErrorTimes = 0,
		tempCorrectTimes;

	char ch1[15];
	char ch;
	clock_t start, finish;
	double  duration;

	showEnter();
	system("CLS");                                                      //���� 

	start = clock();

	number = NUMBER;                                                      //��ʼ��Ҫ���еĻغ���

	Number = 0;

	while (number>0) {


		tempErrorTimes = 0;
		tempCorrectTimes = 0;

		ps = randomExtract();

		length = strlen(ps);                                           //���������ȡ�ĵ��ʵĳ���

		strcpy(tempWord[Number], ps);

		printf("\n\n\n\n");
		printf("��������������*******************************************************\n");
		printf("              *                     �� %1d �غ�                       *\n", NUMBER - number + 1);
		printf("              *                      ");
		for (i = 0; i<length; i++)
		{
			ch1[i] = '-';
			printf("-");
		}
		printf("\n");
		printf("              *������һ����ĸ���в²�!                              *\n");        //�������һ����ĸ������Ϸ
		printf("�������������� ");
		while (tempErrorTimes<ERROR_TIMES)
		{
			flag = 0;
			fflush(stdin);
			ch = getchar();
			for (i = 0; i<length; i++)
			{
				if ((*(ps + i) == ch) && (ch != ch1[i]))
				{
					ch1[i] = *(ps + i);
					k++;
					tempCorrectTimes++;
					correctTimes++;
					break;
				}
			}
			if (k == 0)
			{
				tempErrorTimes++;
				printf("              *����������!,���ٴ�����һ����ĸ���㻹�� %d �γ������\n               ", ERROR_TIMES - tempErrorTimes);								//��ʾ���������Ϣ����						

			}

			else
			{
				printf("�������������� ");
				for (i = 0; i<length; i++)
				{
					printf("%c", ch1[i]);
				}
				printf("\n");
				printf("�������������� ");
				k--;
			}
			if (tempCorrectTimes == length)
			{
				flag = 1;
				flag1++;
				if (Number<NUMBER - 1) {
					showTemporarySuccess(Number);
					Number++;
				}
				break;
			}
			runTimes++;
		}
		if (Number<NUMBER - 1) {
			showTemporaryFailure(Number);
		}
		Number++;
		system("CLS");
		number--;
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	if (flag == 1 && flag1 == NUMBER)
	{
		showSuccess(correctTimes, runTimes, duration);                     //�򿪳ɹ����溯��
	}
	else {

		showFailure();                                                   //��ʧ�ܽ���

	}
}

//����÷ֺ�������

double score(int correctTimes, int runTimes) {

	double scores;

	scores = (double)correctTimes / runTimes * 100;   //�÷ּ������

	return scores;
}

//��ʾ��Ϣ����

void showTips() {
	char button;                                                                        //�����û����������

	system("CLS");                                                                         //����

	printf("\n\n\n\n");
	printf("��������������*************************��ʾ**************************\n");
	printf("         ���� *                                                     *\n");
	printf("         ���� *                      ����һ�֣���                   *\n");
	printf("          ����*                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("��������������*  1����                                        2���� *\n");
	printf("�������������� ");

	do {
		fflush(stdin);
		button = getchar();                                                                 //�û������������
		if (button == '\n') {
			showTips();
		}
		fflush(stdin);
		if (button != '1') {
			printf("�������������� ����������������룡����\n�������������� ");
		}
	} while (button <= '0' || button >= '3');

	if (button == '1') {                                                                        //���ݲ���������Ӧ����
		start();
	}

	if (button == '2') {
		showMain();
	}
}

void scoreInput(char *name, double duration, double scores)
{
	FILE *fp;

	strcpy(playerTemp.name, name);
	playerTemp.score = scores;
	playerTemp.time = duration;
	fp = fopen(PATH2, "a+");
	if (fp == 0)
	{
		printf("file error");
		exit(1);
	}
	fprintf(fp, "%s %.2lf %.2lf ", playerTemp.name, playerTemp.time, playerTemp.score);
	fclose(fp);
}

//�Ƚ���ҷ�������

int compareScore()
{
	int i, j,                                                                  //��������ѭ������
		playerNumber = 0;                                                //����һ����Ǳ����ʹ�����������ı���                                    
	double temp1, temp2;
	char temp3[20];

	FILE *fp;
	fp = fopen(PATH2, "r");
	if (fp == 0)
	{
		printf("file error");
		exit(1);
	}

	fscanf(fp, "%s%lf%lf", playerTemp.name, &playerTemp.time, &playerTemp.score);    //���ļ��ж�ȡ�����Ϣ����ҽṹ��������
	strcpy(allPlayer[playerNumber].name, playerTemp.name);
	allPlayer[playerNumber].score = playerTemp.score;
	allPlayer[playerNumber].time = playerTemp.time;


	if (fabs(allPlayer[0].time - 0)<EPS) {                                  //�ж��Ƿ��ȡ��������                                     
		playerNumber = 0;
	}
	else {
		playerNumber = 1;
	}

	while (!feof(fp))
	{

		fscanf(fp, "%s%lf%lf", playerTemp.name, &playerTemp.time, &playerTemp.score);
		strcpy(allPlayer[playerNumber].name, playerTemp.name);
		allPlayer[playerNumber].score = playerTemp.score;
		allPlayer[playerNumber].time = playerTemp.time;

		playerNumber++;
	}


	if (playerNumber == 0 || playerNumber == 1) {

		return playerNumber;
	}                                                                        //ð�����򷨣��÷ָߵ�������ǰ��
	else {
		for (i = 0; i<playerNumber; i++)
			for (j = playerNumber - 1; j>i; j--)
			{
				if (allPlayer[j].score>allPlayer[j - 1].score)
				{
					temp1 = allPlayer[j - 1].score;
					allPlayer[j - 1].score = allPlayer[j].score;
					allPlayer[j].score = temp1;

					strcpy(temp3, allPlayer[j - 1].name);
					strcpy(allPlayer[j - 1].name, allPlayer[j].name);
					strcpy(allPlayer[j].name, temp3);

					temp2 = allPlayer[j - 1].time;
					allPlayer[j - 1].time = allPlayer[j].time;
					allPlayer[j].time = temp2;
				}
			}
		return playerNumber;

	}
	fclose(fp);
}

//��ʾ������Ϸ����

void showEnter() {
	int i = 3, j = 1, k = 1, n;                                              //����һ��ѭ�����������ڼ�����������
	int randomFigure;                                               //������һ���������

	for (; i>0; i--) {

		srand(time(NULL));
		randomFigure = rand() % 3 + 1;

		system("CLS");
		printf("\n\n\n\n");
		printf("��������������*************************������Ϸ**********************\n");
		printf("         ���� *                                                     *\n");
		printf("         ���� *                                                     *\n");
		switch (randomFigure) {
		case 1:                                                                          //��������ʾ
			printf("              *    ��ʾ����Ϸ�Ѷ��Ĵ󣬵�С�����룡��               *\n");
			break;
		case 2:
			printf("              *    ��ʾ����Ϸ�ּ����غϣ��¶����е��ʲ���ɹ�����   *\n");
			break;
		case 3:
			printf("              *    ��ʾ���µ������´�15�Σ�����ʧ�ܣ���           *\n");
			break;
		}
		printf("         ���� *                                                     *\n");
		printf("         ���� *                                                     *\n");
		printf("         ����    ���ڼ�����Ϸ�����Ժ󡭡�����\n\n");

		switch (j) {
		case 1:
			printf("         ���� ");
			break;
		case 2:
			printf("         ���� >>>>>>>>>>>>>>>>>>");
			break;
		case 3:
			printf("         ���� >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
			break;
		}
		for (n = 0; n<6; n++) {
			printf(">>>");
			sleep((clock_t)1 * CLOCKS_PER_SEC);
		}
		j++;
	}
}

//ĳ�غϳɹ�������ʾ����

void showTemporarySuccess(int Number) {
	system("CLS");                                                        //���� 

	printf("\n\n\n\n");
	printf("��������������*******************************************************\n");
	printf("��������������*                                                     *\n");
	printf("��������������*                    �¶Ե��� ��%s                   \n", tempWord[Number]);
	printf("��������������*                                                     *\n");
	printf("��������������*                    ���ڽ�����һ�غ�...              *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("��������������");
	sleep((clock_t)6 * CLOCKS_PER_SEC);

}

void showTemporaryFailure(int Number) {
	system("CLS");                                                        //���� 

	printf("\n\n\n\n");
	printf("��������������*******************************************************\n");
	printf("��������������*                                                     *\n");
	printf("��������������*          �´��ˣ���ȷ���� ��%s                        \n", tempWord[Number]);
	printf("��������������*                                                     *\n");
	printf("��������������*          ��Ҫ���ģ�������һ�غϣ����ڽ���...        *\n");
	printf("��������������*                                                     *\n");
	printf("��������������*******************************************************\n");
	printf("��������������");
	sleep((clock_t)6 * CLOCKS_PER_SEC);

}


