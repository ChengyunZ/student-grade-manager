#include<stdio.h>
#include<string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    float scores[3];
    float total;
    float average;

}Students;

void addStudents(Students students[],int *n);
void delStudents(Students students[],int *n);
void modifyStudents(Students students[],int *n);
void searchStudents(Students students[],int *n);
void showStudentsALL(Students students[],int *n);
void sortStudents(Students students[],int *n);
void statistics(Students students[],int *n);
void savefiles(Students students[],int n);

int main()
{
    Students students[MAX_STUDENTS];
    int num = 0;
    printf("请输入学生数目:\n");
    if( scanf("%d",&num) != 1 || num<1 || num > MAX_STUDENTS) {
        printf("输入的学生数量无效!");   //这里的！=1是返回值，表示成功读了一个数据
        return 1;
    }
    printf("现在我们要录入%d个学生在系统里\n",num);
    int n = 0;

    //menu design
    int choice = 0;
    do {
        printf("%-35s\n","================Sysyem of Students MANAGEMENT================");
        printf("%-35s\n","1. Add Students");
        printf("%-35s\n","2. Delete Students");
        printf("%-35s\n","3. Modify INFOTAMTION of Students");
        printf("%-35s\n","4. Search Students");
        printf("%-35s\n","5. Show ALL Students");
        printf("%-35s\n","6. Sort by Scores");
        printf("%-35s\n","7. Score STATISTICS");
        printf("%-35s\n","8. Save Data");
        printf("%-35s\n","0. EXIT SYSTEM");
        printf("%-35s\n","=============================================================");
        printf("%-35s\n","please enter your choice:");
        scanf("%d",&choice);

        switch (choice) {
            case 1 :
            addStudents(students,&n);
            break;// 这里必须加break不然直接进case2了！！！
            case 2 :
            delStudents(students,&n);
            break;
            case 3 :
            modifyStudents(students,&n);
            break;
            case 4 :
            searchStudents(students,&n);
            break;
            case 5 :
            showStudentsALL(students,&n);
            break;
            case 6 :
            sortStudents(students,&n);
            break;
            case 7 :
            statistics(students,&n);
            break;
            case 8 :
            savefiles(students,n);
            break;

        }





    } while(choice > 0 && choice < 9) ;

    

    


    
    
    return 0;
}

    /////part 1 add student//////
    //enter students information 
    //1.check full 
    //2.enter id|3.check id repeated|4.scan name&age|5.scan scores
    //6.calculate total and average|7.account+1
void addStudents(Students students[],int *n)
{
//1.检查人数是否满了
    if(*n >= MAX_STUDENTS) {
        printf("students account is already full!");
    }

//2+3.输入并检查学生的id是否重复    
    printf("Please enter student's id:\n");
      
    if( scanf("%d",&students[*n].id) != 1  ) {
        printf("invalid id");  //检查数字有效  
        return;  //在void函数里如果直接返回一个值那么证明直接结束这个函数
    }  
    for(int i = 0;i<(*n);i++) {   //遍历已经有的学生的学号，观看是否有重复
        if(students[i].id == students[*n].id) {
            printf("id has existed\n");
            return; //在void函数里如果直接返回一个值那么证明直接结束这个函数
        }
        
    }  
//4.输入学生的姓名与年龄
    printf("Please enter student's name and age:\n");
    scanf("%49s %d",students[*n].name,&students[*n].age); //%49s 这是为了防止姓名超过名字数组最大长度
//5. 输入他/她的分数
    students[*n].total = 0 ; 
    for(int j = 0;j<3;j++) {
        printf("enter his/her score:\n");
        scanf("%f",&students[*n].scores[j]);//这就是给结构体里面的数组赋值的方法
        students[*n].total += students[*n].scores[j];   
    }
//6.计算总分与平均数
    students[*n].average = students[*n].total / 3;
    // printf("%f %f",students[*n].average,students[*n].total);
//7.完成录入，总学生加1
    (*n)++;
    
}



    /////part2 delete students/////
void delStudents(Students students[],int *n)
{
    if(*n == 0) {
        printf("No student to delete!\n");
    }
    int id = 0;

    printf("please enter the student's ID to delete:\n");
    if( scanf("%d",&id) != 1 ) {
        printf("invalid id\n");
        return;
    }
    
    int idx = -1;
    for(int i = 0;i<*n;i++) {
        if(students[i].id == id) {
            // printf("I find him/her!\n");
            idx = i; //这里利用索引准备对数组顺序进行更改
            break;//找到了
        }
    }

    if(idx==-1) {
        printf("Student not FOUND!\n");
        return;//没找到
    }

    //下面我要对数组idx编号的学生进行删除，后面的人到前面一个格子
    for(int j = idx;j<(*n)-1;j++) {
        students[j] = students[j+1];
    }

    printf("The ID:%d student has been deleted!\n",id);
    (*n)--;
}


/////part3 modify students information/////
void modifyStudents(Students students[],int *n) 
{
    int id = 0;
    if(*n == 0) {
        printf("No students MODIFIED\n");
        return;
    }

    printf("Enter the id of stu that you want to modify:\n");
    int ID = 0;
    if( scanf("%d",&ID) != 1 ) {
        printf("invalid id\n");
    }

    int idx = -1;
    for(int j=0;j<(*n);j++) {
        if(students[j].id == ID) {
            idx = j;
            break;
        }
    }
    if(idx == -1) {
        printf("No students FOUND!");
        return;
    }

    ;
    //在这里要进行对应修改的选择
    int choice = 0;
    
    printf("%-35s\n","1.name");
    printf("%-35s\n","2.age");
    printf("%-35s\n","3.scores");
    printf("Please enter what u want to modify:\n");
    scanf("%d",&choice);

    switch (choice) {
        case 1 :
        printf("请输入要更改成的名字:\n");
        scanf("%s",students[idx].name);
        break;

        case 2 :
        printf("请输入要改成的年龄:\n");
        scanf("%d",&students[idx].age);
        break;

        case 3 :
        printf("请输入要更改成的成绩:\n");
        students[idx].total = 0;
        for(int k = 0;k<3;k++)  {
            printf("%d.",k);
            scanf("%d",students[idx].scores[k]);
            students[idx].total += students[idx].scores[k];
        }
        students[idx].average = students[idx].total / 3;
        break;

        printf("Modification OVER");
    }   
}


/////part4 search students ijSEARCH/////

void searchStudents(Students students[],int *n)
{
    printf("enter the student's ID you want to find:\n");
    int id = 0;
    if( scanf("%d",&id) != 1 ) {
        printf("invalid id\n");
        return;
    }

    int idx = -1;
    for(int j=0;j<(*n);j++) {
        if(students[j].id == id) {
            idx = j;
            break;
        }
    }
    if(idx == -1) {
        printf("No students FOUND!");
        return;
    }
    printf("ID:%d\nNAME:%s\nAGE:%d\n",students[idx].id,students[idx].name,students[idx].age);
    for(int k = 0;k<3;k++)  {
            printf("SCORE:%d\n",students[idx].scores[k]);
    }
    printf("TOTAL:%f\nAVERAGE:%f\n",students[idx].total,students[idx].average);
}

////part5 show all students/////

void showStudentsALL(Students students[],int *n){

for(int i = 0;i<(*n);i++) {
    printf("ID:%d\nNAME:%s\nAGE:%d\n",students[i].id,students[i].name,students[i].age);
    for(int k = 0;k<3;k++)  {
            printf("SCORE:%f\n",students[i].scores[k]);
    }
    printf("TOTAL:%f\nAVERAGE:%f\n",students[i].total,students[i].average);
}
}

/////part6 sort students by grades/////
void sortStudents(Students students[],int *n)
{
    //ij sort 
    Students temp;
    for(int i = 0;i<(*n)-1;i++) {
        for(int j = 0;j<(*n)-i-1;j++) {
            if(students[j].total < students[j+1].total) {
                temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp; 
            }
        }
    }
    printf("sort over\n");
}


/////part7 scores statistic/////
//1.number of students
//2.calculate average
//3.find top and last score
//4.statistic the average of ever course
void statistics(Students students[],int *n) 
{
    //1
    printf("the number of students is %d\n",*n);
    //2
    float Average = 0.0;
    float Total = 0.0;
    for(int i = 0;i<(*n);i++) {
        Total += students[i].average;
    }
    Average = Total / (*n);
    printf("the average score of students is %f\n",Average);

    //3
    float get_MAX = students[0].total;
    float get_MIN = students[0].total;
    for(int i = 0;i<(*n);i++) {
        if(students[i].total > get_MAX) {
            get_MAX = students[i].total;
        }
        if(students[i+1].total < get_MIN) {
            get_MIN = students[i].total;
        }
    printf("the highest score is %f\nthe lowest score is %f\n",get_MAX,get_MIN);
        //4
        float tot[3];
        float ave[3];
        float ave1 = 0.0;
        int z = 0;
        for(int j = 0;j<3;j++) {
            ave1 = 0;
            for(int k = 0;k<(*n);k++) {
                ave1 += students[k].scores[j];   
            }
            ave[z] = ave1 / (*n);
            printf("the average of score%d is %f\n",z+1,ave[z]);
            z++;
        }       
}   
}

/////part8 save files/////
void savefiles(Students students[],int n)
{
    FILE *file = fopen("C:\\Users\\zcy\\Desktop\\a.txt","w");

    if(file == NULL) {
        printf("file can't be opened");
        return;
    }

    for(int i = 0;i<n;i++) {
        fprintf(file,"ID:%d\nNAME:%s\nAGE:%d\nSCORES:%f %f %f\nTOTAL:%f\nAVERAGE:%f\n\n"
            ,students[i].id,students[i].name,students[i].age,students[i].scores[0],students[i].scores[1],students[i].scores[2],students[i].total,students[i].average);
        
    }
    if( fclose(file) == EOF ) {
        printf("files can't be saved");
        return;
    }

    printf("files saved successfully");
}

