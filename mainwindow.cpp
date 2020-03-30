//defualt include
#include "mainwindow.h"
#include "ui_mainwindow.h"
//SQL include
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
//string include
#include <QString>
//QMessageBox include
#include <QMessageBox>
// Date include
#include <QDateTime>

//image include
#include <QPixmap>
#include <QFileDialog>

//key events for press enter key on login
#include <QKeyEvent>

//include a Q Horizon Layout
#include <QHBoxLayout>

//include File and Directory option
#include <QFile>
#include <QDir>

//include string for give backup
#include <string>
#include <cstring>


// varaible (version of application)
QString verion_app = "v0.3";

//search edit varibels regestration
QString family="";
QString name="";
QString code="";
QString *editVar;
//QString *editVar2;
QString editParameter="";
QString avatar_url="";

//database dynamic variables for Disable Status on(RegistraionTitles)
QString dbDynamic_disable_status_Text = "0"; // or use 'false'

//check code user at search to edit user registeration
bool stats_check_code_user = false;

// for search edit registration name and family variabels
bool edit_search_name_and_family = false;
bool edit_search_code_and_name_and_family = false;
bool edit_search_code_and_name = false;
bool edit_search_code_and_family = false;
QString tmp1,tmp2,tmp3 = "";


//userinformation set a varaible to click btn edit user by code.
bool edit_user_coming_from_userinfo_btn = false;

//url defualt avatar for registration from adminconfig
QString defualt_avatar="";

//for block key event on other pages..
bool user_is_on_login_page = false;

//var address file hs users
QString address_avatar_hs_users = "./avatar/" ; //"/root/Downloads/avatar/";
QString defualt_avatar_hs_users = "./avatar/defualt/"; //"/root/Downloads/avatar/defualt/";

//sub avatar variables
QString for_rename_avatar_lastusername_is_here = "";


//a string for easy way to change format images (avatar/defualt avatar)
QString avatar_format = ".jpg"; // and edit 2 .jpg format from filters image QFileDialog



//create class part
int last_class_id_integer;


//student selected in a class  and want to change score
QString code_student_for_edit_score;


//variable for static make class id
QString class_id_is_herex = "";

//var image for create student exists
bool image_for_new_student_is_exists = false;

//var for check stats want to add student from list (btn)
bool want_to_select_student_from_list_for_add_to_a_class= false;

bool im_want_to_select_student_from_list_students_for_add_to_class = false;


bool im_from_students_list = false;
bool im_from_hs_list = false;


//student/hs user code meli
QString code_meli = "";
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(QSize(841, 640));
    QIcon icon("./icon.ico");
    this->setWindowIcon(icon);
    //Login admin page
    ui->menubar->setDisabled(true); // or hide this
    user_is_on_login_page=true;
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();

    //other
    ui->groupBox_change_window_title->hide();
    ui->groupBox_change_userpass_admin->hide(); ui->groupBox_maxtry_change->hide();
    ui->groupBox_avatar_path_change->hide(); ui->groupBox_currenttry_change->hide();
    ui->groupBox_send_cmd_to_db->hide(); ui->groupBox_history_of_admin_logins_log->hide();
    ui->groupBox_db_backup_config->hide();
    ui->groupBox_resetfactory_tables->hide();

    //change forms
    ui->groupBox_change_class_titles->hide();
    ui->groupBox_hs_form->hide();
    ui->groupBox_set_tabTitles->hide();
    ui->groupBox_change_headers->hide();
    ui->scrollArea_settings_change_titles->hide(); //this is skit!
    ui->groupBox_change_student_titles->hide();
    ui->groupBox_change_tbl_title->hide();





    //---------------Login admin page is ended.

    ui->groupBox_login->setGeometry(240,130,361,281);
    ui->groupBox_hs_search_for_edit->setGeometry(200,130,460,331);
    ui->groupBox_change_show->setGeometry(350,40,300,320);
    ui->groupBox_change_database->setGeometry(40,40,300,320);
    ui->groupBox_hs_register->setGeometry(10,10,821,581);
    ui->groupBox_show_users_hs->setGeometry(90,50,661,511);
    ui->groupBox_hs_user_information->setGeometry(60,10,731,561);
    ui->groupBox_settings->setGeometry(70,10,711,541);
    ui->groupBox_home->setGeometry(145,100,541,371);
    ui->groupBox_send_cmd_to_db->setGeometry(150,140,431,121);
    //ui->horizontalLayout_return_to_home_from_config->setGeometry();
    ui->groupBox_db_backup_config->setGeometry(40,20,601,371);
    ui->groupBox_hs_form->setGeometry(30,20,631,101);
    ui->groupBox_change_window_title->setGeometry(120,100,471,201);
//    ui->scrollArea_settings_change_titles->setGeometry(10,10,661,401);
    ui->groupBox_resetfactory_tables->setGeometry(90,50,511,341);
    ui->groupBox_search_hs_users->setGeometry(20,10,811,571);
    ui->groupBox_search_result->setGeometry(110,30,621,511);
    ui->groupBox_create_class->setGeometry(170,60,511,471);
    ui->groupBox_class_list->setGeometry(70,40,701,521);
    ui->groupBox_show_class_info->setGeometry(20,30,801,561);
    ui->groupBox_question_select_one_part_for_edit_class->setGeometry(220,160,391,271);
    ui->groupBox_edit_this_class->setGeometry(60,30,731,551);
    ui->groupBox_edit_student_from_this_class->setGeometry(70,30,721,541);
    ui->groupBox_edit_form_stu_from_class->setGeometry(40,20,771,561);
    ui->groupBox_student_register->setGeometry(10,10,821,581);
    ui->groupBox_show_students_list->setGeometry(90,50,661,511);
    ui->groupBox_student_information->setGeometry(60,10,731,561);
    ui->groupBox_qustion_add_student_to_this_class_by->setGeometry(260,160,331,291);
    ui->groupBox_insert_more_data_to_student_for_this_class->setGeometry(80,50,711,521);
    ui->groupBox_search_on_class->setGeometry(80,20,691,581);
    ui->groupBox_result_search_class->setGeometry(90,40,691,531);

    //forms
    ui->groupBox_side_right_forms->setGeometry(370,70,261,281);
    ui->groupBox_side_left_forms->setGeometry(100,70,261,281);
    ui->groupBox_change_class_titles->setGeometry(40,10,611,451);
    ui->groupBox_hs_form->setGeometry(40,20,611,431);
    ui->groupBox_set_tabTitles->setGeometry(30,20,611,441);
    ui->groupBox_change_headers->setGeometry(50,10,581,421);
    ui->groupBox_change_student_titles->setGeometry(50,10,601,431);


    //f------------------- enable for windows compile (with database SQLite)
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./database/hs.db");

    QDir check_dire_database("./database");
    if(check_dire_database.exists())
    {
        //nothing..
    }
    else
    {
        QMessageBox::information(this," ","فایل پایگاه داده یافت نشد"
                                          "\n"
                                          "لطفا تا پایان عملیات ساخت و تنظیم پایگاه داده صبر کنید.");
        check_dire_database.mkpath(".");
        QFile database_file_will_be_create("hs.db");
        if(db.open())
        {
            //create tables to hs.db


            //----create headers
            //sr0-3 -> search result students/hs
            //cl0-15 -> class list
            //src0-3 -> search result class
            //s0-29 -> score
            QSqlQuery create_table_headers("CREATE TABLE headers(sr0 TEXT,sr1 TEXT,sr2 TEXT,sr3 TEXT);");
            QSqlQuery createTablexprc0("ALTER TABLE headers ADD src0 TEXT;");
            QSqlQuery createTablexprc1("ALTER TABLE headers ADD src1 TEXT;");
            QSqlQuery createTablexprc2("ALTER TABLE headers ADD src2 TEXT;");
            QSqlQuery createTablexprc3("ALTER TABLE headers ADD src3 TEXT;");
            QSqlQuery alter_tbl_headers_cl_0("ALTER TABLE headers ADD cl0 TEXT;");
            QSqlQuery alter_tbl_headers_cl_1("ALTER TABLE headers ADD cl1 TEXT;");
            QSqlQuery alter_tbl_headers_cl_2("ALTER TABLE headers ADD cl2 TEXT;");
            QSqlQuery alter_tbl_headers_cl_3("ALTER TABLE headers ADD cl3 TEXT;");
            QSqlQuery alter_tbl_headers_cl_4("ALTER TABLE headers ADD cl4 TEXT;");
            QSqlQuery alter_tbl_headers_cl_5("ALTER TABLE headers ADD cl5 TEXT;");
            QSqlQuery alter_tbl_headers_cl_6("ALTER TABLE headers ADD cl6 TEXT;");
            QSqlQuery alter_tbl_headers_cl_7("ALTER TABLE headers ADD cl7 TEXT;");
            QSqlQuery alter_tbl_headers_cl_8("ALTER TABLE headers ADD cl8 TEXT;");
            QSqlQuery alter_tbl_headers_cl_9("ALTER TABLE headers ADD cl9 TEXT;");
            QSqlQuery alter_tbl_headers_cl_10("ALTER TABLE headers ADD cl10 TEXT;");
            QSqlQuery alter_tbl_headers_cl_11("ALTER TABLE headers ADD cl11 TEXT;");
            QSqlQuery alter_tbl_headers_cl_12("ALTER TABLE headers ADD cl12 TEXT;");
            QSqlQuery alter_tbl_headers_cl_13("ALTER TABLE headers ADD cl13 TEXT;");
            QSqlQuery alter_tbl_headers_cl_14("ALTER TABLE headers ADD cl14 TEXT;");
            QSqlQuery alter_tbl_headers_cl_15("ALTER TABLE headers ADD cl15 TEXT;");
            QSqlQuery alter_tbl_headers_0("ALTER TABLE headers ADD s0 TEXT;");
            QSqlQuery alter_tbl_headers_1("ALTER TABLE headers ADD s1 TEXT;");
            QSqlQuery alter_tbl_headers_2("ALTER TABLE headers ADD s2 TEXT;");
            QSqlQuery alter_tbl_headers_3("ALTER TABLE headers ADD s3 TEXT;");
            QSqlQuery alter_tbl_headers_4("ALTER TABLE headers ADD s4 TEXT;");
            QSqlQuery alter_tbl_headers_5("ALTER TABLE headers ADD s5 TEXT;");
            QSqlQuery alter_tbl_headers_6("ALTER TABLE headers ADD s6 TEXT;");
            QSqlQuery alter_tbl_headers_7("ALTER TABLE headers ADD s7 TEXT;");
            QSqlQuery alter_tbl_headers_8("ALTER TABLE headers ADD s8 TEXT;");
            QSqlQuery alter_tbl_headers_9("ALTER TABLE headers ADD s9 TEXT;");
            QSqlQuery alter_tbl_headers_10("ALTER TABLE headers ADD s10 TEXT;");
            QSqlQuery alter_tbl_headers_11("ALTER TABLE headers ADD s11 TEXT;");
            QSqlQuery alter_tbl_headers_12("ALTER TABLE headers ADD s12 TEXT;");
            QSqlQuery alter_tbl_headers_13("ALTER TABLE headers ADD s13 TEXT;");
            QSqlQuery alter_tbl_headers_14("ALTER TABLE headers ADD s14 TEXT;");
            QSqlQuery alter_tbl_headers_15("ALTER TABLE headers ADD s15 TEXT;");
            QSqlQuery alter_tbl_headers_16("ALTER TABLE headers ADD s16 TEXT;");
            QSqlQuery alter_tbl_headers_17("ALTER TABLE headers ADD s17 TEXT;");
            QSqlQuery alter_tbl_headers_18("ALTER TABLE headers ADD s18 TEXT;");
            QSqlQuery alter_tbl_headers_19("ALTER TABLE headers ADD s19 TEXT;");
            QSqlQuery alter_tbl_headers_20("ALTER TABLE headers ADD s20 TEXT;");
            QSqlQuery alter_tbl_headers_21("ALTER TABLE headers ADD s21 TEXT;");
            QSqlQuery alter_tbl_headers_22("ALTER TABLE headers ADD s22 TEXT;");
            QSqlQuery alter_tbl_headers_23("ALTER TABLE headers ADD s23 TEXT;");
            QSqlQuery alter_tbl_headers_24("ALTER TABLE headers ADD s24 TEXT;");
            QSqlQuery alter_tbl_headers_25("ALTER TABLE headers ADD s25 TEXT;");
            QSqlQuery alter_tbl_headers_26("ALTER TABLE headers ADD s26 TEXT;");
            QSqlQuery alter_tbl_headers_27("ALTER TABLE headers ADD s27 TEXT;");
            QSqlQuery alter_tbl_headers_28("ALTER TABLE headers ADD s28 TEXT;");
            QSqlQuery alter_tbl_headers_29("ALTER TABLE headers ADD s29 TEXT;");

            QSqlQuery add_defualt_data_to_headers("INSERT INTO headers (sr0) VALUES('کدملی');");
            QSqlQuery update_values_to_headers_0("UPDATE headers SET sr1='نام',sr2='نام خانوادگی',sr3='مقدار یافت شده',src0='کدکلاس',src1='مدرس',src2='درس',src3='مقدار یافت شده';");
            QSqlQuery update_values_to_headers_1("UPDATE headers SET cl0='cl0',cl1='cl1',cl2='cl2',cl3='cl3',cl4='cl4',cl5='cl5',cl6='cl6',cl7='cl7',cl8='cl8',cl9='cl9',cl10='cl10',cl11='cl11',cl12='cl12',cl13='cl13',cl14='cl14',cl15='cl15';");
            QSqlQuery update_values_to_headers_2("UPDATE headers SET s0='s0',s1='s1',s2='s2',s3='s3',s4='s4',s5='s5',s6='s6',s7='s7',s8='s8',s9='s9',s10='s10',s11='s11',s12='s12',s13='s13',s14='s14',s15='s15',s16='s16',s17='s17',s18='s18',s19='s19',s20='s20',s21='s21',s22='s22',s23='s23',s24='s24',s25='s25',s26='s26',s27='s27',s28='s28',s29='s29';");
            //-----end of headers



            //---create studentTitles
            QSqlQuery createTableStudentTItles("CREATE TABLE studentTitles(st0 TEXT,st1 TEXT,st2 TEXT,st3 TEXT,st4 TEXT,st5 TEXT,st6 TEXT,st7 TEXT,st8 TEXT,st9 TEXT,st10 TEXT,st11 TEXT,st12 TEXT,st13 TEXT,st14 TEXT,st15 TEXT,st16 TEXT,st17 TEXT,st18 TEXT,st19 TEXT,st20 TEXT,st21 TEXT,st22 TEXT,st23 TEXT,st24 TEXT,st25 TEXT,st26 TEXT,st27 TEXT,st28 TEXT,st29 TEXT);");
            QSqlQuery add_defualt_data_to_student_titles("INSERT INTO `studentTitles`(`st0`,`st1`,`st2`,`st3`,`st4`,`st5`,`st6`,`st7`,`st8`,`st9`,`st10`,`st11`,`st12`,`st13`,`st14`,`st15`,`st16`,`st17`,`st18`,`st19`,`st20`,`st21`,`st22`,`st23`,`st24`,`st25`,`st26`,`st27`,`st28`,`st29`) VALUES ('کدملی','name','family','father_name','student_title_4','student_title_5','student_title_6','student_title_7','student_title_8','student_title_9','student_title_10','student_title_11','student_title_12','student_title_13','student_title_14','student_title_15','student_title_16','student_title_17','student_title_18','student_title_19','student_title_20','student_title_21','student_title_22','student_title_23','student_title_24','student_title_25','student_title_26','student_title_27','student_title_28','student_title_29');");
            //------end of studentTitles


            //------create tabTitles
            QSqlQuery createTabletabTitle("CREATE TABLE tabTitles(tab_settings_0 TEXT,tab_settings_1 TEXT,tab_show_user_info_0 TEXT, tab_show_user_info_1 TEXT, tab_show_user_info_2 TEXT, tab_show_user_info_3 TEXT, tab_show_user_info_4 TEXT);");
            QSqlQuery add_data_to_tabTitles("INSERT INTO `tabTitles` (`tab_settings_0`) VALUES ('L');");
            QSqlQuery update_defualt_value_to_tabTitles("UPDATE tabTitles SET tab_settings_0='فرم ها', tab_settings_1='پیکربندی', tab_show_user_info_0='اطلاعات کاربر', tab_show_user_info_1='سایر 1', tab_show_user_info_2='سایر 2', tab_show_user_info_3='سایر 3',tab_show_user_info_4='نمرات';");
            //---------------end of tabTitles




            //-----create adminloginslog
            QSqlQuery createTableAdminloginslog("CREATE TABLE adminloginslog(login_number TEXT, login_date TEXT);");
            QSqlQuery add_Default_value_to_adminsloginlog("INSERT INTO adminloginslog (`login_number`,`login_date`) VALUES ('login_0','unknow date');");
            //--------------------- end of adminloginlogs



            //------create adminconfig TAble
            QSqlQuery createAdminConfig("CREATE TABLE adminconfig(username TEXT,password TEXT,maxtry TEXT,currenttry TEXT,total_logins TEXT,defualt_avatar TEXT,db_auto_backup TEXT,db_path_backup TEXT,window_title TEXT,last_cid TEXT);");
            QSqlQuery insert_defualt_value("INSERT INTO adminconfig (`username`,`password`,`maxtry`,`currenttry`,`total_logins`,`defualt_avatar`,`db_auto_backup`,`db_path_backup`,`window_title`,`last_cid`) VALUES ('admin','admin','5','0','0','null','disable','C:/','management-app v0.3','0');");
            //------end of adminconfig creator..


            //--------create t_class_info
            QSqlQuery create_tbl_t_class_info("CREATE TABLE t_class_info (t_cid TEXT,t_cinfo0 TEXT,t_cinfo1 TEXT,t_cinfo2 TEXT,t_cinfo3 TEXT,t_cinfo4 TEXT,t_cinfo5 TEXT,t_cinfo6 TEXT,t_cinfo7 TEXT,t_cinfo8 TEXT,t_cinfo9 TEXT,t_cinfo10 TEXT,t_cinfo11 TEXT,t_cinfo12 TEXT,t_cinfo13 TEXT,t_cinfo14 TEXT,t_cpara0 TEXT,t_cpara1 TEXT,t_cpara2 TEXT,t_cpara3 TEXT,t_cpara4 TEXT,t_cpara5 TEXT,t_cpara6 TEXT,t_cpara7 TEXT,t_cpara8 TEXT,t_cpara9 TEXT,t_cpara10 TEXT,t_cpara11 TEXT,t_cpara12 TEXT,t_cpara13 TEXT,t_cpara14 TEXT);");
            QSqlQuery insert_defualt_value_to_t_clasS_info("INSERT INTO t_class_info (`t_cid`,`t_cinfo0`,`t_cinfo1`,`t_cinfo2`,`t_cinfo3`,`t_cinfo4`,`t_cinfo5`,`t_cinfo6`,`t_cinfo7`,`t_cinfo8`,`t_cinfo9`,`t_cinfo10`,`t_cinfo11`,`t_cinfo12`,`t_cinfo13`,`t_cinfo14`,`t_cpara0`,`t_cpara1`,`t_cpara2`,`t_cpara3`,`t_cpara4`,`t_cpara5`,`t_cpara6`,`t_cpara7`,`t_cpara8`,`t_cpara9`,`t_cpara10`,`t_cpara11`,`t_cpara12`,`t_cpara13`,`t_cpara14`) VALUES ('title_cid','title_cinfo_0','title_cinfo_1','title_cinfo_2','title_cinfo_3','title_cinfo_4','title_cinfo_5','title_cinfo_6','title_cinfo_7','title_cinfo_8','title_cinfo_9','title_cinfo_10','title_cinfo_11','title_cinfo_12','title_cinfo_13','title_cinfo_14','title_cpara_0','title_cpara_1','title_cpara_2','title_cpara_3','title_cpara_4','title_cpara_5','title_cpara_6','title_cpara_7','title_cpara_8','title_cpara_9','title_cpara_10','title_cpara_11','title_cpara_12','title_cpara_13','title_cpara_14');");
            //---end of create tbl t_class_info


            //-------create tbl class_list
            QSqlQuery create_class_list_tbl("CREATE TABLE class_list(cid TEXT,ci0 TEXT,ci1 TEXT,ci2 TEXT,ci3 TEXT,ci4 TEXT,ci5 TEXT,ci6 TEXT,ci7 TEXT,ci8 TEXT,ci9 TEXT,ci10 TEXT,ci11 TEXT,ci12 TEXT,ci13 TEXT,ci14 TEXT,cp0 TEXT,cp1 TEXT,cp2 TEXT,cp3 TEXT,cp4 TEXT,cp5 TEXT,cp6 TEXT,cp7 TEXT,cp8 TEXT,cp9 TEXT,cp10 TEXT,cp11 TEXT,cp12 TEXT,cp13 TEXT,cp14 TEXT);");
            QSqlQuery make_defualt_value_to_class_list_tbl("INSERT INTO class_list (`cid`,`ci0`,`ci1`,`cip2`,`ci3`,`ci4`,`ci5`,`ci6`,`ci7`,`ci8`,`ci9`,`ci10`,`ci11`,`ci12`,`ci13`,`ci14`,`cp0`,`cp1`,`cp2`,`cp3`,`cp4`,`cp5`,`cp6`,`cp7`,`cp8`,`cp9`,`cp10`,`cp11`,`cp12`,`cp13`,`cp14`) VALUES ('cid','ci0','ci1','ci2','ci3','ci4','ci5','ci6','ci7','ci8','ci9','ci10','ci11','ci12','ci13','ci14','cp0','cp1','cp2','cp3','cp4','cp5','cp6','cp7','cp8','cp9','cp10','cp11','cp12','cp13','cp14');");
            //-----end of create class_list

            //-------- create registrationTitles 0-29
            //QSqlQuery droptblregistraionTitles("DROP TABLE registrationTitles;");
            QSqlQuery createTable("CREATE TABLE registrationTitles(t0 TEXT);");
            for(int i=0;i<=29;i++)
            {
                QSqlQuery createTitles("ALTER TABLE registrationTitles ADD t"+QString::number(i)+" TEXT;");
                QSqlQuery createDisabelStats("ALTER TABLE registrationTitles ADD disable_status"+QString::number(i)+" TEXT;");
            }
            QSqlQuery updateDefualtValuesToTitleForRegistraion("INSERT INTO `registrationTitles` (`t0`, `t1`, `t2`, `t3`, `t4`, `t5`, `t6`, `t7`, `t8`, `t9`, `t10`, `t11`, `t12`, `t13`, `t14`, `t15`, `t16`, `t17`, `t18`, `t19`, `t20`, `t21`, `t22`, `t23`, `t24`, `t25`, `t26`, `t27`, `t28`, `t29`, `disable_status0`, `disable_status1`, `disable_status2`, `disable_status3`, `disable_status4`, `disable_status5`, `disable_status6`, `disable_status7`, `disable_status8`, `disable_status9`, `disable_status10`, `disable_status11`, `disable_status12`, `disable_status13`, `disable_status14`, `disable_status15`, `disable_status16`, `disable_status17`, `disable_status18`, `disable_status19`, `disable_status20`, `disable_status21`, `disable_status22`, `disable_status23`, `disable_status24`, `disable_status25`, `disable_status26`, `disable_status27`, `disable_status28`, `disable_status29`) VALUES ('t0', 't1', 't2', 't3', 't4', 't5', 't6', 't7', 't8', 't9', 't10', 't11', 't12', 't13', 't14', 't15', 't16', 't17', 't18', 't19', 't20', 't21', 't22', 't23', 't24', 't25', 't26', 't27', 't28', 't29', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');");
            QSqlQuery updateDefualtValuesToTitlesForRegistraion("UPDATE registrationTitles SET t0='کدملی‌ :', t1='نام :', t2='نام خانوادگی‌ :', t3='نام پدر :';");
            //------------- end of registrationTitles



            //-----create table students
            QSqlQuery createTableStudents("CREATE TABLE students (p0 TEXT,p1 TEXT,p2 TEXT,p3 TEXT,p4 TEXT,p5 TEXT,p6 TEXT,p7 TEXT,p8 TEXT,p9 TEXT,p10 TEXT,p11 TEXT,p12 TEXT,p13 TEXT,p14 TEXT,p15 TEXT,p16 TEXT,p17 TEXT,p18 TEXT,p19 TEXT,p20 TEXT,p21 TEXT,p22 TEXT,p23 TEXT,p24 TEXT,p25 TEXT,p26 TEXT,p27 TEXT,p28 TEXT,p29 TEXT,p30 TEXT);");
            //------end of students


            //---------------- registreation auto creator table registration
            QSqlQuery createTablex("CREATE TABLE registration(p0 TEXT);");
            QSqlQuery createTablexp1("ALTER TABLE registration ADD p1 TEXT;");
            QSqlQuery createTablexp2("ALTER TABLE registration ADD p2 TEXT;");
            QSqlQuery createTablexp3("ALTER TABLE registration ADD p3 TEXT;");
            QSqlQuery createTablexp4("ALTER TABLE registration ADD p4 TEXT;");
            QSqlQuery createTablexp5("ALTER TABLE registration ADD p5 TEXT;");
            QSqlQuery createTablexp6("ALTER TABLE registration ADD p6 TEXT;");
            QSqlQuery createTablexp7("ALTER TABLE registration ADD p7 TEXT;");
            QSqlQuery createTablexp8("ALTER TABLE registration ADD p8 TEXT;");
            QSqlQuery createTablexp9("ALTER TABLE registration ADD p9 TEXT;");
            QSqlQuery createTablexp10("ALTER TABLE registration ADD p10 TEXT;");
            QSqlQuery createTablexp11("ALTER TABLE registration ADD p11 TEXT;");
            QSqlQuery createTablexp12("ALTER TABLE registration ADD p12 TEXT;");
            QSqlQuery createTablexp13("ALTER TABLE registration ADD p13 TEXT;");
            QSqlQuery createTablexp14("ALTER TABLE registration ADD p14 TEXT;");
            QSqlQuery createTablexp15("ALTER TABLE registration ADD p15 TEXT;");
            QSqlQuery createTablexp16("ALTER TABLE registration ADD p16 TEXT;");
            QSqlQuery createTablexp17("ALTER TABLE registration ADD p17 TEXT;");
            QSqlQuery createTabuiylex("ALTER TABLE registration ADD p18 TEXT;");
            QSqlQuery createTablpex("ALTER TABLE registration ADD p19 TEXT;");
            QSqlQuery createTabuiylpex("ALTER TABLE registration ADD p20 TEXT;");
            QSqlQuery createTablupex("ALTER TABLE registration ADD p21 TEXT;");
            QSqlQuery createTabluypex("ALTER TABLE registration ADD p22 TEXT;");
            QSqlQuery createTabluyypex("ALTER TABLE registration ADD p23 TEXT;");
            QSqlQuery createTabliypex("ALTER TABLE registration ADD p24 TEXT;");
            QSqlQuery createTablppex("ALTER TABLE registration ADD p25 TEXT;");
            QSqlQuery createTaytrblepx("ALTER TABLE registration ADD p26 TEXT;");
            QSqlQuery createTa2blex("ALTER TABLE registration ADD p27 TEXT;");
            QSqlQuery creatrteTablex("ALTER TABLE registration ADD p28 TEXT;");
            QSqlQuery creathrteTablex("ALTER TABLE registration ADD p29 TEXT;");
            QSqlQuery createTablexe("ALTER TABLE registration ADD p30 TEXT;");

            //--------------end of registreation auto creator
        }
        else
        {
            QMessageBox ::critical (this," " , "اتصال به پایگاه داده ساخته شده انجام نشد !");
            this->close();
        }
    }

    //end create TABLES to HS.db
    QDir check_dire_avatar("./avatar");
    if(check_dire_avatar.exists())
    {
        //nothing..
    }
    else
    {
        QMessageBox::information(this," ","مسیری برای تصاویر یافت نشد"
                                          "\n"
                                          "درحال ساخت مسیر...");
        check_dire_avatar.mkpath(".");
        check_dire_avatar.mkdir("../avatar/defualt");
    }




    //    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //    db.setHostName("localhost");
    //    db.setDatabaseName("hs");
    //    db.setUserName("root");
    //    db.setPassword("toor8");
    if(db.open())
    {
        //give title text from database
        QSqlQuery q_give_title("SELECT * FROM adminconfig;");
        QString title_text;
        while(q_give_title.next())
        {
            title_text = q_give_title.value("window_title").toString();
        }
        this->setWindowTitle(title_text); //+" "+verion_app



        //set title to headers
        QSqlQuery q_guve("SELECT * FROM headers;");
        while(q_guve.next())
        {
           ui->tableWidget_search_result->setHorizontalHeaderLabels(QString(q_guve.value("sr0").toString()+";"+q_guve.value("sr1").toString()+";"+q_guve.value("sr2").toString()+";"+q_guve.value("sr3").toString()+";").split(";"));
           ui->tableWidget_class_list->setHorizontalHeaderLabels(QString(q_guve.value("cl0").toString()+";"+q_guve.value("cl1").toString()+";"+q_guve.value("cl2").toString()+";"+q_guve.value("cl3").toString()+";"+q_guve.value("cl4").toString()+";"+q_guve.value("cl5").toString()+";"+q_guve.value("cl6").toString()+";"+q_guve.value("cl7").toString()+";"+q_guve.value("cl8").toString()+";"+q_guve.value("cl9").toString()+";"+q_guve.value("cl10").toString()+";"+q_guve.value("cl11").toString()+";"+q_guve.value("cl12").toString()+";"+q_guve.value("cl13").toString()+";"+q_guve.value("cl14").toString()+";"+q_guve.value("cl15").toString()+";").split(";"));
           ui->tableWidget_search_class_result->setHorizontalHeaderLabels(QString(q_guve.value("src0").toString()+";"+q_guve.value("src1").toString()+";"+q_guve.value("src2").toString()+";"+q_guve.value("src3").toString()+";").split(";"));
           ui->tableWidget_show_student_scores->setHorizontalHeaderLabels(QString(q_guve.value("s0").toString()+";"+q_guve.value("s1").toString()+";"+q_guve.value("s2").toString()+";"+q_guve.value("s3").toString()+";"+q_guve.value("s4").toString()+";"+q_guve.value("s5").toString()+";"+q_guve.value("s6").toString()+";"+q_guve.value("s7").toString()+";"+q_guve.value("s8").toString()+";"+q_guve.value("s9").toString()+";"+q_guve.value("s10").toString()+";"+q_guve.value("s11").toString()+";"+q_guve.value("s12").toString()+";"+q_guve.value("s13").toString()+";"+q_guve.value("s14").toString()+";"+q_guve.value("s15").toString()+";"+q_guve.value("s16").toString()+";"+q_guve.value("s17").toString()+";"+q_guve.value("s18").toString()+";"+q_guve.value("s19").toString()+";"+q_guve.value("s20").toString()+";"+q_guve.value("s21").toString()+";"+q_guve.value("s22").toString()+";"+q_guve.value("s23").toString()+";"+q_guve.value("s24").toString()+";"+q_guve.value("s25").toString()+";"+q_guve.value("s26").toString()+";"+q_guve.value("s27").toString()+";"+q_guve.value("s28").toString()+";"+q_guve.value("s29").toString()+";").split(";"));
        }




        ui->groupBox_login->show();
        ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
        ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->hide();    ui->groupBox_settings->hide();

        //other
        ui->groupBox_change_userpass_admin->hide();
        ui->groupBox_maxtry_change->hide();
        ui->groupBox_currenttry_change->hide();
        ui->groupBox_avatar_path_change->hide();
        ui->groupBox_history_of_admin_logins_log->hide();
        ui->groupBox_send_cmd_to_db->hide();
        ui->groupBox_db_backup_config->hide();
        ui->groupBox_search_hs_users->hide();

    }
    else
    {
        QMessageBox ::critical (this,"خطا" ,"اتصال به پایگاه داده انجام نشد.");
        this->close();
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_register_clear_clicked()
{
    ui->scrollArea_register->ensureVisible(0,0,0,0);
    if(ui->btn_register_clear->text() == "انصراف")
    {
        ui->groupBox_hs_register->hide();
        ui->groupBox_hs_search_for_edit->hide();
        ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
        ui->txt_register_0->setToolTip("");  ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
        ui->groupBox_hs_register->setTitle("فرم ثبت نام عضو جدید در حسینیه");
        ui->btn_register_insert->setText("ثبت"); //ui->btn_register_clear->setText("تنظیم مجدد");
        ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
        ui->groupBox_hs_register->hide();
        ui->groupBox_home->show();
    }
    else
    {
        QMessageBox::critical(this,"","error code1");
        //if want to back and make button clear/reset everything from form . use down code and idcode(codr1)
        // ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
    }

}

void MainWindow::on_btn_register_insert_clicked()
{
    ui->scrollArea_register->ensureVisible(0,0,0,0);
    if(ui->txt_register_0->text() == "" || (ui->txt_register_1->text() == "" && ui->txt_register_2->text()==""))
    {
        QMessageBox ::warning(this,"خطا" ," فیلد ها اصلی خالی است‌‌ !!");//یکی از
    }
    else if(ui->txt_register_0->text().size() < 10 || ui->txt_register_0->text().size() > 10)
    {
        QMessageBox ::warning(this,"خطا" ,"‌‌\n"
                                          "کدملی باید 10رقم باشد.");

    }


    else
    {
        if(ui->groupBox_hs_register->title() == "فرم ثبت نام دانش آموز جدید")
        {
            if(avatar_url == "" || avatar_url == " " || avatar_url.size()<1)
            {
                QSqlQuery q_search_def_user_avatar("SELECT * FROM adminconfig;");
                while(q_search_def_user_avatar.next())
                {                avatar_url = q_search_def_user_avatar.value("defualt_avatar").toString();

                }
            }

            QSqlQuery q_student_Register("INSERT INTO students (p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30) VALUES ('"+ui->txt_register_0->text()+"','"+ui->txt_register_1->text()+"','"+ui->txt_register_2->text()+"','"+ui->txt_register_3->text()+"','"+ui->txt_register_4->text()+"','"+ui->txt_register_5->text()+"','"+ui->txt_register_6->text()+"','"+ui->txt_register_7->text()+"','"+ui->txt_register_8->text()+"','"+ui->txt_register_9->text()+"','"+ui->txt_register_10->text()+"','"+ui->txt_register_11->text()+"','"+ui->txt_register_12->text()+"','"+ui->txt_register_13->text()+"','"+ui->txt_register_14->text()+"','"+ui->txt_register_15->text()+"','"+ui->txt_register_16->text()+"','"+ui->txt_register_17->text()+"','"+ui->txt_register_18->text()+"','"+ui->txt_register_19->text()+"','"+ui->txt_register_20->text()+"','"+ui->txt_register_21->text()+"','"+ui->txt_register_22->text()+"','"+ui->txt_register_23->text()+"','"+ui->txt_register_24->text()+"','"+ui->txt_register_25->text()+"','"+ui->txt_register_26->text()+"','"+ui->txt_register_27->text()+"','"+ui->txt_register_28->text()+"','"+ui->txt_register_29->text()+"','"+avatar_url+"');");
            //            QSqlQuery q_save_new_student("INSERT INTO students (`p0`,`p1`,`p2`,`p3`,`p4`,`p5`,`p6`,`p7`,`p8`,`p9`,`p10`,`p11`,`p12`,`p13`,`p14`,`p15`,`p16`,`p17`,`p18`,`p19`,`p20`,`p21`,`p22`,`p23`,`p24`,`p25`,`p26`,`p27`,`p28`,`p29`,`p30`) VALUES ('"+ui->txt_register_0->text()+"','"+ui->txt_register_1->text()+"','"+ui->txt_register_2->text()+"','"+ui->txt_register_3->text()+"','"+ui->txt_register_4->text()+"','"+ui->txt_register_5->text()+"','"+ui->txt_register_6->text()+"','"+ui->txt_register_7->text()+"','"+ui->txt_register_8->text()+"','"+ui->txt_register_9->text()+"','"+ui->txt_register_10->text()+"','"+ui->txt_register_11->text()+"','"+ui->txt_register_12->text()+"','"+ui->txt_register_13->text()+"','"+ui->txt_register_14->text()+"','"+ui->txt_register_15->text()+"','"+ui->txt_register_16->text()+"','"+ui->txt_register_17->text()+"','"+ui->txt_register_18->text()+"','"+ui->txt_register_19->text()+"','"+ui->txt_register_20->text()+"','"+ui->txt_register_21->text()+"','"+ui->txt_register_22->text()+"','"+ui->txt_register_23->text()+"','"+ui->txt_register_24->text()+"','"+ui->txt_register_25->text()+"','"+ui->txt_register_26->text()+"','"+ui->txt_register_27->text()+"','"+ui->txt_register_28->text()+"','"+ui->txt_register_29->text()+"','"+avatar_url+"');");
            avatar_url = "";
            QMessageBox::information(this," ","اطلاعات دانش آموز با موفقیت ثبت شد و تاپایان ساخت جدول نمره این دانش آموز صبر کنید");
            QSqlQuery q_create_tbl_score("CREATE TABLE score_"+ui->txt_register_0->text()+" (p0 TEXT);");
            QSqlQuery q_alter_table_score("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p1 TEXT;");
            QSqlQuery q_alter_table_score1("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p2 TEXT;");
            QSqlQuery q_alter_table_score2("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p3 TEXT;");
            QSqlQuery q_alter_table_score3("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p4 TEXT;");
            QSqlQuery q_alter_table_score4("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p5 TEXT;");
            QSqlQuery q_alter_table_score5("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p6 TEXT;");
            QSqlQuery q_alter_table_score6("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p7 TEXT;");
            QSqlQuery q_alter_table_score7("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p8 TEXT;");
            QSqlQuery q_alter_table_score8("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p9 TEXT;");
            QSqlQuery q_alter_table_score9("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p10 TEXT;");
            QSqlQuery q_alter_table_score10("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p11 TEXT;");
            QSqlQuery q_alter_table_score11("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p12 TEXT;");
            QSqlQuery q_alter_table_score12("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p13 TEXT;");
            QSqlQuery q_alter_table_score13("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p14 TEXT;");
            QSqlQuery q_alter_table_score14("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p15 TEXT;");
            QSqlQuery q_alter_table_score15("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p16 TEXT;");
            QSqlQuery q_alter_table_score16("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p17 TEXT;");
            QSqlQuery q_alter_table_score17("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p18 TEXT;");
            QSqlQuery q_alter_table_score18("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p19 TEXT;");
            QSqlQuery q_alter_table_score19("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p20 TEXT;");
            QSqlQuery q_alter_table_score20("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p21 TEXT;");
            QSqlQuery q_alter_table_score21("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p22 TEXT;");
            QSqlQuery q_alter_table_score22("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p23 TEXT;");
            QSqlQuery q_alter_table_score23("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p24 TEXT;");
            QSqlQuery q_alter_table_score24("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p25 TEXT;");
            QSqlQuery q_alter_table_score25("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p26 TEXT;");
            QSqlQuery q_alter_table_score26("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p27 TEXT;");
            QSqlQuery q_alter_table_score27("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p28 TEXT;");
            QSqlQuery q_alter_table_score28("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p29 TEXT;");
            QSqlQuery q_alter_table_score29("ALTER TABLE score_"+ui->txt_register_0->text()+" ADD p30 TEXT;");
            QMessageBox::information(this," ","دانش آموز با موفیقت ساخته شد");
            ui->groupBox_hs_register->hide();
            ui->groupBox_home->show();

        }
        else if(ui->groupBox_hs_register->title() == "فرم ویرایش دانش اموز")
        {
            if(avatar_url == "" || avatar_url == " " || avatar_url.size()<1)
            {
                QSqlQuery q_search_def_user_avatar("SELECT * FROM adminconfig;");
                while(q_search_def_user_avatar.next())
                {                avatar_url = q_search_def_user_avatar.value("defualt_avatar").toString();

                }
            }

            QSqlQuery q_update_data_to_student("UPDATE students SET p0='"+ui->txt_register_0->text()+"',p1='"+ui->txt_register_1->text()+"',p2='"+ui->txt_register_2->text()+"',p3='"+ui->txt_register_3->text()+"',p4='"+ui->txt_register_4->text()+"',p5='"+ui->txt_register_5->text()+"',p6='"+ui->txt_register_6->text()+"',p7='"+ui->txt_register_7->text()+"',p8='"+ui->txt_register_8->text()+"',p9='"+ui->txt_register_9->text()+"',p10='"+ui->txt_register_10->text()+"',p11='"+ui->txt_register_11->text()+"',p12='"+ui->txt_register_12->text()+"',p13='"+ui->txt_register_13->text()+"',p14='"+ui->txt_register_14->text()+"',p15='"+ui->txt_register_15->text()+"',p16='"+ui->txt_register_16->text()+"',p17='"+ui->txt_register_17->text()+"',p18='"+ui->txt_register_18->text()+"',p19='"+ui->txt_register_19->text()+"',p20='"+ui->txt_register_20->text()+"',p21='"+ui->txt_register_21->text()+"',p22='"+ui->txt_register_22->text()+"',p23='"+ui->txt_register_23->text()+"',p24='"+ui->txt_register_24->text()+"',p25='"+ui->txt_register_25->text()+"',p26='"+ui->txt_register_26->text()+"',p27='"+ui->txt_register_27->text()+"',p28='"+ui->txt_register_28->text()+"',p29='"+ui->txt_register_29->text()+"',p30='"+avatar_url+"' WHERE p0='"+ui->txt_register_0->text()+"';");
            avatar_url = "";
            ui->groupBox_hs_register->hide();
            ui->groupBox_home->show();
            QMessageBox::information(this,"توجه",
                                     "ویرایش کاربر "+ui->txt_register_1->text() +
                                     "  "
                                     + ui->txt_register_2->text()+
                                     "  "+ui->txt_register_0->text()+"  "
                                     +"با موفقیت انجام شد.");


            //here will add code for other......
        }
        else if(ui->groupBox_hs_register->title()== "فرم ویرایش اعضای حسینیه")
        {
            //add button drop/delete this user..


            if(edit_search_name_and_family == true)
            {
                QSqlQuery q_Hs_Modify_userxx("UPDATE registration SET p0='"+ui->txt_register_0->text()+"',p1='"+ui->txt_register_1->text()+"',p3='"+ui->txt_register_3->text()+"',p4='"+ui->txt_register_4->text()+"',p5='"+ui->txt_register_5->text()+"',p6='"+ui->txt_register_6->text()+"',p7='"+ui->txt_register_7->text()+"',p8='"+ui->txt_register_8->text()+"',p9='"+ui->txt_register_9->text()+"',p10='"+ui->txt_register_10->text()+"',p11='"+ui->txt_register_11->text()+"',p12='"+ui->txt_register_12->text()+"',p13='"+ui->txt_register_13->text()+"',p14='"+ui->txt_register_14->text()+"',p15='"+ui->txt_register_15->text()+"',p16='"+ui->txt_register_16->text()+"',p17='"+ui->txt_register_17->text()+"',p18='"+ui->txt_register_18->text()+"',p19='"+ui->txt_register_19->text()+"',p20='"+ui->txt_register_20->text()+"',p21='"+ui->txt_register_21->text()+"',p22='"+ui->txt_register_22->text()+"',p23='"+ui->txt_register_23->text()+"',p24='"+ui->txt_register_24->text()+"',p25='"+ui->txt_register_25->text()+"',p26='"+ui->txt_register_26->text()+"',p27='"+ui->txt_register_27->text()+"',p28='"+ui->txt_register_28->text()+"',p29='"+ui->txt_register_29->text()+"',p30='"+avatar_url+"' WHERE p1='"+tmp1+"' AND p2='"+tmp2+"';");
                if(QFileInfo(avatar_url).exists())
                {
                    if(avatar_url == "./avatar/"+for_rename_avatar_lastusername_is_here+avatar_format)
                    {
                        //do nothing..
                    }
                    else
                    {
                        const QString this_is_new_url_avatar_user_will_be_save = "./avatar/"+ui->txt_register_0->text()+avatar_format;
                        //for_rename_avatar_lastusername_is_here
                        //QStringRef this_is_unknoww = this_is_new_url_avatar_user_will_be_save.rightRef(13);
                        //this_is_unknoww = this_is_new_url_avatar_user_will_be_save.leftRef(10);
                        QFile::rename(avatar_url,"./avatar/"+ui->txt_register_0->text()+avatar_format);
                        QSqlQuery user_avatar_has_been_renamed("UPDATE registration SET p30='"+this_is_new_url_avatar_user_will_be_save+"' WHERE p0='"+ui->txt_register_0->text()+"'");
                    }
                }
                for_rename_avatar_lastusername_is_here = "";
                QMessageBox::information(this,"توجه",
                                         "ویرایش کاربر "+ui->txt_register_1->text() +
                                         "  "
                                         + ui->txt_register_2->text()+
                                         "  "+ui->txt_register_0->text()+"  "
                                         +"با موفقیت انجام شد.");

                //remove everything from form registeration
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
                family=""; name=""; code="";
                editParameter=""; avatar_url="";
                edit_search_name_and_family = false;
                edit_search_code_and_name_and_family = false;
                edit_search_code_and_name = false;
                edit_search_code_and_family = false;
                stats_check_code_user= false;
                edit_user_coming_from_userinfo_btn =false;
                tmp1="";tmp2="";tmp3="";
                //back to main window slide ..
                ui->groupBox_hs_register->hide();
                ui->groupBox_hs_search_for_edit->hide();
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip("");  ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg

                ui->groupBox_home->show();
            }
            else if(edit_user_coming_from_userinfo_btn == true)
            {
                QSqlQuery q_Hs_Modify_userxx("UPDATE registration SET p1='"+ui->txt_register_1->text()+"',p2='"+ui->txt_register_2->text()+"',p3='"+ui->txt_register_3->text()+"',p4='"+ui->txt_register_4->text()+"',p5='"+ui->txt_register_5->text()+"',p6='"+ui->txt_register_6->text()+"',p7='"+ui->txt_register_7->text()+"',p8='"+ui->txt_register_8->text()+"',p9='"+ui->txt_register_9->text()+"',p10='"+ui->txt_register_10->text()+"',p11='"+ui->txt_register_11->text()+"',p12='"+ui->txt_register_12->text()+"',p13='"+ui->txt_register_13->text()+"',p14='"+ui->txt_register_14->text()+"',p15='"+ui->txt_register_15->text()+"',p16='"+ui->txt_register_16->text()+"',p17='"+ui->txt_register_17->text()+"',p18='"+ui->txt_register_18->text()+"',p19='"+ui->txt_register_19->text()+"',p20='"+ui->txt_register_20->text()+"',p21='"+ui->txt_register_21->text()+"',p22='"+ui->txt_register_22->text()+"',p23='"+ui->txt_register_23->text()+"',p24='"+ui->txt_register_24->text()+"',p25='"+ui->txt_register_25->text()+"',p26='"+ui->txt_register_26->text()+"',p27='"+ui->txt_register_27->text()+"',p28='"+ui->txt_register_28->text()+"',p29='"+ui->txt_register_29->text()+"',p30='"+avatar_url+"' WHERE p0='"+ui->lbl_hs_userinfo_p0->text()+"';");
                if(QFileInfo(avatar_url).exists())
                {
                    if(avatar_url == "./avatar/"+for_rename_avatar_lastusername_is_here+avatar_format)
                    {
                        //do nothing..
                    }
                    else
                    {
                        const QString this_is_new_url_avatar_user_will_be_save = "./avatar/"+ui->txt_register_0->text()+avatar_format;
                        //for_rename_avatar_lastusername_is_here
                        //QStringRef this_is_unknoww = this_is_new_url_avatar_user_will_be_save.rightRef(13);
                        //this_is_unknoww = this_is_new_url_avatar_user_will_be_save.leftRef(10);
                        QFile::rename(avatar_url,"./avatar/"+ui->txt_register_0->text()+avatar_format);
                        QSqlQuery user_avatar_has_been_renamed("UPDATE registration SET p30='"+this_is_new_url_avatar_user_will_be_save+"' WHERE p0='"+ui->txt_register_0->text()+"'");
                    }
                }
                for_rename_avatar_lastusername_is_here = "";
                QMessageBox::information(this,"توجه",
                                         "ویرایش کاربر "+ui->txt_register_1->text() +
                                         "  "
                                         + ui->txt_register_2->text()+
                                         "  "+ui->txt_register_0->text()+"  "
                                         +"با موفقیت انجام شد.");
                //remove everything from form registeration
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
                family=""; name=""; code="";
                editParameter=""; avatar_url="";
                edit_search_name_and_family = false;
                edit_search_code_and_name_and_family = false;
                edit_search_code_and_name = false;
                edit_search_code_and_family = false;
                stats_check_code_user= false;
                edit_user_coming_from_userinfo_btn =false;
                tmp1="";tmp2="";tmp3="";
                //back to main window slide ..
                ui->groupBox_hs_register->hide();
                ui->groupBox_hs_search_for_edit->hide();
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip("");  ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg

                ui->groupBox_home->show();
            }
            else if(edit_search_code_and_name_and_family == true)
            {
                QSqlQuery q_Hs_Modify_userxx("UPDATE registration SET p0='"+ui->txt_register_0->text()+"',p1='"+ui->txt_register_1->text()+"',p3='"+ui->txt_register_3->text()+"',p4='"+ui->txt_register_4->text()+"',p5='"+ui->txt_register_5->text()+"',p6='"+ui->txt_register_6->text()+"',p7='"+ui->txt_register_7->text()+"',p8='"+ui->txt_register_8->text()+"',p9='"+ui->txt_register_9->text()+"',p10='"+ui->txt_register_10->text()+"',p11='"+ui->txt_register_11->text()+"',p12='"+ui->txt_register_12->text()+"',p13='"+ui->txt_register_13->text()+"',p14='"+ui->txt_register_14->text()+"',p15='"+ui->txt_register_15->text()+"',p16='"+ui->txt_register_16->text()+"',p17='"+ui->txt_register_17->text()+"',p18='"+ui->txt_register_18->text()+"',p19='"+ui->txt_register_19->text()+"',p20='"+ui->txt_register_20->text()+"',p21='"+ui->txt_register_21->text()+"',p22='"+ui->txt_register_22->text()+"',p23='"+ui->txt_register_23->text()+"',p24='"+ui->txt_register_24->text()+"',p25='"+ui->txt_register_25->text()+"',p26='"+ui->txt_register_26->text()+"',p27='"+ui->txt_register_27->text()+"',p28='"+ui->txt_register_28->text()+"',p29='"+ui->txt_register_29->text()+"',p30='"+avatar_url+"' WHERE p1='"+tmp1+"' AND p2='"+tmp2+"' AND p3='"+tmp3+"';");
                if(QFileInfo(avatar_url).exists())
                {
                    if(avatar_url == "./avatar/"+for_rename_avatar_lastusername_is_here+avatar_format)
                    {
                        //do nothing..
                    }
                    else
                    {
                        const QString this_is_new_url_avatar_user_will_be_save = "./avatar/"+ui->txt_register_0->text()+avatar_format;
                        //for_rename_avatar_lastusername_is_here
                        //QStringRef this_is_unknoww = this_is_new_url_avatar_user_will_be_save.rightRef(13);
                        //this_is_unknoww = this_is_new_url_avatar_user_will_be_save.leftRef(10);
                        QFile::rename(avatar_url,"./avatar/"+ui->txt_register_0->text()+avatar_format);
                        QSqlQuery user_avatar_has_been_renamed("UPDATE registration SET p30='"+this_is_new_url_avatar_user_will_be_save+"' WHERE p0='"+ui->txt_register_0->text()+"'");
                    }
                }
                for_rename_avatar_lastusername_is_here = "";
                QMessageBox::information(this,"توجه",
                                         "ویرایش کاربر "+ui->txt_register_1->text() +
                                         "  "
                                         + ui->txt_register_2->text()+
                                         "  "+ui->txt_register_0->text()+"  "
                                         +"با موفقیت انجام شد.");
                //remove everything from form registeration
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
                family=""; name=""; code="";
                editParameter=""; avatar_url="";
                edit_search_name_and_family = false;
                edit_search_code_and_name_and_family = false;
                edit_search_code_and_name = false;
                edit_search_code_and_family = false;
                stats_check_code_user= false;
                edit_user_coming_from_userinfo_btn =false;
                tmp1="";tmp2="";tmp3="";
                //back to main window slide ..
                ui->groupBox_hs_register->hide();
                ui->groupBox_hs_search_for_edit->hide();
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip("");  ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg

                ui->groupBox_home->show();

            }
            else if(edit_search_code_and_name==true)
            {                                                       //
                QSqlQuery q_Hs_Modify_userxx("UPDATE registration SET p0='"+ui->txt_register_0->text()+"',p1='"+ui->txt_register_1->text()+"',p3='"+ui->txt_register_3->text()+"',p4='"+ui->txt_register_4->text()+"',p5='"+ui->txt_register_5->text()+"',p6='"+ui->txt_register_6->text()+"',p7='"+ui->txt_register_7->text()+"',p8='"+ui->txt_register_8->text()+"',p9='"+ui->txt_register_9->text()+"',p10='"+ui->txt_register_10->text()+"',p11='"+ui->txt_register_11->text()+"',p12='"+ui->txt_register_12->text()+"',p13='"+ui->txt_register_13->text()+"',p14='"+ui->txt_register_14->text()+"',p15='"+ui->txt_register_15->text()+"',p16='"+ui->txt_register_16->text()+"',p17='"+ui->txt_register_17->text()+"',p18='"+ui->txt_register_18->text()+"',p19='"+ui->txt_register_19->text()+"',p20='"+ui->txt_register_20->text()+"',p21='"+ui->txt_register_21->text()+"',p22='"+ui->txt_register_22->text()+"',p23='"+ui->txt_register_23->text()+"',p24='"+ui->txt_register_24->text()+"',p25='"+ui->txt_register_25->text()+"',p26='"+ui->txt_register_26->text()+"',p27='"+ui->txt_register_27->text()+"',p28='"+ui->txt_register_28->text()+"',p29='"+ui->txt_register_29->text()+"',p30='"+avatar_url+"' WHERE p0='"+tmp1+"' AND p1='"+tmp2+"';");
                if(QFileInfo(avatar_url).exists())
                {
                    if(avatar_url == "./avatar/"+for_rename_avatar_lastusername_is_here+avatar_format)
                    {
                        //do nothing..
                    }
                    else
                    {
                        const QString this_is_new_url_avatar_user_will_be_save = "./avatar/"+ui->txt_register_0->text()+avatar_format;
                        //for_rename_avatar_lastusername_is_here
                        //QStringRef this_is_unknoww = this_is_new_url_avatar_user_will_be_save.rightRef(13);
                        //this_is_unknoww = this_is_new_url_avatar_user_will_be_save.leftRef(10);
                        QFile::rename(avatar_url,"./avatar/"+ui->txt_register_0->text()+avatar_format);
                        QSqlQuery user_avatar_has_been_renamed("UPDATE registration SET p30='"+this_is_new_url_avatar_user_will_be_save+"' WHERE p0='"+ui->txt_register_0->text()+"'");
                    }
                }
                for_rename_avatar_lastusername_is_here = "";
                QMessageBox::information(this,"توجه",
                                         "ویرایش کاربر "+ui->txt_register_1->text() +
                                         "  "
                                         + ui->txt_register_2->text()+
                                         "  "+ui->txt_register_0->text()+"  "
                                         +"با موفقیت انجام شد.");
                //remove everything from form registeration
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
                family=""; name=""; code="";
                editParameter=""; avatar_url="";
                edit_search_name_and_family = false;
                edit_search_code_and_name_and_family = false;
                edit_search_code_and_name = false;
                edit_search_code_and_family = false;
                edit_user_coming_from_userinfo_btn =false;
                stats_check_code_user= false;
                tmp1="";tmp2="";tmp3="";
                //back to main window slide ..
                ui->groupBox_hs_register->hide();
                ui->groupBox_hs_search_for_edit->hide();
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip("");  ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg

                ui->groupBox_home->show();
            }
            else if(edit_search_code_and_family==true)
            {

                QSqlQuery q_Hs_Modify_userxx("UPDATE registration SET p0='"+ui->txt_register_0->text()+"',p1='"+ui->txt_register_1->text()+"',p3='"+ui->txt_register_3->text()+"',p4='"+ui->txt_register_4->text()+"',p5='"+ui->txt_register_5->text()+"',p6='"+ui->txt_register_6->text()+"',p7='"+ui->txt_register_7->text()+"',p8='"+ui->txt_register_8->text()+"',p9='"+ui->txt_register_9->text()+"',p10='"+ui->txt_register_10->text()+"',p11='"+ui->txt_register_11->text()+"',p12='"+ui->txt_register_12->text()+"',p13='"+ui->txt_register_13->text()+"',p14='"+ui->txt_register_14->text()+"',p15='"+ui->txt_register_15->text()+"',p16='"+ui->txt_register_16->text()+"',p17='"+ui->txt_register_17->text()+"',p18='"+ui->txt_register_18->text()+"',p19='"+ui->txt_register_19->text()+"',p20='"+ui->txt_register_20->text()+"',p21='"+ui->txt_register_21->text()+"',p22='"+ui->txt_register_22->text()+"',p23='"+ui->txt_register_23->text()+"',p24='"+ui->txt_register_24->text()+"',p25='"+ui->txt_register_25->text()+"',p26='"+ui->txt_register_26->text()+"',p27='"+ui->txt_register_27->text()+"',p28='"+ui->txt_register_28->text()+"',p29='"+ui->txt_register_29->text()+"',p30='"+avatar_url+"' WHERE p0='"+tmp1+"' AND p2='"+tmp2+"';");
                if(QFileInfo(avatar_url).exists())
                {
                    if(avatar_url == "./avatar/"+for_rename_avatar_lastusername_is_here+avatar_format)
                    {
                        //do nothing..
                    }
                    else
                    {
                        const QString this_is_new_url_avatar_user_will_be_save = "./avatar/"+ui->txt_register_0->text()+avatar_format;
                        //for_rename_avatar_lastusername_is_here
                        //QStringRef this_is_unknoww = this_is_new_url_avatar_user_will_be_save.rightRef(13);
                        //this_is_unknoww = this_is_new_url_avatar_user_will_be_save.leftRef(10);
                        QFile::rename(avatar_url,"./avatar/"+ui->txt_register_0->text()+avatar_format);
                        QSqlQuery user_avatar_has_been_renamed("UPDATE registration SET p30='"+this_is_new_url_avatar_user_will_be_save+"' WHERE p0='"+ui->txt_register_0->text()+"'");
                    }
                }
                for_rename_avatar_lastusername_is_here = "";
                QMessageBox::information(this,"توجه",
                                         "ویرایش کاربر "+ui->txt_register_1->text() +
                                         "  "
                                         + ui->txt_register_2->text()+
                                         "  "+ui->txt_register_0->text()+"  "
                                         +"با موفقیت انجام شد.");
                //remove everything from form registeration
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
                family=""; name=""; code="";
                editParameter=""; avatar_url="";
                edit_search_name_and_family = false;
                edit_search_code_and_name_and_family = false;
                edit_search_code_and_name = false;
                edit_search_code_and_family = false;
                edit_user_coming_from_userinfo_btn =false;
                stats_check_code_user= false;
                tmp1="";tmp2="";tmp3="";
                //back to main window slide ..
                ui->groupBox_hs_register->hide();
                ui->groupBox_hs_search_for_edit->hide();
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip("");  ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                ui->groupBox_home->show();

            }
            else
            {
                QSqlQuery q_Hs_Modify_userxx("UPDATE registration SET p0='"+ui->txt_register_0->text()+"',p1='"+ui->txt_register_1->text()+"',p2='"+ui->txt_register_2->text()+"',p3='"+ui->txt_register_3->text()+"',p4='"+ui->txt_register_4->text()+"',p5='"+ui->txt_register_5->text()+"',p6='"+ui->txt_register_6->text()+"',p7='"+ui->txt_register_7->text()+"',p8='"+ui->txt_register_8->text()+"',p9='"+ui->txt_register_9->text()+"',p10='"+ui->txt_register_10->text()+"',p11='"+ui->txt_register_11->text()+"',p12='"+ui->txt_register_12->text()+"',p13='"+ui->txt_register_13->text()+"',p14='"+ui->txt_register_14->text()+"',p15='"+ui->txt_register_15->text()+"',p16='"+ui->txt_register_16->text()+"',p17='"+ui->txt_register_17->text()+"',p18='"+ui->txt_register_18->text()+"',p19='"+ui->txt_register_19->text()+"',p20='"+ui->txt_register_20->text()+"',p21='"+ui->txt_register_21->text()+"',p22='"+ui->txt_register_22->text()+"',p23='"+ui->txt_register_23->text()+"',p24='"+ui->txt_register_24->text()+"',p25='"+ui->txt_register_25->text()+"',p26='"+ui->txt_register_26->text()+"',p27='"+ui->txt_register_27->text()+"',p28='"+ui->txt_register_28->text()+"',p29='"+ui->txt_register_29->text()+"',p30='"+avatar_url+"' WHERE "+editParameter+"='"+*editVar+"';");
                if(QFileInfo(avatar_url).exists())
                {
                    if(avatar_url == "./avatar/"+for_rename_avatar_lastusername_is_here+avatar_format)
                    {
                        //do nothing..
                    }
                    else
                    {
                        const QString this_is_new_url_avatar_user_will_be_save = "./avatar/"+ui->txt_register_0->text()+avatar_format;
                        //for_rename_avatar_lastusername_is_here
                        //QStringRef this_is_unknoww = this_is_new_url_avatar_user_will_be_save.rightRef(13);
                        //this_is_unknoww = this_is_new_url_avatar_user_will_be_save.leftRef(10);
                        QFile::rename(avatar_url,"./avatar/"+ui->txt_register_0->text()+avatar_format);
                        QSqlQuery user_avatar_has_been_renamed("UPDATE registration SET p30='"+this_is_new_url_avatar_user_will_be_save+"' WHERE p0='"+ui->txt_register_0->text()+"'");
                    }
                }
                for_rename_avatar_lastusername_is_here = "";
                QMessageBox::information(this,"توجه",
                                         "ویرایش کاربر "+ui->txt_register_1->text() +
                                         "  "
                                         + ui->txt_register_2->text()+
                                         "  "+ui->txt_register_0->text()+"  "
                                         +"با موفقیت انجام شد.");
                //ui->groupBox_hs_search_for_edit->hide();
                //remove everything from form registeration
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
                family=""; name=""; code="";
                editParameter=""; avatar_url="";
                edit_search_name_and_family = false;
                edit_search_code_and_name_and_family = false;
                edit_search_code_and_name = false;
                edit_search_code_and_family = false;
                stats_check_code_user= false;
                edit_user_coming_from_userinfo_btn =false;
                tmp1="";tmp2="";tmp3="";
                //back to main window slide ..
                ui->groupBox_hs_register->hide();
                ui->groupBox_hs_search_for_edit->hide();
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip("");  ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                ui->groupBox_home->show();
            }
        }
        else
        {
            if(avatar_url == "" || avatar_url == " " || avatar_url.size()<1)
            {
                QSqlQuery q_search_def_user_avatar("SELECT * FROM adminconfig;");
                while(q_search_def_user_avatar.next())
                {                avatar_url = q_search_def_user_avatar.value("defualt_avatar").toString();

                }

            }
            QString usercodeisexist;
            QSqlQuery q_hs_register_give_user_code("SELECT * FROM registration WHERE p0='"+ui->txt_register_0->text()+"';");
            while(q_hs_register_give_user_code.next())
            {
                usercodeisexist =  q_hs_register_give_user_code.value("p0").toString();
            }
            if(usercodeisexist == ui->txt_register_0->text())
            {
                QMessageBox::critical(this," ", "کاربری با همین کدملی ثبت شده است\n"
                                                "لطفا کدملی درست را وارد کنید \n"
                                                "یا به ویرایش کاربر با کدملی:"
                                      +ui->txt_register_0->text()+ "  "
                                                                   "اقدام فرمایید. ");
            }
            else
            {
                QSqlQuery q_Hs_Register_user("INSERT INTO registration (p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30) VALUES ('"+ui->txt_register_0->text()+"','"+ui->txt_register_1->text()+"','"+ui->txt_register_2->text()+"','"+ui->txt_register_3->text()+"','"+ui->txt_register_4->text()+"','"+ui->txt_register_5->text()+"','"+ui->txt_register_6->text()+"','"+ui->txt_register_7->text()+"','"+ui->txt_register_8->text()+"','"+ui->txt_register_9->text()+"','"+ui->txt_register_10->text()+"','"+ui->txt_register_11->text()+"','"+ui->txt_register_12->text()+"','"+ui->txt_register_13->text()+"','"+ui->txt_register_14->text()+"','"+ui->txt_register_15->text()+"','"+ui->txt_register_16->text()+"','"+ui->txt_register_17->text()+"','"+ui->txt_register_18->text()+"','"+ui->txt_register_19->text()+"','"+ui->txt_register_20->text()+"','"+ui->txt_register_21->text()+"','"+ui->txt_register_22->text()+"','"+ui->txt_register_23->text()+"','"+ui->txt_register_24->text()+"','"+ui->txt_register_25->text()+"','"+ui->txt_register_26->text()+"','"+ui->txt_register_27->text()+"','"+ui->txt_register_28->text()+"','"+ui->txt_register_29->text()+"','"+avatar_url+"');");
                //show message
                QMessageBox::information(this,"",
                                         "کاربر با مشخصات :\n"
                                         "نام‌: "+ui->txt_register_1->text()+
                                         "\nنام خانوادگی :"+ui->txt_register_2->text()+
                                         "\n کدملی: "+ui->txt_register_0->text()+ "\n"
                                                                                  "با موفیقت ساخته شد.");

                //back to main window slide ..
                ui->groupBox_hs_register->hide();
                ui->groupBox_hs_search_for_edit->hide();
                ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
                ui->txt_register_0->setToolTip("");  ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
                ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
                //hide btn delete user when page = registar || page != edit user
                ui->groupBox_home->show();
                ui->btn_edit_goto_delete_this_user->show();
            }

        }
    }
}

void MainWindow::on_hs_register_triggered()
{
    ui->scrollArea_register->ensureVisible(0,0,0,0);



    ui->groupBox_login->hide();
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();

    //hide btn delete user when page = registar || page != edit user
    ui->btn_edit_goto_delete_this_user->hide();


    ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
    ui->groupBox_hs_register->show();
    ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
    ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
    ui->groupBox_hs_register->setTitle("فرم ثبت نام عضو جدید در حسینیه");
    ui->btn_register_insert->setText("ثبت");
    //if want to back and make button clear/reset everything from form idcode(codr1)
    //ui->btn_register_clear->setText("تنظیم مجدد");
    QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
    while (q_Hs_Load_Title.next())
    {
        ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
        //dbDynamic_disable_status_Text use this  disable_status
        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
        const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
        if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
        const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
        if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
        const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
        if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
        const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
        if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
        const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
        if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
        const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
        if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
        const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
        if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
        const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
        if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
        const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
        if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
        const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
        if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
        const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
        if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
        const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
        if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
        const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
        if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
        const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
        if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
        const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
        if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
        const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
        if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
        const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
        if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
        const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
        if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
        const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
        if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
        const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
        if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
        const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
        if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
        const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
        if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
        const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
        if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
        const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
        if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
        const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
        if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
        const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
        if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
    }
    if(avatar_url == "")
    {
        QSqlQuery search_for_url_avatar_defualt("SELECT * FROM adminconfig;");
        //url
        while (search_for_url_avatar_defualt.next())
        {
            defualt_avatar = search_for_url_avatar_defualt.value("defualt_avatar").toString();
        }
        QPixmap pm(defualt_avatar); ui->lbl_register_avatar->setPixmap(defualt_avatar);
        ui->lbl_register_avatar->setScaledContents(true);
    }

}

void MainWindow::on_hs_edit_triggered()
{



    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();





    ui->btn_edit_goto_delete_this_user->show();

    ui->groupBox_hs_search_for_edit->show();
    ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
    ui->txt_hs_search_for_edit_by_family->clear();  ui->txt_hs_search_for_edit_by_name->clear();  ui->txt_hs_search_for_edit_by_code->clear();
    ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false);  ui->txt_register_2->setDisabled(false);
    ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
}

void MainWindow::on_btn_hs_search_for_edit_clicked()
{
    ui->scrollArea_register->ensureVisible(0,0,0,0);
    ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
    ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
    if(ui->txt_hs_search_for_edit_by_code->text() == "" && ui->txt_hs_search_for_edit_by_name->text() == "" && ui->txt_hs_search_for_edit_by_family->text() == "")
    {
        QMessageBox::warning(this,"خطا","باید حداقل یکی از فیلدها جهت جستجو پرشود\n جهت دقت بیشتر در جستجو ، از فیلد های بیشتری استفاده کنید"); //
    }
    else if(ui->txt_hs_search_for_edit_by_code->text() == "" && ui->txt_hs_search_for_edit_by_name->text() == "" && ui->txt_hs_search_for_edit_by_family->text() != "")
    {
        family = ui->txt_hs_search_for_edit_by_family->text();
        ui->groupBox_hs_search_for_edit->hide();
        editVar = &family;
        editParameter = "p2";
        ui->txt_register_2->setDisabled(true);
        ui->txt_register_2->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی ");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش اعضای حسینیه");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");

        QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
            //dbDynamic_disable_status_Text use this  disable_status
            //        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
            //        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
            //        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
            //        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
            //        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
            //        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
            //        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
            //        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
            const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
            if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
            const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
            if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
            const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
            if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
            const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
            if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
            const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
            if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
            const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
            if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
            const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
            if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
            const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
            if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
            const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
            if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
            const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
            if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
            const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
            if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
            const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
            if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
            const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
            if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
            const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
            if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
            const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
            if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
            const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
            if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
            const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
            if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
            const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
            if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
            const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
            if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
            const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
            if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
            const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
            if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
            const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
            if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
            const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
            if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
            const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
            if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
            const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
            if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
            const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
            if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
        }


        QSqlQuery q_Hs_search_for_edit_by_family("SELECT * FROM registration WHERE p2='"+ui->txt_hs_search_for_edit_by_family->text()+"'");
        while (q_Hs_search_for_edit_by_family.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_family.value("p0").toString());     ui->txt_register_1->setText(q_Hs_search_for_edit_by_family.value("p1").toString());
            ui->txt_register_2->setText(q_Hs_search_for_edit_by_family.value("p2").toString());     ui->txt_register_3->setText(q_Hs_search_for_edit_by_family.value("p3").toString());
            ui->txt_register_4->setText(q_Hs_search_for_edit_by_family.value("p4").toString());     ui->txt_register_5->setText(q_Hs_search_for_edit_by_family.value("p5").toString());
            ui->txt_register_6->setText(q_Hs_search_for_edit_by_family.value("p6").toString());     ui->txt_register_7->setText(q_Hs_search_for_edit_by_family.value("p7").toString());
            ui->txt_register_8->setText(q_Hs_search_for_edit_by_family.value("p8").toString());     ui->txt_register_9->setText(q_Hs_search_for_edit_by_family.value("p9").toString());
            ui->txt_register_10->setText(q_Hs_search_for_edit_by_family.value("p10").toString());   ui->txt_register_11->setText(q_Hs_search_for_edit_by_family.value("p11").toString());
            ui->txt_register_12->setText(q_Hs_search_for_edit_by_family.value("p12").toString());   ui->txt_register_13->setText(q_Hs_search_for_edit_by_family.value("p13").toString());
            ui->txt_register_14->setText(q_Hs_search_for_edit_by_family.value("p14").toString());   ui->txt_register_15->setText(q_Hs_search_for_edit_by_family.value("p15").toString());
            ui->txt_register_16->setText(q_Hs_search_for_edit_by_family.value("p16").toString());   ui->txt_register_17->setText(q_Hs_search_for_edit_by_family.value("p17").toString());
            ui->txt_register_18->setText(q_Hs_search_for_edit_by_family.value("p18").toString());   ui->txt_register_19->setText(q_Hs_search_for_edit_by_family.value("p19").toString());
            ui->txt_register_20->setText(q_Hs_search_for_edit_by_family.value("p20").toString());   ui->txt_register_21->setText(q_Hs_search_for_edit_by_family.value("p21").toString());
            ui->txt_register_22->setText(q_Hs_search_for_edit_by_family.value("p22").toString());   ui->txt_register_23->setText(q_Hs_search_for_edit_by_family.value("p23").toString());
            ui->txt_register_24->setText(q_Hs_search_for_edit_by_family.value("p24").toString());   ui->txt_register_25->setText(q_Hs_search_for_edit_by_family.value("p25").toString());
            ui->txt_register_26->setText(q_Hs_search_for_edit_by_family.value("p26").toString());   ui->txt_register_27->setText(q_Hs_search_for_edit_by_family.value("p27").toString());
            ui->txt_register_28->setText(q_Hs_search_for_edit_by_family.value("p28").toString());   ui->txt_register_29->setText(q_Hs_search_for_edit_by_family.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_family.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_family.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url); ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);

        }
        ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
        if(ui->txt_register_0->text()=="" && ui->txt_register_1->text() =="" &&ui->txt_register_2->text()=="")
        {
            ui->groupBox_hs_register->hide();
            ui->groupBox_hs_search_for_edit->show();
            ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
            QMessageBox :: warning(this,"خطا","کاربری با چنین نام خانوادگی یافت نشد\nجهت دقت بیشتر در جستجو ، از فیلد های بیشتری استفاده کنید");
        }
    }
    else if(ui->txt_hs_search_for_edit_by_code->text() == "" && ui->txt_hs_search_for_edit_by_name->text() != "" && ui->txt_hs_search_for_edit_by_family->text() == "")
    {

        name = ui->txt_hs_search_for_edit_by_name->text();
        ui->groupBox_hs_search_for_edit->hide();
        editVar = &name;
        editParameter = "p1";
        ui->txt_register_0->setDisabled(false);
        ui->txt_register_0->setToolTip("");
        ui->txt_register_1->setDisabled(true);
        ui->txt_register_1->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی ");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش اعضای حسینیه");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");

        QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
            //dbDynamic_disable_status_Text use this  disable_status
            //        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
            //        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
            //        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
            //        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
            //        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
            //        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
            //        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
            //        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
            const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
            if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
            const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
            if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
            const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
            if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
            const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
            if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
            const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
            if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
            const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
            if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
            const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
            if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
            const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
            if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
            const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
            if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
            const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
            if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
            const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
            if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
            const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
            if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
            const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
            if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
            const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
            if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
            const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
            if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
            const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
            if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
            const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
            if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
            const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
            if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
            const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
            if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
            const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
            if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
            const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
            if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
            const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
            if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
            const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
            if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
            const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
            if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
            const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
            if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
            const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
            if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
        }
        QSqlQuery q_Hs_search_for_edit_by_name("SELECT * FROM registration WHERE p1='"+ui->txt_hs_search_for_edit_by_name->text()+"'");
        while (q_Hs_search_for_edit_by_name.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_name.value("p0").toString());   ui->txt_register_1->setText(q_Hs_search_for_edit_by_name.value("p1").toString());
            ui->txt_register_2->setText(q_Hs_search_for_edit_by_name.value("p2").toString());   ui->txt_register_3->setText(q_Hs_search_for_edit_by_name.value("p3").toString());
            ui->txt_register_4->setText(q_Hs_search_for_edit_by_name.value("p4").toString());   ui->txt_register_5->setText(q_Hs_search_for_edit_by_name.value("p5").toString());
            ui->txt_register_6->setText(q_Hs_search_for_edit_by_name.value("p6").toString());   ui->txt_register_7->setText(q_Hs_search_for_edit_by_name.value("p7").toString());
            ui->txt_register_8->setText(q_Hs_search_for_edit_by_name.value("p8").toString());   ui->txt_register_9->setText(q_Hs_search_for_edit_by_name.value("p9").toString());
            ui->txt_register_10->setText(q_Hs_search_for_edit_by_name.value("p10").toString()); ui->txt_register_11->setText(q_Hs_search_for_edit_by_name.value("p11").toString());
            ui->txt_register_12->setText(q_Hs_search_for_edit_by_name.value("p12").toString()); ui->txt_register_13->setText(q_Hs_search_for_edit_by_name.value("p13").toString());
            ui->txt_register_14->setText(q_Hs_search_for_edit_by_name.value("p14").toString()); ui->txt_register_15->setText(q_Hs_search_for_edit_by_name.value("p15").toString());
            ui->txt_register_16->setText(q_Hs_search_for_edit_by_name.value("p16").toString()); ui->txt_register_17->setText(q_Hs_search_for_edit_by_name.value("p17").toString());
            ui->txt_register_18->setText(q_Hs_search_for_edit_by_name.value("p18").toString()); ui->txt_register_19->setText(q_Hs_search_for_edit_by_name.value("p19").toString());
            ui->txt_register_20->setText(q_Hs_search_for_edit_by_name.value("p20").toString()); ui->txt_register_21->setText(q_Hs_search_for_edit_by_name.value("p21").toString());
            ui->txt_register_22->setText(q_Hs_search_for_edit_by_name.value("p22").toString()); ui->txt_register_23->setText(q_Hs_search_for_edit_by_name.value("p23").toString());
            ui->txt_register_24->setText(q_Hs_search_for_edit_by_name.value("p24").toString()); ui->txt_register_25->setText(q_Hs_search_for_edit_by_name.value("p25").toString());
            ui->txt_register_26->setText(q_Hs_search_for_edit_by_name.value("p26").toString()); ui->txt_register_27->setText(q_Hs_search_for_edit_by_name.value("p27").toString());
            ui->txt_register_28->setText(q_Hs_search_for_edit_by_name.value("p28").toString()); ui->txt_register_29->setText(q_Hs_search_for_edit_by_name.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_name.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_name.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url); // <- path to image file  "C:/Users/Patrick Wieland/Documents/Kochen/bento.jpg"
            ui->lbl_register_avatar->setPixmap(avatar_url);
            ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg

        }
        ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
        if(ui->txt_register_0->text()=="" && ui->txt_register_1->text() =="" &&ui->txt_register_2->text()=="")
        {
            ui->groupBox_hs_register->hide();
            ui->groupBox_hs_search_for_edit->show();
            ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
            QMessageBox :: warning(this,"خطا"
                                   ,"کاربری با چنین نام یافت نشد \nجهت دقت بیشتر در جستجو ، از فیلد های بیشتری استفاده کنید");
        }

    }
    else if(ui->txt_hs_search_for_edit_by_code->text() != "" && ui->txt_hs_search_for_edit_by_name->text() == "" && ui->txt_hs_search_for_edit_by_family->text() == "")
    {
        code = ui->txt_hs_search_for_edit_by_code->text();
        ui->groupBox_hs_search_for_edit->hide();
        editVar = &code;
        editParameter = "p0";
        ui->txt_register_0->setDisabled(true);
        ui->txt_register_0->setToolTip("       نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید  \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > نام یا نام خانوادگی");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش اعضای حسینیه");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");

        QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
            //dbDynamic_disable_status_Text use this  disable_status
            //        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
            //        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
            //        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
            //        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
            //        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
            //        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
            //        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
            //        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
            const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
            if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
            const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
            if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
            const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
            if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
            const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
            if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
            const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
            if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
            const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
            if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
            const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
            if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
            const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
            if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
            const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
            if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
            const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
            if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
            const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
            if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
            const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
            if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
            const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
            if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
            const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
            if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
            const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
            if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
            const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
            if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
            const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
            if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
            const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
            if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
            const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
            if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
            const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
            if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
            const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
            if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
            const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
            if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
            const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
            if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
            const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
            if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
            const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
            if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
            const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
            if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
        }


        QSqlQuery q_Hs_search_for_edit_by_code("SELECT * FROM registration WHERE p0='"+ui->txt_hs_search_for_edit_by_code->text()+"'");
        while (q_Hs_search_for_edit_by_code.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_code.value("p0").toString());   ui->txt_register_1->setText(q_Hs_search_for_edit_by_code.value("p1").toString());
            ui->txt_register_2->setText(q_Hs_search_for_edit_by_code.value("p2").toString());   ui->txt_register_3->setText(q_Hs_search_for_edit_by_code.value("p3").toString());
            ui->txt_register_4->setText(q_Hs_search_for_edit_by_code.value("p4").toString());   ui->txt_register_5->setText(q_Hs_search_for_edit_by_code.value("p5").toString());
            ui->txt_register_6->setText(q_Hs_search_for_edit_by_code.value("p6").toString());   ui->txt_register_7->setText(q_Hs_search_for_edit_by_code.value("p7").toString());
            ui->txt_register_8->setText(q_Hs_search_for_edit_by_code.value("p8").toString());   ui->txt_register_9->setText(q_Hs_search_for_edit_by_code.value("p9").toString());
            ui->txt_register_10->setText(q_Hs_search_for_edit_by_code.value("p10").toString()); ui->txt_register_11->setText(q_Hs_search_for_edit_by_code.value("p11").toString());
            ui->txt_register_12->setText(q_Hs_search_for_edit_by_code.value("p12").toString()); ui->txt_register_13->setText(q_Hs_search_for_edit_by_code.value("p13").toString());
            ui->txt_register_14->setText(q_Hs_search_for_edit_by_code.value("p14").toString()); ui->txt_register_15->setText(q_Hs_search_for_edit_by_code.value("p15").toString());
            ui->txt_register_16->setText(q_Hs_search_for_edit_by_code.value("p16").toString()); ui->txt_register_17->setText(q_Hs_search_for_edit_by_code.value("p17").toString());
            ui->txt_register_18->setText(q_Hs_search_for_edit_by_code.value("p18").toString()); ui->txt_register_19->setText(q_Hs_search_for_edit_by_code.value("p19").toString());
            ui->txt_register_20->setText(q_Hs_search_for_edit_by_code.value("p20").toString()); ui->txt_register_21->setText(q_Hs_search_for_edit_by_code.value("p21").toString());
            ui->txt_register_22->setText(q_Hs_search_for_edit_by_code.value("p22").toString()); ui->txt_register_23->setText(q_Hs_search_for_edit_by_code.value("p23").toString());
            ui->txt_register_24->setText(q_Hs_search_for_edit_by_code.value("p24").toString()); ui->txt_register_25->setText(q_Hs_search_for_edit_by_code.value("p25").toString());
            ui->txt_register_26->setText(q_Hs_search_for_edit_by_code.value("p26").toString()); ui->txt_register_27->setText(q_Hs_search_for_edit_by_code.value("p27").toString());
            ui->txt_register_28->setText(q_Hs_search_for_edit_by_code.value("p28").toString()); ui->txt_register_29->setText(q_Hs_search_for_edit_by_code.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_code.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_code.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url);   ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);

        }
        ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
        if(ui->txt_register_0->text()=="" && ui->txt_register_1->text() =="" &&ui->txt_register_2->text()=="")
        {
            ui->groupBox_hs_register->hide(); ui->groupBox_hs_search_for_edit->show();
            ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
            QMessageBox :: critical(this,"خطا",
                                    "کاربری با چنین کدملی یافت نشد\nجهت دقت بیشتر در جستجو ، از فیلد های بیشتری استفاده کنید");
        }
        //        else if(ui->txt_register_0->text()== "0" && ui->txt_register_1->text()== "1")
        //        {
        //            stats_check_code_user = true;
        //            ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->show();
        //            ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
        //            ui->txt_hs_search_for_edit_by_family->clear();  ui->txt_hs_search_for_edit_by_name->clear();  ui->txt_hs_search_for_edit_by_code->clear();
        //            ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false);  ui->txt_register_2->setDisabled(false);
        //            ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip("");  ui->txt_register_2->setToolTip("");
        //            QMessageBox::critical(this,"خطا",
        //                                  "استفاده از کارکتر غیرمجاز\nلطفا از عداد برای پر کردن فیلد کدملی استفاده کنید !");
        //        }
    }
    else if(ui->txt_hs_search_for_edit_by_code->text() == "" && ui->txt_hs_search_for_edit_by_name->text() != "" && ui->txt_hs_search_for_edit_by_family->text() != "")
    {
        name = ui->txt_hs_search_for_edit_by_name->text();
        family = ui->txt_hs_search_for_edit_by_family->text();
        ui->groupBox_hs_search_for_edit->hide();
        edit_search_name_and_family = true;
        //editVar = &;  //editParameter = "p0";
        ui->txt_register_1->setDisabled(true);
        ui->txt_register_1->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی یا نام خالی یا نام خانوادگی خالی");
        ui->txt_register_2->setDisabled(true);
        ui->txt_register_2->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی ");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش اعضای حسینیه");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");

        QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
            //dbDynamic_disable_status_Text use this  disable_status
            //        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
            //        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
            //        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
            //        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
            //        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
            //        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
            //        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
            //        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
            const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
            if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
            const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
            if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
            const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
            if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
            const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
            if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
            const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
            if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
            const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
            if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
            const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
            if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
            const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
            if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
            const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
            if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
            const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
            if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
            const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
            if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
            const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
            if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
            const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
            if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
            const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
            if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
            const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
            if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
            const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
            if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
            const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
            if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
            const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
            if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
            const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
            if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
            const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
            if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
            const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
            if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
            const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
            if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
            const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
            if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
            const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
            if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
            const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
            if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
            const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
            if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
        }

        tmp1 = ui->txt_hs_search_for_edit_by_name->text();
        tmp2 = ui->txt_hs_search_for_edit_by_family->text();
        QSqlQuery q_Hs_search_for_edit_by_name_and_family("SELECT * FROM registration WHERE p1='"+tmp1+"' AND p2='"+tmp2+"'");
        while (q_Hs_search_for_edit_by_name_and_family.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_name_and_family.value("p0").toString());    ui->txt_register_1->setText(q_Hs_search_for_edit_by_name_and_family.value("p1").toString());    ui->txt_register_2->setText(q_Hs_search_for_edit_by_name_and_family.value("p2").toString());    ui->txt_register_3->setText(q_Hs_search_for_edit_by_name_and_family.value("p3").toString());    ui->txt_register_4->setText(q_Hs_search_for_edit_by_name_and_family.value("p4").toString());    ui->txt_register_5->setText(q_Hs_search_for_edit_by_name_and_family.value("p5").toString());    ui->txt_register_6->setText(q_Hs_search_for_edit_by_name_and_family.value("p6").toString());    ui->txt_register_7->setText(q_Hs_search_for_edit_by_name_and_family.value("p7").toString());    ui->txt_register_8->setText(q_Hs_search_for_edit_by_name_and_family.value("p8").toString());    ui->txt_register_9->setText(q_Hs_search_for_edit_by_name_and_family.value("p9").toString());    ui->txt_register_10->setText(q_Hs_search_for_edit_by_name_and_family.value("p10").toString());  ui->txt_register_11->setText(q_Hs_search_for_edit_by_name_and_family.value("p11").toString());  ui->txt_register_12->setText(q_Hs_search_for_edit_by_name_and_family.value("p12").toString());  ui->txt_register_13->setText(q_Hs_search_for_edit_by_name_and_family.value("p13").toString());  ui->txt_register_14->setText(q_Hs_search_for_edit_by_name_and_family.value("p14").toString());  ui->txt_register_15->setText(q_Hs_search_for_edit_by_name_and_family.value("p15").toString());  ui->txt_register_16->setText(q_Hs_search_for_edit_by_name_and_family.value("p16").toString());  ui->txt_register_17->setText(q_Hs_search_for_edit_by_name_and_family.value("p17").toString());  ui->txt_register_18->setText(q_Hs_search_for_edit_by_name_and_family.value("p18").toString());  ui->txt_register_19->setText(q_Hs_search_for_edit_by_name_and_family.value("p19").toString());  ui->txt_register_20->setText(q_Hs_search_for_edit_by_name_and_family.value("p20").toString());  ui->txt_register_21->setText(q_Hs_search_for_edit_by_name_and_family.value("p21").toString());  ui->txt_register_22->setText(q_Hs_search_for_edit_by_name_and_family.value("p22").toString());  ui->txt_register_23->setText(q_Hs_search_for_edit_by_name_and_family.value("p23").toString());  ui->txt_register_24->setText(q_Hs_search_for_edit_by_name_and_family.value("p24").toString());  ui->txt_register_25->setText(q_Hs_search_for_edit_by_name_and_family.value("p25").toString());  ui->txt_register_26->setText(q_Hs_search_for_edit_by_name_and_family.value("p26").toString());  ui->txt_register_27->setText(q_Hs_search_for_edit_by_name_and_family.value("p27").toString());  ui->txt_register_28->setText(q_Hs_search_for_edit_by_name_and_family.value("p28").toString());  ui->txt_register_29->setText(q_Hs_search_for_edit_by_name_and_family.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_name_and_family.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_name_and_family.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url);   ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);
        }
        ui->txt_hs_search_for_edit_by_code->clear(); ui->txt_hs_search_for_edit_by_name->clear(); ui->txt_hs_search_for_edit_by_family->clear();
        if(ui->txt_register_0->text()=="" && ui->txt_register_1->text() =="" &&ui->txt_register_2->text()=="")
        {
            ui->groupBox_hs_register->hide();
            ui->groupBox_hs_search_for_edit->show();
            ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
            QMessageBox :: critical(this,"خطا","کاربری با چنین نام و نام خانوادگی یافت نشد");
        }
    }
    else if(ui->txt_hs_search_for_edit_by_code->text() != "" && ui->txt_hs_search_for_edit_by_name->text() != "" && ui->txt_hs_search_for_edit_by_family->text() != "")
    {

        family = ui->txt_hs_search_for_edit_by_family->text();
        code= ui->txt_hs_search_for_edit_by_code->text();
        name = ui->txt_hs_search_for_edit_by_name->text();

        ui->groupBox_hs_search_for_edit->hide();
        edit_search_code_and_name_and_family = true;
        ui->txt_register_0->setDisabled(true);  ui->txt_register_1->setDisabled(true);  ui->txt_register_2->setDisabled(true);
        ui->txt_register_0->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو >   ");
        ui->txt_register_1->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو >   ");
        ui->txt_register_2->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو >   ");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش اعضای حسینیه");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");

        QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
            //dbDynamic_disable_status_Text use this  disable_status
            //        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
            //        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
            //        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
            //        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
            //        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
            //        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
            //        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
            //        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
            const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
            if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
            const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
            if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
            const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
            if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
            const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
            if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
            const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
            if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
            const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
            if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
            const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
            if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
            const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
            if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
            const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
            if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
            const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
            if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
            const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
            if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
            const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
            if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
            const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
            if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
            const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
            if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
            const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
            if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
            const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
            if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
            const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
            if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
            const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
            if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
            const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
            if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
            const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
            if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
            const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
            if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
            const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
            if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
            const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
            if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
            const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
            if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
            const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
            if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
            const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
            if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
        }

        tmp1 = ui->txt_hs_search_for_edit_by_name->text();
        tmp2 = ui->txt_hs_search_for_edit_by_family->text();
        tmp3 = ui->txt_hs_search_for_edit_by_code->text();
        QSqlQuery q_Hs_search_for_edit_by_code_and_name_and_family("SELECT * FROM registration WHERE p1='"+tmp1+"' AND p2='"+tmp2+"' AND p0='"+tmp3+"'");
        while (q_Hs_search_for_edit_by_code_and_name_and_family.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p0").toString());    ui->txt_register_1->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p1").toString());    ui->txt_register_2->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p2").toString());    ui->txt_register_3->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p3").toString());    ui->txt_register_4->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p4").toString());    ui->txt_register_5->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p5").toString());    ui->txt_register_6->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p6").toString());    ui->txt_register_7->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p7").toString());    ui->txt_register_8->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p8").toString());    ui->txt_register_9->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p9").toString());    ui->txt_register_10->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p10").toString());  ui->txt_register_11->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p11").toString());  ui->txt_register_12->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p12").toString());  ui->txt_register_13->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p13").toString());  ui->txt_register_14->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p14").toString());  ui->txt_register_15->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p15").toString());  ui->txt_register_16->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p16").toString());  ui->txt_register_17->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p17").toString());  ui->txt_register_18->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p18").toString());  ui->txt_register_19->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p19").toString());  ui->txt_register_20->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p20").toString());  ui->txt_register_21->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p21").toString());  ui->txt_register_22->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p22").toString());  ui->txt_register_23->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p23").toString());  ui->txt_register_24->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p24").toString());  ui->txt_register_25->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p25").toString());  ui->txt_register_26->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p26").toString());  ui->txt_register_27->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p27").toString());  ui->txt_register_28->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p28").toString());  ui->txt_register_29->setText(q_Hs_search_for_edit_by_code_and_name_and_family.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_code_and_name_and_family.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_code_and_name_and_family.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url);   ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);
        }
        ui->txt_hs_search_for_edit_by_code->clear(); ui->txt_hs_search_for_edit_by_name->clear(); ui->txt_hs_search_for_edit_by_family->clear();
        if(ui->txt_register_0->text()=="" && ui->txt_register_1->text() =="" &&ui->txt_register_2->text()=="")
        {
            ui->groupBox_hs_register->hide();
            ui->groupBox_hs_search_for_edit->show();
            ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
            QMessageBox :: critical(this,"خطا","کاربری با چنین نام و نام خانوادگی و کدملی یافت نشد");
        }
    }
    else if(ui->txt_hs_search_for_edit_by_code->text() != "" && ui->txt_hs_search_for_edit_by_name->text() != "" && ui->txt_hs_search_for_edit_by_family->text() == "")
    {
        //do
        name = ui->txt_hs_search_for_edit_by_name->text();
        code = ui->txt_hs_search_for_edit_by_code->text();
        ui->groupBox_hs_search_for_edit->hide();
        edit_search_code_and_name =true; //edit_search_name_and_family = true;
        ui->txt_register_0->setDisabled(true);  ui->txt_register_1->setDisabled(true);
        //ui->txt_register_1->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی ");
        ui->txt_register_0->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی یا نام خالی یا نام خانوادگی خالی");
        ui->txt_register_1->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی یا نام خالی یا نام خانوادگی خالی");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش اعضای حسینیه");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");

        QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
            //dbDynamic_disable_status_Text use this  disable_status
            //        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
            //        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
            //        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
            //        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
            //        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
            //        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
            //        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
            //        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
            const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
            if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
            const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
            if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
            const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
            if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
            const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
            if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
            const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
            if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
            const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
            if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
            const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
            if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
            const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
            if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
            const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
            if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
            const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
            if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
            const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
            if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
            const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
            if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
            const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
            if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
            const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
            if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
            const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
            if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
            const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
            if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
            const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
            if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
            const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
            if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
            const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
            if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
            const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
            if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
            const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
            if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
            const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
            if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
            const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
            if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
            const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
            if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
            const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
            if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
            const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
            if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
        }

        tmp1 = ui->txt_hs_search_for_edit_by_code->text();
        tmp2 = ui->txt_hs_search_for_edit_by_name->text();
        QSqlQuery q_Hs_search_for_edit_by_code_and_name("SELECT * FROM registration WHERE p0='"+tmp1+"' AND p1='"+tmp2+"'");
        while (q_Hs_search_for_edit_by_code_and_name.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_code_and_name.value("p0").toString());    ui->txt_register_1->setText(q_Hs_search_for_edit_by_code_and_name.value("p1").toString());    ui->txt_register_2->setText(q_Hs_search_for_edit_by_code_and_name.value("p2").toString());    ui->txt_register_3->setText(q_Hs_search_for_edit_by_code_and_name.value("p3").toString());    ui->txt_register_4->setText(q_Hs_search_for_edit_by_code_and_name.value("p4").toString());    ui->txt_register_5->setText(q_Hs_search_for_edit_by_code_and_name.value("p5").toString());    ui->txt_register_6->setText(q_Hs_search_for_edit_by_code_and_name.value("p6").toString());    ui->txt_register_7->setText(q_Hs_search_for_edit_by_code_and_name.value("p7").toString());    ui->txt_register_8->setText(q_Hs_search_for_edit_by_code_and_name.value("p8").toString());    ui->txt_register_9->setText(q_Hs_search_for_edit_by_code_and_name.value("p9").toString());    ui->txt_register_10->setText(q_Hs_search_for_edit_by_code_and_name.value("p10").toString());  ui->txt_register_11->setText(q_Hs_search_for_edit_by_code_and_name.value("p11").toString());  ui->txt_register_12->setText(q_Hs_search_for_edit_by_code_and_name.value("p12").toString());  ui->txt_register_13->setText(q_Hs_search_for_edit_by_code_and_name.value("p13").toString());  ui->txt_register_14->setText(q_Hs_search_for_edit_by_code_and_name.value("p14").toString());  ui->txt_register_15->setText(q_Hs_search_for_edit_by_code_and_name.value("p15").toString());  ui->txt_register_16->setText(q_Hs_search_for_edit_by_code_and_name.value("p16").toString());  ui->txt_register_17->setText(q_Hs_search_for_edit_by_code_and_name.value("p17").toString());  ui->txt_register_18->setText(q_Hs_search_for_edit_by_code_and_name.value("p18").toString());  ui->txt_register_19->setText(q_Hs_search_for_edit_by_code_and_name.value("p19").toString());  ui->txt_register_20->setText(q_Hs_search_for_edit_by_code_and_name.value("p20").toString());  ui->txt_register_21->setText(q_Hs_search_for_edit_by_code_and_name.value("p21").toString());  ui->txt_register_22->setText(q_Hs_search_for_edit_by_code_and_name.value("p22").toString());  ui->txt_register_23->setText(q_Hs_search_for_edit_by_code_and_name.value("p23").toString());  ui->txt_register_24->setText(q_Hs_search_for_edit_by_code_and_name.value("p24").toString());  ui->txt_register_25->setText(q_Hs_search_for_edit_by_code_and_name.value("p25").toString());  ui->txt_register_26->setText(q_Hs_search_for_edit_by_code_and_name.value("p26").toString());  ui->txt_register_27->setText(q_Hs_search_for_edit_by_code_and_name.value("p27").toString());  ui->txt_register_28->setText(q_Hs_search_for_edit_by_code_and_name.value("p28").toString());  ui->txt_register_29->setText(q_Hs_search_for_edit_by_code_and_name.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_code_and_name.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_code_and_name.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url);   ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);
        }
        ui->txt_hs_search_for_edit_by_code->clear(); ui->txt_hs_search_for_edit_by_name->clear(); ui->txt_hs_search_for_edit_by_family->clear();
        if(ui->txt_register_0->text()=="" && ui->txt_register_1->text() =="" &&ui->txt_register_2->text()=="")
        {
            ui->groupBox_hs_register->hide();
            ui->groupBox_hs_search_for_edit->show();
            ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
            QMessageBox :: critical(this,"خطا","کاربری با چنین نام و کدملی یافت نشد");
        }
    }
    else if(ui->txt_hs_search_for_edit_by_code->text() != "" && ui->txt_hs_search_for_edit_by_name->text() == "" && ui->txt_hs_search_for_edit_by_family->text() != "")
    {
        family = ui->txt_hs_search_for_edit_by_family->text();
        code = ui->txt_hs_search_for_edit_by_code->text();
        ui->groupBox_hs_search_for_edit->hide();
        edit_search_code_and_family =true;
        ui->txt_register_0->setDisabled(true);  ui->txt_register_2->setDisabled(true);
        ui->txt_register_0->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی یا نام خالی یا نام خانوادگی خالی");
        ui->txt_register_2->setToolTip("نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > کد ملی یا نام خالی یا نام خانوادگی خالی");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش اعضای حسینیه");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");

        QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
            //dbDynamic_disable_status_Text use this  disable_status
            //        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
            //        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
            //        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
            //        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
            //        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
            //        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
            //        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
            //        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
            const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
            if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
            const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
            if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
            const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
            if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
            const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
            if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
            const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
            if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
            const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
            if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
            const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
            if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
            const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
            if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
            const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
            if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
            const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
            if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
            const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
            if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
            const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
            if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
            const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
            if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
            const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
            if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
            const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
            if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
            const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
            if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
            const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
            if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
            const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
            if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
            const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
            if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
            const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
            if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
            const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
            if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
            const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
            if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
            const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
            if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
            const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
            if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
            const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
            if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
            const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
            if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
        }

        tmp1 = ui->txt_hs_search_for_edit_by_code->text();
        tmp2 = ui->txt_hs_search_for_edit_by_family->text();
        QSqlQuery q_Hs_search_for_edit_by_code_and_family("SELECT * FROM registration WHERE p0='"+tmp1+"' AND p2='"+tmp2+"'");
        while (q_Hs_search_for_edit_by_code_and_family.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_code_and_family.value("p0").toString());    ui->txt_register_1->setText(q_Hs_search_for_edit_by_code_and_family.value("p1").toString());    ui->txt_register_2->setText(q_Hs_search_for_edit_by_code_and_family.value("p2").toString());    ui->txt_register_3->setText(q_Hs_search_for_edit_by_code_and_family.value("p3").toString());    ui->txt_register_4->setText(q_Hs_search_for_edit_by_code_and_family.value("p4").toString());    ui->txt_register_5->setText(q_Hs_search_for_edit_by_code_and_family.value("p5").toString());    ui->txt_register_6->setText(q_Hs_search_for_edit_by_code_and_family.value("p6").toString());    ui->txt_register_7->setText(q_Hs_search_for_edit_by_code_and_family.value("p7").toString());    ui->txt_register_8->setText(q_Hs_search_for_edit_by_code_and_family.value("p8").toString());    ui->txt_register_9->setText(q_Hs_search_for_edit_by_code_and_family.value("p9").toString());    ui->txt_register_10->setText(q_Hs_search_for_edit_by_code_and_family.value("p10").toString());  ui->txt_register_11->setText(q_Hs_search_for_edit_by_code_and_family.value("p11").toString());  ui->txt_register_12->setText(q_Hs_search_for_edit_by_code_and_family.value("p12").toString());  ui->txt_register_13->setText(q_Hs_search_for_edit_by_code_and_family.value("p13").toString());  ui->txt_register_14->setText(q_Hs_search_for_edit_by_code_and_family.value("p14").toString());  ui->txt_register_15->setText(q_Hs_search_for_edit_by_code_and_family.value("p15").toString());  ui->txt_register_16->setText(q_Hs_search_for_edit_by_code_and_family.value("p16").toString());  ui->txt_register_17->setText(q_Hs_search_for_edit_by_code_and_family.value("p17").toString());  ui->txt_register_18->setText(q_Hs_search_for_edit_by_code_and_family.value("p18").toString());  ui->txt_register_19->setText(q_Hs_search_for_edit_by_code_and_family.value("p19").toString());  ui->txt_register_20->setText(q_Hs_search_for_edit_by_code_and_family.value("p20").toString());  ui->txt_register_21->setText(q_Hs_search_for_edit_by_code_and_family.value("p21").toString());  ui->txt_register_22->setText(q_Hs_search_for_edit_by_code_and_family.value("p22").toString());  ui->txt_register_23->setText(q_Hs_search_for_edit_by_code_and_family.value("p23").toString());  ui->txt_register_24->setText(q_Hs_search_for_edit_by_code_and_family.value("p24").toString());  ui->txt_register_25->setText(q_Hs_search_for_edit_by_code_and_family.value("p25").toString());  ui->txt_register_26->setText(q_Hs_search_for_edit_by_code_and_family.value("p26").toString());  ui->txt_register_27->setText(q_Hs_search_for_edit_by_code_and_family.value("p27").toString());  ui->txt_register_28->setText(q_Hs_search_for_edit_by_code_and_family.value("p28").toString());  ui->txt_register_29->setText(q_Hs_search_for_edit_by_code_and_family.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_code_and_family.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_code_and_family.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url);   ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);
        }
        ui->txt_hs_search_for_edit_by_code->clear(); ui->txt_hs_search_for_edit_by_name->clear(); ui->txt_hs_search_for_edit_by_family->clear();
        if(ui->txt_register_0->text()=="" && ui->txt_register_1->text() =="" &&ui->txt_register_2->text()=="")
        {
            ui->groupBox_hs_register->hide();
            ui->groupBox_hs_search_for_edit->show();
            ui->txt_hs_search_for_edit_by_code->clear();    ui->txt_hs_search_for_edit_by_name->clear();    ui->txt_hs_search_for_edit_by_family->clear();
            QMessageBox :: critical(this,"خطا","کاربری با چنین کدملی و نام خانوادگی یافت نشد");
        }
    }
}

void MainWindow::on_btn_register_avatar_clicked() //code5
{
    ui->scrollArea_register->ensureVisible(0,0,0,0);
    if(ui->txt_register_0->text() == "" || (ui->txt_register_1->text() == "" && ui->txt_register_2->text()==""))
    {
        QMessageBox ::warning(this,"خطا" ," فیلد ها اصلی خالی است‌‌ !!");//یکی از
    }
    else if(ui->txt_register_0->text().size() < 10 || ui->txt_register_0->text().size() > 10)
    {
        QMessageBox ::warning(this,"خطا" ,"‌‌\n"
                                          "کدملی باید 10رقم باشد.");

    }

    else
    {
        QString url_and_filename_avatar = QFileDialog::getOpenFileName(this,   tr("تصویر مورد نظر را انتخاب کنید"), "/", tr("Image Files (*.jpg)"));
        //"تصویر مورد نظر را انتخاب کنید" , "/home");
        //    QStringRef secend_y = url_and_filename_avatar.rightRef(4);
        QString formatof = "";
        if(url_and_filename_avatar.endsWith(avatar_format) == true || url_and_filename_avatar.endsWith(avatar_format.toUpper()) == true)
            formatof = avatar_format;


        if(ui->txt_register_0->text() == "" || ui->txt_register_0->text() == " " || ui->txt_register_0->text() == "   ")
        {
            QMessageBox::information(this, " ", "لطفا اول کد ملی را وارد نمایید و سپس اقدام به افزودن عکس کنید");
        }
        else
        {
            QFile::remove(address_avatar_hs_users+ui->txt_register_0->text()+avatar_format);
            QFile::remove(address_avatar_hs_users+ui->txt_register_0->text()+avatar_format.toUpper());

            QFile::copy(url_and_filename_avatar, address_avatar_hs_users+ui->txt_register_0->text()+formatof);
            avatar_url = address_avatar_hs_users+ui->txt_register_0->text()+formatof;
            QPixmap pm(avatar_url); ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);
        }
    }
}

void MainWindow::on_btn_login_clicked()
{
    int current_try=0;
    int max_try=0;
    //login varaibels
    QSqlQuery q_Hs_login_give_maxtry_and_currenttry("SELECT * FROM adminconfig;");
    while (q_Hs_login_give_maxtry_and_currenttry.next())
    {
        max_try = q_Hs_login_give_maxtry_and_currenttry.value("maxtry").toInt();
        current_try = q_Hs_login_give_maxtry_and_currenttry.value("currenttry").toInt();
    }

    QSqlQuery q_Hs_login("SELECT username,password FROM adminconfig;");
    while (q_Hs_login.next())
    {
        const QString username = q_Hs_login.value("username").toString();
        const QString password = q_Hs_login.value("password").toString();//HASH
        int tottalAdminLogins;
        QString totall_tmp ="";

        if(ui->txt_username->text() == username && ui->txt_password->text() == password)
        {
            user_is_on_login_page=false;
            if(current_try>=max_try)
            {
                QMessageBox::critical(this, "مسدودیت حساب!",
                                      "<FONT COLOR='#000000'>به علت تعداد تلاش مکرر در ورود ، حساب کاربری شما مسدود شده است.  </FONT><FONT COLOR='#ff0000'>("+QString::number(max_try)+"/"+QString::number(current_try)+")</FONT>");
            }
            else
            {
                if(ui->txt_username->text() == "admin" && ui->txt_password->text()== "admin")
                {
                    QMessageBox::warning(this," ", "درصورتی که برنامه را پیکربندی نکرده اید به بخش تنظیمات مراجعه فرمایید"
                                                   "\n"
                                                   "نام کاربری و کلمه عبور ایمن نیست"
                                                   "\n"
                                                   "لطفا هرچه زودتر به تغییر نام کاربری و کلمه عبور اقدام فرمایید");

                }
                //message or actions for user
                QMessageBox::information(this," .خوش‌ آمدید "+username,
                                         "ورود با موفیقت انجام شد");
                ui->menubar->setDisabled(false); //or hide
                ui->groupBox_login->hide();
                ui->groupBox_home->show();



                //update and give last login number for create next field to table adminloginslog
                QSqlQuery give_total_logins("SELECT total_logins FROM adminconfig");
                while (give_total_logins.next())
                {
                    totall_tmp = give_total_logins.value("total_logins").toString();
                }
                tottalAdminLogins = totall_tmp.toInt();
                if(tottalAdminLogins>=1000)
                {
                    //delete Table  and create again..
                    QSqlQuery drop_table_adminloginslog("DROP TABLE adminloginslog;");

                    //create again
                    QSqlQuery createTableAdminloginslog("CREATE TABLE adminloginslog(login_number TEXT, login_date TEXT);");
                    QSqlQuery add_Default_value_to_adminsloginlog("INSERT INTO adminloginslog (`login_number`,`login_date`) VALUES ('login_0','unknow date');");
                    //--------------------- end of adminloginlogs
                    QSqlQuery update_total_logins("UPDATE adminconfig SET total_logins='0';");
                    QMessageBox::warning(this,"توجه",
                                         "تعداد ورود های ادمین ثبت شده بیشتر از ۱۰۰۰ عدد شده و تعداد ورودهای ثبت شده از اول راه اندازی شدند.");

                }
                else
                {
                    tottalAdminLogins++;
                    QSqlQuery update_total_logins("UPDATE adminconfig SET total_logins='"+QString::number(tottalAdminLogins)+"';");
                    //give current date and insert to table adminloginslog
                    QString currentTimeAndDate =  QDateTime::currentDateTime().toString();

                    QSqlQuery add_new_login_date_to_loginslog("INSERT INTO adminloginslog (login_number,login_date) VALUES ('login_"+QString::number(+tottalAdminLogins)+"','"+currentTimeAndDate+"');");
                    //tottalAdminLogins=0; //currentTimeAndDate=""; //totall_tmp="";
                }
            }

        }
        else
        {
            if(current_try>=max_try)
            {
                user_is_on_login_page =false;
                QMessageBox::critical(this, "مسدودیت حساب!",
                                      "<FONT COLOR='#000000'>به علت تعداد تلاش مکرر در ورود ، حساب کاربری شما مسدود شده است.  </FONT><FONT COLOR='#ff0000'>("+QString::number(max_try)+"/"+QString::number(current_try)+")</FONT>");
            }
            else
            {
                user_is_on_login_page = true;
                current_try++;
                QSqlQuery q_Hs_login_append_currenttry("UPDATE adminconfig SET currenttry='"+QString::number(current_try)+"';");
                QMessageBox::warning(this, "عدم موفقیت در ورود به حساب کاربری",
                                     "<FONT COLOR='#000000'>نام کاربری یا کلمه عبور اشتباه است تعداد دفعات باقیمانده تلاش برای ورود</FONT>  <FONT COLOR='#ff0000'>("+QString::number(max_try)+"/"+QString::number(current_try)+")</FONT>");
            }

        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *keyLogin)
{
    if(user_is_on_login_page == true)
    {
        switch (keyLogin->key())
        {
        case Qt::Key_Enter:
        {
            int current_try=0;
            int max_try=0;
            //login varaibels
            QSqlQuery q_Hs_login_give_maxtry_and_currenttry("SELECT * FROM adminconfig;");
            while (q_Hs_login_give_maxtry_and_currenttry.next())
            {
                max_try = q_Hs_login_give_maxtry_and_currenttry.value("maxtry").toInt();
                current_try = q_Hs_login_give_maxtry_and_currenttry.value("currenttry").toInt();
            }

            QSqlQuery q_Hs_login("SELECT username,password FROM adminconfig;");
            while (q_Hs_login.next())
            {
                const QString username = q_Hs_login.value("username").toString();
                const QString password = q_Hs_login.value("password").toString();//HASH
                int tottalAdminLogins;
                QString totall_tmp ="";

                if(ui->txt_username->text() == username && ui->txt_password->text() == password)
                {
                    if(current_try>=max_try)
                    {
                        QMessageBox::critical(this, "مسدودیت حساب!",
                                              "<FONT COLOR='#000000'>به علت تعداد تلاش مکرر در ورود ، حساب کاربری شما مسدود شده است.  </FONT><FONT COLOR='#ff0000'>("+QString::number(max_try)+"/"+QString::number(current_try)+")</FONT>");
                    }
                    else
                    {
                        if(ui->txt_username->text() == "admin" && ui->txt_password->text()== "admin")
                        {
                            QMessageBox::warning(this," ", "درصورتی که برنامه را پیکربندی نکرده اید به بخش تنظیمات مراجعه فرمایید"
                                                           "\n"
                                                           "نام کاربری و کلمه عبور ایمن نیست"
                                                           "\n"
                                                           "لطفا هرچه زودتر به تغییر نام کاربری و کلمه عبور اقدام فرمایید");

                        }
                        //message or actions for user
                        QMessageBox::information(this," .خوش‌ آمدید "+username,
                                                 "ورود با موفیقت انجام شد");
                        ui->menubar->setDisabled(false); //or hide
                        ui->groupBox_login->hide();
                        ui->groupBox_home->show();




                        //update and give last login number for create next field to table adminloginslog
                        QSqlQuery give_total_logins("SELECT total_logins FROM adminconfig");
                        while (give_total_logins.next())
                        {
                            totall_tmp = give_total_logins.value("total_logins").toString();
                        }
                        tottalAdminLogins = totall_tmp.toInt();
                        if(tottalAdminLogins>=1000)
                        {
                            //delete Table  and create again..
                            QSqlQuery drop_table_adminloginslog("DROP TABLE adminloginslog;");

                            //create again
                            QSqlQuery add_table_adminloginslog("CREATE TABLE adminloginslog(login_number VARCHAR(1000), login_date VARCHAR(80));");
                            QSqlQuery add_Default_value_to_adminsloginlog("INSERT INTO adminloginslog (login_number,login_date) VALUES ('login_0','unknow-date');");
                            QSqlQuery update_total_logins("UPDATE adminconfig SET total_logins='0';");
                            QMessageBox::warning(this,"توجه",
                                                 "تعداد ورود های ادمین ثبت شده بیشتر از ۱۰۰۰ عدد شده و تعداد ورودهای ثبت شده از اول راه اندازی شدند.");

                        }
                        else
                        {
                            tottalAdminLogins++;
                            QSqlQuery update_total_logins("UPDATE adminconfig SET total_logins='"+QString::number(tottalAdminLogins)+"';");
                            //give current date and insert to table adminloginslog
                            QString currentTimeAndDate =  QDateTime::currentDateTime().toString();

                            QSqlQuery add_new_login_date_to_loginslog("INSERT INTO adminloginslog (login_number,login_date) VALUES ('login_"+QString::number(+tottalAdminLogins)+"','"+currentTimeAndDate+"');");
                            //tottalAdminLogins=0; //currentTimeAndDate=""; //totall_tmp="";
                        }
                    }

                }
                else
                {
                    if(current_try>=max_try)
                    {
                        QMessageBox::critical(this, "مسدودیت حساب!",
                                              "<FONT COLOR='#000000'>به علت تعداد تلاش مکرر در ورود ، حساب کاربری شما مسدود شده است.  </FONT><FONT COLOR='#ff0000'>("+QString::number(max_try)+"/"+QString::number(current_try)+")</FONT>");
                    }
                    else
                    {
                        current_try++;
                        QSqlQuery q_Hs_login_append_currenttry("UPDATE adminconfig SET currenttry='"+QString::number(current_try)+"';");
                        QMessageBox::warning(this, "عدم موفقیت در ورود به حساب کاربری",
                                             "<FONT COLOR='#000000'>نام کاربری یا کلمه عبور اشتباه است تعداد دفعات باقیمانده تلاش برای ورود</FONT>  <FONT COLOR='#ff0000'>("+QString::number(max_try)+"/"+QString::number(current_try)+")</FONT>");
                    }

                }
            }
            user_is_on_login_page= false;
        }
            break;
        }
    }
    else
    {
        //nothing..
    }

}


void MainWindow::on_btn_show_users_hs_clicked()
{
    if(want_to_select_student_from_list_for_add_to_a_class == true)
    {
        ui->groupBox_hs_user_information->hide();//new added !
        ui->groupBox_show_users_hs->hide();
        //        int numwawawa=0;
        //        QSqlQuery q_last_class_id("SELECT * FROM adminconfig;");
        //        while(q_last_class_id.next())
        //        {
        //           numwawawa = q_last_class_id.value("last_cid").toInt();
        //        }
        //        --numwawawa;
        //        class_id_is_herex = QString::number(numwawawa);
        //        QMessageBox::information(this," ","im in last_cid and value="+class_id_is_herex);


        ui->scrollArea_need_data_to_add_student_to_this_class->ensureVisible(0,0,0,0);
        int row = ui->tableWidget_show_users_hs->currentRow();
        int column = ui->tableWidget_show_users_hs->currentColumn();
        QString student_idcode = ui->tableWidget_show_users_hs->model()->index(row,column).data().toString();
//        QStringRef student_idcode_remove = student_idcode.leftRef(10);
//        code_meli = student_idcode_remove.toString();
        code_meli = student_idcode;
        ui->groupBox_show_users_hs->hide();
        QSqlQuery q_give_student_info_for_insert_to_class("SELECT * FROM students WHERE p0='"+code_meli+"';");
        QString my_temp_variable,my_temp_variable1,my_temp_variable2,my_temp_variable3;
        while(q_give_student_info_for_insert_to_class.next())
        {
            my_temp_variable = q_give_student_info_for_insert_to_class.value("p0").toString();
            my_temp_variable1 = q_give_student_info_for_insert_to_class.value("p1").toString();
            my_temp_variable2 = q_give_student_info_for_insert_to_class.value("p2").toString();
            my_temp_variable3 = q_give_student_info_for_insert_to_class.value("p3").toString();
        }
        //        QMessageBox::information(this," ","im in my_temp_variable and value="+my_temp_variable);
        QSqlQuery q_add_a_student_to_this_class0("INSERT INTO "+class_id_is_herex+" (cp0) VALUES ('"+my_temp_variable+"');");
        QSqlQuery q_update_cid_now("UPDATE "+class_id_is_herex+" SET cp1='"+my_temp_variable1+"',cp2='"+my_temp_variable2+"',cp3='"+my_temp_variable3+"' WHERE cp0='"+my_temp_variable+"';");


        ui->txt_stu_data_to_this_class_0->setText(my_temp_variable);
        ui->txt_stu_data_to_this_class_1->setText(my_temp_variable1);
        ui->txt_stu_data_to_this_class_2->setText(my_temp_variable2);
        ui->txt_stu_data_to_this_class_3->setText(my_temp_variable3);
        //groupBox_edit_form_stu_from_class
        ui->txt_stu_data_to_this_class_4->clear(); ui->txt_stu_data_to_this_class_5->clear(); ui->txt_stu_data_to_this_class_6->clear();ui->txt_stu_data_to_this_class_7->clear();ui->txt_stu_data_to_this_class_8->clear();ui->txt_stu_data_to_this_class_9->clear();ui->txt_stu_data_to_this_class_10->clear();ui->txt_stu_data_to_this_class_11->clear();ui->txt_stu_data_to_this_class_12->clear();ui->txt_stu_data_to_this_class_13->clear();ui->txt_stu_data_to_this_class_14->clear();
        ui->btn_show_users_hs->setText("نمایش اطلاعات");

        QSqlQuery q_give_class_parameters_from_classid("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
        while(q_give_class_parameters_from_classid.next())
        {
            ui->lbl_stu_data_to_this_class_0->setText(q_give_class_parameters_from_classid.value("cp0").toString());
            ui->lbl_stu_data_to_this_class_1->setText(q_give_class_parameters_from_classid.value("cp1").toString());
            ui->lbl_stu_data_to_this_class_2->setText(q_give_class_parameters_from_classid.value("cp2").toString());
            ui->lbl_stu_data_to_this_class_3->setText(q_give_class_parameters_from_classid.value("cp3").toString());
            ui->lbl_stu_data_to_this_class_4->setText(q_give_class_parameters_from_classid.value("cp4").toString());
            ui->lbl_stu_data_to_this_class_5->setText(q_give_class_parameters_from_classid.value("cp5").toString());
            ui->lbl_stu_data_to_this_class_6->setText(q_give_class_parameters_from_classid.value("cp6").toString());
            ui->lbl_stu_data_to_this_class_7->setText(q_give_class_parameters_from_classid.value("cp7").toString());
            ui->lbl_stu_data_to_this_class_8->setText(q_give_class_parameters_from_classid.value("cp8").toString());
            ui->lbl_stu_data_to_this_class_9->setText(q_give_class_parameters_from_classid.value("cp9").toString());
            ui->lbl_stu_data_to_this_class_10->setText(q_give_class_parameters_from_classid.value("cp10").toString());
            ui->lbl_stu_data_to_this_class_11->setText(q_give_class_parameters_from_classid.value("cp11").toString());
            ui->lbl_stu_data_to_this_class_12->setText(q_give_class_parameters_from_classid.value("cp12").toString());
            ui->lbl_stu_data_to_this_class_13->setText(q_give_class_parameters_from_classid.value("cp13").toString());
            ui->lbl_stu_data_to_this_class_14->setText(q_give_class_parameters_from_classid.value("cp14").toString());
        }
        ui->groupBox_insert_more_data_to_student_for_this_class->show();
        want_to_select_student_from_list_for_add_to_a_class = false;
    }


    else if(ui->groupBox_show_users_hs->title() == "لیست اعضای حسینیه")
    {
        im_from_hs_list =true;
        ui->tabWidget_hs_user_information->setTabEnabled(4,false);
        ui->btn_hs_userinfo_return_to_users_list->setText("بازگشت به لیست اعضا");
        QSqlQuery q_give_tab_titles("SELECT * FROM tabTitles;");
        while(q_give_tab_titles.next())
        {
            ui->tabWidget_hs_user_information->setTabText(0,q_give_tab_titles.value("tab_show_user_info_0").toString());
            ui->tabWidget_hs_user_information->setTabText(1,q_give_tab_titles.value("tab_show_user_info_1").toString());
            ui->tabWidget_hs_user_information->setTabText(2,q_give_tab_titles.value("tab_show_user_info_2").toString());
            ui->tabWidget_hs_user_information->setTabText(3,q_give_tab_titles.value("tab_show_user_info_3").toString());
            ui->tabWidget_hs_user_information->setTabText(4,q_give_tab_titles.value("tab_show_user_info_4").toString());

        }
        ui->scrollArea_register->ensureVisible(0,0,0,0);
//        if(ui->listWidget_show_users_hs->selectedItems().size() > 0)
//        {
        QString user_code_id ;
            int row = ui->tableWidget_show_users_hs->currentRow();
            int column = ui->tableWidget_show_users_hs->currentColumn();
            QString student_idcode = ui->tableWidget_show_users_hs->model()->index(row,column).data().toString();
            user_code_id = student_idcode;
//            QString name = ui->listWidget_show_users_hs->currentItem()->text();
//            QString user_code_id = name.left(10);
            //do other
            ui->groupBox_show_users_hs->hide();
            ui->groupBox_hs_user_information->show();
            //remove all values from userinformation
            ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
            ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
            ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
            ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
            ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
            ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
            ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
            ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
            ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
            ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
            ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
            ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
            ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
            ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
            ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
            ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
            ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
            ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
            ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
            ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
            ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
            ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
            ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
            ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
            ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
            ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
            ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
            ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
            ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
            ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
            ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();

            //give titles
            QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles;");
            while (q_Hs_Load_Title.next())
            {
                ui->lbl_hs_userinfo_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_hs_userinfo_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_hs_userinfo_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_hs_userinfo_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_hs_userinfo_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_hs_userinfo_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_hs_userinfo_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_hs_userinfo_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_hs_userinfo_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_hs_userinfo_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_hs_userinfo_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_hs_userinfo_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_hs_userinfo_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_hs_userinfo_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_hs_userinfo_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_hs_userinfo_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_hs_userinfo_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_hs_userinfo_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_hs_userinfo_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_hs_userinfo_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_hs_userinfo_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_hs_userinfo_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_hs_userinfo_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_hs_userinfo_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_hs_userinfo_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_hs_userinfo_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_hs_userinfo_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_hs_userinfo_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_hs_userinfo_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_hs_userinfo_t29->setText(q_Hs_Load_Title.value("t29").toString());
            }

            //give data WHERE idcode = database
            QSqlQuery q_hs_userinformation_show("SELECT * FROM registration WHERE p0='"+user_code_id+"';");
            while (q_hs_userinformation_show.next())
            {
                ui->lbl_hs_userinfo_p0->setText(q_hs_userinformation_show.value("p0").toString());   ui->lbl_hs_userinfo_p1->setText(q_hs_userinformation_show.value("p1").toString());
                ui->lbl_hs_userinfo_p2->setText(q_hs_userinformation_show.value("p2").toString());   ui->lbl_hs_userinfo_p3->setText(q_hs_userinformation_show.value("p3").toString());
                ui->lbl_hs_userinfo_p4->setText(q_hs_userinformation_show.value("p4").toString());   ui->lbl_hs_userinfo_p5->setText(q_hs_userinformation_show.value("p5").toString());
                ui->lbl_hs_userinfo_p6->setText(q_hs_userinformation_show.value("p6").toString());   ui->lbl_hs_userinfo_p7->setText(q_hs_userinformation_show.value("p7").toString());
                ui->lbl_hs_userinfo_p8->setText(q_hs_userinformation_show.value("p8").toString());   ui->lbl_hs_userinfo_p9->setText(q_hs_userinformation_show.value("p9").toString());
                ui->lbl_hs_userinfo_p10->setText(q_hs_userinformation_show.value("p10").toString()); ui->lbl_hs_userinfo_p11->setText(q_hs_userinformation_show.value("p11").toString());
                ui->lbl_hs_userinfo_p12->setText(q_hs_userinformation_show.value("p12").toString()); ui->lbl_hs_userinfo_p13->setText(q_hs_userinformation_show.value("p13").toString());
                ui->lbl_hs_userinfo_p14->setText(q_hs_userinformation_show.value("p14").toString()); ui->lbl_hs_userinfo_p15->setText(q_hs_userinformation_show.value("p15").toString());
                ui->lbl_hs_userinfo_p16->setText(q_hs_userinformation_show.value("p16").toString()); ui->lbl_hs_userinfo_p17->setText(q_hs_userinformation_show.value("p17").toString());
                ui->lbl_hs_userinfo_p18->setText(q_hs_userinformation_show.value("p18").toString()); ui->lbl_hs_userinfo_p19->setText(q_hs_userinformation_show.value("p19").toString());
                ui->lbl_hs_userinfo_p20->setText(q_hs_userinformation_show.value("p20").toString()); ui->lbl_hs_userinfo_p21->setText(q_hs_userinformation_show.value("p21").toString());
                ui->lbl_hs_userinfo_p22->setText(q_hs_userinformation_show.value("p22").toString()); ui->lbl_hs_userinfo_p23->setText(q_hs_userinformation_show.value("p23").toString());
                ui->lbl_hs_userinfo_p24->setText(q_hs_userinformation_show.value("p24").toString()); ui->lbl_hs_userinfo_p25->setText(q_hs_userinformation_show.value("p25").toString());
                ui->lbl_hs_userinfo_p26->setText(q_hs_userinformation_show.value("p26").toString()); ui->lbl_hs_userinfo_p27->setText(q_hs_userinformation_show.value("p27").toString());
                ui->lbl_hs_userinfo_p28->setText(q_hs_userinformation_show.value("p28").toString()); ui->lbl_hs_userinfo_p29->setText(q_hs_userinformation_show.value("p29").toString());

                avatar_url = q_hs_userinformation_show.value("p30").toString();
                QPixmap avatar_from_edit(avatar_url); ui->lbl_hs_userinfo_avatar->setPixmap(avatar_url); ui->lbl_hs_userinfo_avatar->setScaledContents(true);


            }
            //        if(!QFileInfo(avatar_url).exists())
            //        {
            //            QMessageBox::information(this, "","exists user avatar..");
            //            QPixmap avatar_from_edit(avatar_url);   ui->lbl_hs_userinfo_avatar->setPixmap(avatar_url); ui->lbl_hs_userinfo_avatar->setScaledContents(true);
            //        }
            //        else
            //        {
            //            QMessageBox::information(this, "","not exists user avatar..");
            //            QSqlQuery q_search_def_user_avatar("SELECT * FROM adminconfig;");
            //            while(q_search_def_user_avatar.next())
            //            {                avatar_url = q_search_def_user_avatar.value("defualt_avatar").toString();

            //            }
            //            QPixmap avatar_from_edit(avatar_url);   ui->lbl_hs_userinfo_avatar->setPixmap(avatar_url); ui->lbl_hs_userinfo_avatar->setScaledContents(true);
            //        }
//        }

//        else
//        {
//            QMessageBox::critical(this," ","هیچ کاربری انتخاب نشده است.");
//        }
    }
    else
    {
        ui->tabWidget_hs_user_information->setTabEnabled(4,true);
        //load score to tabScore !!!!!
        im_from_students_list=true;
        ui->btn_hs_userinfo_return_to_users_list->setText("بازگشت به لیست دانش آموزان");
        //ui->groupBox_show_users_hs->setTitle("لیست دانش آموزان");
        QSqlQuery q_give_tab_titles("SELECT * FROM tabTitles;");
        while(q_give_tab_titles.next())
        {
            ui->tabWidget_hs_user_information->setTabText(0,q_give_tab_titles.value("tab_show_user_info_0").toString());
            ui->tabWidget_hs_user_information->setTabText(1,q_give_tab_titles.value("tab_show_user_info_1").toString());
            ui->tabWidget_hs_user_information->setTabText(2,q_give_tab_titles.value("tab_show_user_info_2").toString());
            ui->tabWidget_hs_user_information->setTabText(3,q_give_tab_titles.value("tab_show_user_info_3").toString());
            ui->tabWidget_hs_user_information->setTabText(4,q_give_tab_titles.value("tab_show_user_info_4").toString());


        }
        ui->scrollArea_register->ensureVisible(0,0,0,0);
//        if(ui->listWidget_show_users_hs->selectedItems().size() > 0)
//        {
            QString user_code_id ;
                int row = ui->tableWidget_show_users_hs->currentRow();
                int column = ui->tableWidget_show_users_hs->currentColumn();
                QString student_idcode = ui->tableWidget_show_users_hs->model()->index(row,column).data().toString();
                user_code_id = student_idcode;
//            QString name = ui->listWidget_show_users_hs->currentItem()->text();
//            QString user_code_id = name.left(10);
            //do other
            ui->groupBox_show_users_hs->hide();
            ui->groupBox_hs_user_information->show();
            //remove all values from userinformation
            ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
            ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
            ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
            ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
            ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
            ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
            ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
            ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
            ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
            ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
            ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
            ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
            ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
            ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
            ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
            ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
            ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
            ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
            ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
            ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
            ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
            ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
            ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
            ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
            ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
            ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
            ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
            ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
            ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
            ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
            ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();

            //give titles
            QSqlQuery q_Hs_Load_Title("SELECT * FROM studentTitles");
            while (q_Hs_Load_Title.next())
            {
                ui->lbl_hs_userinfo_t0->setText(q_Hs_Load_Title.value("st0").toString()); ui->lbl_hs_userinfo_t1->setText(q_Hs_Load_Title.value("st1").toString()); ui->lbl_hs_userinfo_t2->setText(q_Hs_Load_Title.value("st2").toString()); ui->lbl_hs_userinfo_t3->setText(q_Hs_Load_Title.value("st3").toString()); ui->lbl_hs_userinfo_t4->setText(q_Hs_Load_Title.value("st4").toString());                ui->lbl_hs_userinfo_t5->setText(q_Hs_Load_Title.value("st5").toString()); ui->lbl_hs_userinfo_t6->setText(q_Hs_Load_Title.value("st6").toString());               ui->lbl_hs_userinfo_t7->setText(q_Hs_Load_Title.value("st7").toString());  ui->lbl_hs_userinfo_t8->setText(q_Hs_Load_Title.value("st8").toString());              ui->lbl_hs_userinfo_t9->setText(q_Hs_Load_Title.value("st9").toString()); ui->lbl_hs_userinfo_t10->setText(q_Hs_Load_Title.value("st10").toString());                ui->lbl_hs_userinfo_t11->setText(q_Hs_Load_Title.value("st11").toString()); ui->lbl_hs_userinfo_t12->setText(q_Hs_Load_Title.value("st12").toString()); ui->lbl_hs_userinfo_t13->setText(q_Hs_Load_Title.value("st13").toString());                 ui->lbl_hs_userinfo_t14->setText(q_Hs_Load_Title.value("st14").toString()); ui->lbl_hs_userinfo_t15->setText(q_Hs_Load_Title.value("st15").toString());                ui->lbl_hs_userinfo_t16->setText(q_Hs_Load_Title.value("st16").toString());  ui->lbl_hs_userinfo_t17->setText(q_Hs_Load_Title.value("st17").toString()); ui->lbl_hs_userinfo_t18->setText(q_Hs_Load_Title.value("st18").toString());ui->lbl_hs_userinfo_t19->setText(q_Hs_Load_Title.value("st19").toString());ui->lbl_hs_userinfo_t20->setText(q_Hs_Load_Title.value("st20").toString());ui->lbl_hs_userinfo_t21->setText(q_Hs_Load_Title.value("st21").toString());ui->lbl_hs_userinfo_t22->setText(q_Hs_Load_Title.value("st22").toString());ui->lbl_hs_userinfo_t23->setText(q_Hs_Load_Title.value("st23").toString());ui->lbl_hs_userinfo_t24->setText(q_Hs_Load_Title.value("st24").toString());ui->lbl_hs_userinfo_t25->setText(q_Hs_Load_Title.value("st25").toString());ui->lbl_hs_userinfo_t26->setText(q_Hs_Load_Title.value("st26").toString()); ui->lbl_hs_userinfo_t27->setText(q_Hs_Load_Title.value("st27").toString());ui->lbl_hs_userinfo_t28->setText(q_Hs_Load_Title.value("st28").toString()); ui->lbl_hs_userinfo_t29->setText(q_Hs_Load_Title.value("st29").toString());
            }

            //give data WHERE idcode = database
            QSqlQuery q_hs_userinformation_show("SELECT * FROM students WHERE p0='"+user_code_id+"';");
            while (q_hs_userinformation_show.next())
            {
                ui->lbl_hs_userinfo_p0->setText(q_hs_userinformation_show.value("p0").toString());   ui->lbl_hs_userinfo_p1->setText(q_hs_userinformation_show.value("p1").toString());
                ui->lbl_hs_userinfo_p2->setText(q_hs_userinformation_show.value("p2").toString());   ui->lbl_hs_userinfo_p3->setText(q_hs_userinformation_show.value("p3").toString());
                ui->lbl_hs_userinfo_p4->setText(q_hs_userinformation_show.value("p4").toString());   ui->lbl_hs_userinfo_p5->setText(q_hs_userinformation_show.value("p5").toString());
                ui->lbl_hs_userinfo_p6->setText(q_hs_userinformation_show.value("p6").toString());   ui->lbl_hs_userinfo_p7->setText(q_hs_userinformation_show.value("p7").toString());
                ui->lbl_hs_userinfo_p8->setText(q_hs_userinformation_show.value("p8").toString());   ui->lbl_hs_userinfo_p9->setText(q_hs_userinformation_show.value("p9").toString());
                ui->lbl_hs_userinfo_p10->setText(q_hs_userinformation_show.value("p10").toString()); ui->lbl_hs_userinfo_p11->setText(q_hs_userinformation_show.value("p11").toString());
                ui->lbl_hs_userinfo_p12->setText(q_hs_userinformation_show.value("p12").toString()); ui->lbl_hs_userinfo_p13->setText(q_hs_userinformation_show.value("p13").toString());
                ui->lbl_hs_userinfo_p14->setText(q_hs_userinformation_show.value("p14").toString()); ui->lbl_hs_userinfo_p15->setText(q_hs_userinformation_show.value("p15").toString());
                ui->lbl_hs_userinfo_p16->setText(q_hs_userinformation_show.value("p16").toString()); ui->lbl_hs_userinfo_p17->setText(q_hs_userinformation_show.value("p17").toString());
                ui->lbl_hs_userinfo_p18->setText(q_hs_userinformation_show.value("p18").toString()); ui->lbl_hs_userinfo_p19->setText(q_hs_userinformation_show.value("p19").toString());
                ui->lbl_hs_userinfo_p20->setText(q_hs_userinformation_show.value("p20").toString()); ui->lbl_hs_userinfo_p21->setText(q_hs_userinformation_show.value("p21").toString());
                ui->lbl_hs_userinfo_p22->setText(q_hs_userinformation_show.value("p22").toString()); ui->lbl_hs_userinfo_p23->setText(q_hs_userinformation_show.value("p23").toString());
                ui->lbl_hs_userinfo_p24->setText(q_hs_userinformation_show.value("p24").toString()); ui->lbl_hs_userinfo_p25->setText(q_hs_userinformation_show.value("p25").toString());
                ui->lbl_hs_userinfo_p26->setText(q_hs_userinformation_show.value("p26").toString()); ui->lbl_hs_userinfo_p27->setText(q_hs_userinformation_show.value("p27").toString());
                ui->lbl_hs_userinfo_p28->setText(q_hs_userinformation_show.value("p28").toString()); ui->lbl_hs_userinfo_p29->setText(q_hs_userinformation_show.value("p29").toString());

                avatar_url = q_hs_userinformation_show.value("p30").toString();
                QPixmap avatar_from_edit(avatar_url); ui->lbl_hs_userinfo_avatar->setPixmap(avatar_url); ui->lbl_hs_userinfo_avatar->setScaledContents(true);


            }
            //load title for score_x^10


            ui->listWidget_show_student_scores->hide();

            QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM score_"+ui->lbl_hs_userinfo_p0->text()+";");
            QString count_show_users_hs;
            while(q_count_show_users_hs.next())
                count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

            ui->tableWidget_show_student_scores->setRowCount(count_show_users_hs.toInt());
            ui->tableWidget_show_student_scores->setColumnCount(30);
            ui->tableWidget_show_student_scores->clear();
            QSqlQuery q_guve("SELECT * FROM headers;");
            while(q_guve.next())
            {
               ui->tableWidget_show_student_scores->setHorizontalHeaderLabels(QString(q_guve.value("s0").toString()+";"+q_guve.value("s1").toString()+";"+q_guve.value("s2").toString()+";"+q_guve.value("s3").toString()+";"+q_guve.value("s4").toString()+";"+q_guve.value("s5").toString()+";"+q_guve.value("s6").toString()+";"+q_guve.value("s7").toString()+";"+q_guve.value("s8").toString()+";"+q_guve.value("s9").toString()+";"+q_guve.value("s10").toString()+";"+q_guve.value("s11").toString()+";"+q_guve.value("s12").toString()+";"+q_guve.value("s13").toString()+";"+q_guve.value("s14").toString()+";"+q_guve.value("s15").toString()+";"+q_guve.value("s16").toString()+";"+q_guve.value("s17").toString()+";"+q_guve.value("s18").toString()+";"+q_guve.value("s19").toString()+";"+q_guve.value("s20").toString()+";"+q_guve.value("s21").toString()+";"+q_guve.value("s22").toString()+";"+q_guve.value("s23").toString()+";"+q_guve.value("s24").toString()+";"+q_guve.value("s25").toString()+";"+q_guve.value("s26").toString()+";"+q_guve.value("s27").toString()+";"+q_guve.value("s28").toString()+";"+q_guve.value("s29").toString()+";").split(";"));
            }
            ui->tableWidget_show_student_scores->verticalHeader()->hide();
            ui->tableWidget_show_student_scores->setStyleSheet("color:black;");


            int sss = 0;
            QSqlQuery q_give_scores_of_this_student("SELECT * FROM score_"+ui->lbl_hs_userinfo_p0->text()+";");
            //{
            while(q_give_scores_of_this_student.next())
            {
                ui->tableWidget_show_student_scores->setItem(sss, 0, new QTableWidgetItem(q_give_scores_of_this_student.value("p0").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 1, new QTableWidgetItem(q_give_scores_of_this_student.value("p1").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 2, new QTableWidgetItem(q_give_scores_of_this_student.value("p2").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 3, new QTableWidgetItem(q_give_scores_of_this_student.value("p3").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 4, new QTableWidgetItem(q_give_scores_of_this_student.value("p4").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 5, new QTableWidgetItem(q_give_scores_of_this_student.value("p5").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 6, new QTableWidgetItem(q_give_scores_of_this_student.value("p6").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 7, new QTableWidgetItem(q_give_scores_of_this_student.value("p7").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 8, new QTableWidgetItem(q_give_scores_of_this_student.value("p8").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 9, new QTableWidgetItem(q_give_scores_of_this_student.value("p9").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 10, new QTableWidgetItem(q_give_scores_of_this_student.value("p10").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 11, new QTableWidgetItem(q_give_scores_of_this_student.value("p11").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 12, new QTableWidgetItem(q_give_scores_of_this_student.value("p12").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 13, new QTableWidgetItem(q_give_scores_of_this_student.value("p13").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 14, new QTableWidgetItem(q_give_scores_of_this_student.value("p14").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 15, new QTableWidgetItem(q_give_scores_of_this_student.value("p15").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 16, new QTableWidgetItem(q_give_scores_of_this_student.value("p16").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 17, new QTableWidgetItem(q_give_scores_of_this_student.value("p17").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 18, new QTableWidgetItem(q_give_scores_of_this_student.value("p18").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 19, new QTableWidgetItem(q_give_scores_of_this_student.value("p19").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 20, new QTableWidgetItem(q_give_scores_of_this_student.value("p20").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 21, new QTableWidgetItem(q_give_scores_of_this_student.value("p21").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 22, new QTableWidgetItem(q_give_scores_of_this_student.value("p22").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 23, new QTableWidgetItem(q_give_scores_of_this_student.value("p23").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 24, new QTableWidgetItem(q_give_scores_of_this_student.value("p24").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 25, new QTableWidgetItem(q_give_scores_of_this_student.value("p25").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 26, new QTableWidgetItem(q_give_scores_of_this_student.value("p26").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 27, new QTableWidgetItem(q_give_scores_of_this_student.value("p27").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 28, new QTableWidgetItem(q_give_scores_of_this_student.value("p28").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 29, new QTableWidgetItem(q_give_scores_of_this_student.value("p29").toString()));
                sss++;
//                QString space_between = "\t  ";
//                QString i_will_make_a_package_of_this_student_information =
//                        q_give_scores_of_this_student.value("p0").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p1").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p2").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p3").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p4").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p5").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p6").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p7").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p8").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p9").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p10").toString()+ space_between +
//                        //                            q_give_scores_of_this_student.value("p11").toString()+ space_between +
//                        //                            q_give_scores_of_this_student.value("p12").toString()+ space_between +
//                        //                            q_give_scores_of_this_student.value("p13").toString()+ space_between +
//                        //                            q_give_scores_of_this_student.value("p14").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p15").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p16").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p17").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p18").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p19").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p20").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p21").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p22").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p23").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p24").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p25").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p26").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p27").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p28").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p29").toString();


//                ui->listWidget_show_student_scores->addItem(i_will_make_a_package_of_this_student_information);
            }
            //}
//        }

//        else
//        {
//            QMessageBox::critical(this," ","هیچ کاربری انتخاب نشده است.");
//        }
    }


}

void MainWindow::on_hs_list_users_triggered()
{

    im_from_hs_list = true;
    ui->groupBox_show_users_hs->setTitle("لیست اعضای حسینیه");
    ui->scrollArea_register->ensureVisible(0,0,0,0);

    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();



    //remove all values from userinformation
    ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
    ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
    ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
    ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
    ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
    ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
    ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
    ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
    ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
    ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
    ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
    ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
    ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
    ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
    ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
    ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
    ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
    ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
    ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
    ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
    ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
    ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
    ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
    ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
    ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
    ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
    ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
    ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
    ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
    ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
    ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();

    //--------
    ui->listWidget_show_users_hs->hide();
    ui->titleX->hide();
    ui->tableWidget_show_users_hs->clear();
    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM registration;");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();


   ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_show_users_hs->setColumnCount(4);
    QSqlQuery q_give_titles("SELECT * FROM registrationTitles;");
    QString t0,t1,t2,t3;
    while(q_give_titles.next())
    {
        t0 = q_give_titles.value("t0").toString();
        t1 = q_give_titles.value("t1").toString();
        t2 = q_give_titles.value("t2").toString();
        t3 = q_give_titles.value("t3").toString();
    }
    ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
    ui->tableWidget_show_users_hs->verticalHeader()->hide();
    ui->tableWidget_show_users_hs->setStyleSheet("color:black;");
    QSqlQuery search("SELECT * FROM registration;");
    QString p0,p1,p2,p3;
    int sss = 0;
    while (search.next())
    {
        p0 = search.value("p0").toString();
        p1 = search.value("p1").toString();
        p2 = search.value("p2").toString();
        p3 = search.value("p3").toString();
        ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
        ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
        ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
        ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
        sss++;
    }
    ui->groupBox_show_users_hs->show();
}


void MainWindow::on_btn_hs_userinfo_return_to_users_list_clicked()
{
    if(ui->btn_hs_userinfo_return_to_users_list->text() == "بازگشت به لیست دانش آموزان")
    {
        ui->groupBox_settings->hide();
        ui->groupBox_login->hide();
        ui->groupBox_hs_register->hide();
        ui->groupBox_hs_search_for_edit->hide();
        //    ui->groupBox_send_cmd_to_db->hide();
        //    ui->groupBox_show_users_hs->hide();
        ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->hide();
        //other
        //    ui->groupBox_change_userpass_admin->hide();
        //    ui->groupBox_maxtry_change->hide();
        //    ui->groupBox_currenttry_change->hide();
        //    ui->groupBox_avatar_path_change->hide();
        //    ui->groupBox_history_of_admin_logins_log->hide();


        //remove all values from userinformation
        ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
        ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
        ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
        ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
        ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
        ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
        ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
        ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
        ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
        ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
        ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
        ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
        ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
        ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
        ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
        ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
        ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
        ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
        ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
        ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
        ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
        ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
        ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
        ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
        ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
        ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
        ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
        ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
        ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
        ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
        ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();




        ui->listWidget_show_users_hs->hide();
        ui->titleX->hide();
        ui->tableWidget_show_users_hs->clear();
        QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM students;");
        QString count_show_users_hs;
        while(q_count_show_users_hs.next())
            count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

        ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
        ui->tableWidget_show_users_hs->setColumnCount(4);
        QSqlQuery q_give_titles("SELECT * FROM studentTitles;");
        QString t0,t1,t2,t3;
        while(q_give_titles.next())
        {
            t0 = q_give_titles.value("st0").toString();
            t1 = q_give_titles.value("st1").toString();
            t2 = q_give_titles.value("st2").toString();
            t3 = q_give_titles.value("st3").toString();
        }
        ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
        ui->tableWidget_show_users_hs->verticalHeader()->hide();
        ui->tableWidget_show_users_hs->setStyleSheet("color:black;");
        QSqlQuery search("SELECT * FROM students;");
        QString p0,p1,p2,p3;
        int sss = 0;
        while (search.next())
        {
            p0 = search.value("p0").toString();
            p1 = search.value("p1").toString();
            p2 = search.value("p2").toString();
            p3 = search.value("p3").toString();
            ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
            ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
            ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
            ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
            sss++;
        }
        ui->groupBox_show_users_hs->show();
    }
    else if(ui->btn_hs_userinfo_return_to_users_list->text() == "بازگشت به لیست جستجو")
    {
        ui->groupBox_settings->hide();
        ui->groupBox_login->hide();
        ui->groupBox_hs_register->hide();
        ui->groupBox_hs_search_for_edit->hide();
        ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->hide();
        ui->groupBox_search_result->show();

    }
    else
    {
        ui->groupBox_settings->hide();
        ui->groupBox_login->hide();
        ui->groupBox_hs_register->hide();
        ui->groupBox_hs_search_for_edit->hide();
        //    ui->groupBox_send_cmd_to_db->hide();
        //    ui->groupBox_show_users_hs->hide();
        ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->hide();
        //other
        //    ui->groupBox_change_userpass_admin->hide();
        //    ui->groupBox_maxtry_change->hide();
        //    ui->groupBox_currenttry_change->hide();
        //    ui->groupBox_avatar_path_change->hide();
        //    ui->groupBox_history_of_admin_logins_log->hide();


        //remove all values from userinformation
        ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
        ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
        ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
        ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
        ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
        ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
        ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
        ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
        ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
        ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
        ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
        ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
        ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
        ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
        ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
        ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
        ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
        ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
        ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
        ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
        ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
        ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
        ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
        ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
        ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
        ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
        ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
        ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
        ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
        ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
        ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();


        ui->listWidget_show_users_hs->hide();
        ui->titleX->hide();
        ui->tableWidget_show_users_hs->clear();
        QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM registration;");
        QString count_show_users_hs;
        while(q_count_show_users_hs.next())
            count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

        ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
        ui->tableWidget_show_users_hs->setColumnCount(4);
        QSqlQuery q_give_titles("SELECT * FROM registrationTitles;");
        QString t0,t1,t2,t3;
        while(q_give_titles.next())
        {
            t0 = q_give_titles.value("t0").toString();
            t1 = q_give_titles.value("t1").toString();
            t2 = q_give_titles.value("t2").toString();
            t3 = q_give_titles.value("t3").toString();
        }
        ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
        ui->tableWidget_show_users_hs->verticalHeader()->hide();
        ui->tableWidget_show_users_hs->setStyleSheet("color:black;");
        QSqlQuery search("SELECT * FROM registration;");
        QString p0,p1,p2,p3;
        int sss = 0;
        while (search.next())
        {
            p0 = search.value("p0").toString();
            p1 = search.value("p1").toString();
            p2 = search.value("p2").toString();
            p3 = search.value("p3").toString();
            ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
            ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
            ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
            ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
            sss++;
        }
        ui->groupBox_show_users_hs->show();
    }
}

void MainWindow::on_btn_hs_userinfo_edit_user_clicked()
{
    if(im_from_students_list == true || ui->groupBox_search_result->title() == "جستجو دانش آموزان")
    {
        ui->groupBox_hs_user_information->hide();
        ui->btn_edit_goto_delete_this_user->show();
        //remove everything from form registeration page
        ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
        ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
        ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");


        ui->txt_register_0->setDisabled(true);
        ui->txt_register_0->setToolTip("       نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید  \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > نام یا نام خانوادگی");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش دانش اموز");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");
        edit_user_coming_from_userinfo_btn= true;

        QSqlQuery q_Hs_Load_Title("SELECT * FROM studentTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("st0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("st1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("st2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("st3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("st4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("st5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("st6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("st7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("st8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("st9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("st10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("st11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("st12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("st13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("st14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("st15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("st16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("st17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("st18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("st19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("st20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("st21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("st22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("st23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("st24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("st25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("st26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("st27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("st28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("st29").toString());
        }




        QSqlQuery q_Hs_search_for_edit_by_code_from_userinfo_group("SELECT * FROM students WHERE p0='"+ui->lbl_hs_userinfo_p0->text()+"';");
        while (q_Hs_search_for_edit_by_code_from_userinfo_group.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p0").toString());   ui->txt_register_1->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p1").toString());
            ui->txt_register_2->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p2").toString());   ui->txt_register_3->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p3").toString());
            ui->txt_register_4->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p4").toString());   ui->txt_register_5->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p5").toString());
            ui->txt_register_6->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p6").toString());   ui->txt_register_7->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p7").toString());
            ui->txt_register_8->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p8").toString());   ui->txt_register_9->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p9").toString());
            ui->txt_register_10->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p10").toString()); ui->txt_register_11->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p11").toString());
            ui->txt_register_12->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p12").toString()); ui->txt_register_13->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p13").toString());
            ui->txt_register_14->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p14").toString()); ui->txt_register_15->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p15").toString());
            ui->txt_register_16->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p16").toString()); ui->txt_register_17->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p17").toString());
            ui->txt_register_18->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p18").toString()); ui->txt_register_19->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p19").toString());
            ui->txt_register_20->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p20").toString()); ui->txt_register_21->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p21").toString());
            ui->txt_register_22->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p22").toString()); ui->txt_register_23->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p23").toString());
            ui->txt_register_24->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p24").toString()); ui->txt_register_25->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p25").toString());
            ui->txt_register_26->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p26").toString()); ui->txt_register_27->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p27").toString());
            ui->txt_register_28->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p28").toString()); ui->txt_register_29->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_code_from_userinfo_group.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_code_from_userinfo_group.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url);   ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);


            if(avatar_url == "" || avatar_url == " " || avatar_url.size()<1)
            {
                QSqlQuery q_search_def_user_avatar("SELECT * FROM adminconfig;");
                while(q_search_def_user_avatar.next())
                {                avatar_url = q_search_def_user_avatar.value("defualt_avatar").toString();

                }

            }
        }
        im_from_students_list = false;
    }
    else if(im_from_hs_list == true || ui->groupBox_search_result->title() == "جستجو اعضای حسینیه")
    {
        ui->groupBox_hs_user_information->hide();

        ui->btn_edit_goto_delete_this_user->show();
        //remove everything from form registeration page
        ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
        ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
        ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");


        ui->txt_register_0->setDisabled(true);
        ui->txt_register_0->setToolTip("       نمی توانید فیلد شرط را تغییر دهید برای ویرایش این فیلد از روش جستجوی دیگری استفاده کنید  \nراهنما :‌   جستجو در حسینیه >‌ روش جستجو > نام یا نام خانوادگی");
        ui->groupBox_hs_register->show();
        ui->groupBox_hs_register->setTitle("فرم ویرایش اعضای حسینیه");
        ui->btn_register_insert->setText("ویرایش");
        ui->btn_register_clear->setText("انصراف");
        edit_user_coming_from_userinfo_btn= true;

        QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
        while (q_Hs_Load_Title.next())
        {
            ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
            //dbDynamic_disable_status_Text use this  disable_status
            //        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
            //        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
            //        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
            //        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
            //        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
            //        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
            //        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
            //        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
            const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
            if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
            const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
            if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
            const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
            if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
            const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
            if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
            const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
            if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
            const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
            if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
            const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
            if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
            const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
            if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
            const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
            if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
            const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
            if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
            const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
            if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
            const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
            if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
            const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
            if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
            const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
            if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
            const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
            if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
            const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
            if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
            const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
            if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
            const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
            if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
            const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
            if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
            const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
            if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
            const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
            if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
            const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
            if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
            const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
            if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
            const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
            if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
            const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
            if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
            const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
            if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
        }




        QSqlQuery q_Hs_search_for_edit_by_code_from_userinfo_group("SELECT * FROM registration WHERE p0='"+ui->lbl_hs_userinfo_p0->text()+"'");
        while (q_Hs_search_for_edit_by_code_from_userinfo_group.next())
        {
            ui->txt_register_0->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p0").toString());   ui->txt_register_1->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p1").toString());
            ui->txt_register_2->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p2").toString());   ui->txt_register_3->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p3").toString());
            ui->txt_register_4->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p4").toString());   ui->txt_register_5->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p5").toString());
            ui->txt_register_6->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p6").toString());   ui->txt_register_7->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p7").toString());
            ui->txt_register_8->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p8").toString());   ui->txt_register_9->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p9").toString());
            ui->txt_register_10->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p10").toString()); ui->txt_register_11->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p11").toString());
            ui->txt_register_12->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p12").toString()); ui->txt_register_13->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p13").toString());
            ui->txt_register_14->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p14").toString()); ui->txt_register_15->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p15").toString());
            ui->txt_register_16->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p16").toString()); ui->txt_register_17->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p17").toString());
            ui->txt_register_18->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p18").toString()); ui->txt_register_19->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p19").toString());
            ui->txt_register_20->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p20").toString()); ui->txt_register_21->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p21").toString());
            ui->txt_register_22->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p22").toString()); ui->txt_register_23->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p23").toString());
            ui->txt_register_24->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p24").toString()); ui->txt_register_25->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p25").toString());
            ui->txt_register_26->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p26").toString()); ui->txt_register_27->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p27").toString());
            ui->txt_register_28->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p28").toString()); ui->txt_register_29->setText(q_Hs_search_for_edit_by_code_from_userinfo_group.value("p29").toString());
            for_rename_avatar_lastusername_is_here = q_Hs_search_for_edit_by_code_from_userinfo_group.value("p0").toString();
            avatar_url = q_Hs_search_for_edit_by_code_from_userinfo_group.value("p30").toString();
            QPixmap avatar_from_edit(avatar_url);   ui->lbl_register_avatar->setPixmap(avatar_url); ui->lbl_register_avatar->setScaledContents(true);


            if(avatar_url == "" || avatar_url == " " || avatar_url.size()<1)
            {
                QSqlQuery q_search_def_user_avatar("SELECT * FROM adminconfig;");
                while(q_search_def_user_avatar.next())
                {                avatar_url = q_search_def_user_avatar.value("defualt_avatar").toString();

                }

            }
        }
        im_from_hs_list = false;
    }
    else
    {
        QMessageBox::information(this," ","error code is 200!");
    }
}

void MainWindow::on_btn_edit_goto_delete_this_user_clicked()
{

    ui->scrollArea_register->ensureVisible(0,0,0,0);
    if(ui->groupBox_hs_register->title() == "فرم ویرایش اعضای حسینیه")
    {
        QString the_box_for_check_variable;
        QSqlQuery q_delete_user_from_edit_page_btn("DELETE FROM registration WHERE p0='"+ui->txt_register_0->text()+"'");
        QSqlQuery search_for_other_sides_used_this_avatar("SELECT * FROM students WHERE p30='"+address_avatar_hs_users+ui->txt_register_0->text()+avatar_format+"';");
        while(search_for_other_sides_used_this_avatar.next())
        {
            the_box_for_check_variable = search_for_other_sides_used_this_avatar.value("p30").toString();
        }
        if(the_box_for_check_variable.size() > 1)
        {
            if(QMessageBox::question(this," ","عکس این دانش اموز توسط بخش دیگری درحال استفاده میباشد"
                                     "\tآیا میخواید همراه حذف این دانش اموز عکس هم پاک شود؟"
                                     "\tتوصیه میشود جهت خراب نشدن بخش های دیگر خیر را انتخاب کنید.") == QMessageBox::Yes)
            {
                QFile::remove(address_avatar_hs_users+ui->txt_register_0->text()+avatar_format);
                QMessageBox::information(this," ","عکس دانش آموز با موفیقت حذف شد.");
            }
        }




        QMessageBox::information(this," ",
                                 "کاربر "+ui->txt_register_1->text()+"  "+ui->txt_register_2->text()+
                                 " با کدملی"
                                 " "+ui->txt_register_0->text()+
                                 "با موفیقت حذف شد.");


        ui->groupBox_hs_register->hide();
        //remove everything from form registeration page
        ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
        ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
        ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");

        ui->listWidget_show_users_hs->hide();
        ui->titleX->hide();
        ui->tableWidget_show_users_hs->clear();
        QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM registration;");
        QString count_show_users_hs;
        while(q_count_show_users_hs.next())
            count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

        ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
        ui->tableWidget_show_users_hs->setColumnCount(4);
        QSqlQuery q_give_titles("SELECT * FROM registrationTitles;");
        QString t0,t1,t2,t3;
        while(q_give_titles.next())
        {
            t0 = q_give_titles.value("t0").toString();
            t1 = q_give_titles.value("t1").toString();
            t2 = q_give_titles.value("t2").toString();
            t3 = q_give_titles.value("t3").toString();
        }
        ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
        ui->tableWidget_show_users_hs->verticalHeader()->hide();
        ui->tableWidget_show_users_hs->setStyleSheet("color:black;");
        QSqlQuery search("SELECT * FROM registration;");
        QString p0,p1,p2,p3;
        int sss = 0;
        while (search.next())
        {
            p0 = search.value("p0").toString();
            p1 = search.value("p1").toString();
            p2 = search.value("p2").toString();
            p3 = search.value("p3").toString();
            ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
            ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
            ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
            ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
            sss++;
        }
        ui->groupBox_show_users_hs->show();
    }
    else
    {
        QString the_box_for_check_variable;
        QSqlQuery q_delete_score_table_student("DROP TABLE score_"+ui->txt_register_0->text()+";");
        QMessageBox::information(this," ","نمرات دانش آموز با موفیقت حذف شد." );

        QSqlQuery q_delete_user_from_edit_page_btn("DELETE FROM students WHERE p0='"+ui->txt_register_0->text()+"'");
        QSqlQuery search_for_other_sides_used_this_avatar("SELECT * FROM registration WHERE p30='"+address_avatar_hs_users+ui->txt_register_0->text()+avatar_format+"';");

        while(search_for_other_sides_used_this_avatar.next())
        {
            the_box_for_check_variable = search_for_other_sides_used_this_avatar.value("p30").toString();
        }
        if(the_box_for_check_variable.size() > 1)
        {
            if(QMessageBox::question(this," ","عکس این دانش اموز توسط بخش دیگری درحال استفاده میباشد"
                                     "\tآیا میخواید همراه حذف این دانش اموز عکس هم پاک شود؟"
                                     "\tتوصیه میشود جهت خراب نشدن بخش های دیگر خیر را انتخاب کنید.") == QMessageBox::Yes)
            {
                QFile::remove(address_avatar_hs_users+ui->txt_register_0->text()+avatar_format);
                QMessageBox::information(this," ","عکس دانش آموز با موفیقت حذف شد.");
            }
        }

        QMessageBox::information(this," ",
                                 "کاربر "+ui->txt_register_1->text()+"  "+ui->txt_register_2->text()+
                                 " با کدملی"
                                 " "+ui->txt_register_0->text()+
                                 "با موفیقت حذف شد.");


        ui->groupBox_hs_register->hide();
        //remove everything from form registeration page
        ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
        ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
        ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");

        ui->listWidget_show_users_hs->hide();
        ui->titleX->hide();
        ui->tableWidget_show_users_hs->clear();
        QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM students;");
        QString count_show_users_hs;
        while(q_count_show_users_hs.next())
            count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

        ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
        ui->tableWidget_show_users_hs->setColumnCount(4);
        QSqlQuery q_give_titles("SELECT * FROM studentTitles;");
        QString t0,t1,t2,t3;
        while(q_give_titles.next())
        {
            t0 = q_give_titles.value("st0").toString();
            t1 = q_give_titles.value("st1").toString();
            t2 = q_give_titles.value("st2").toString();
            t3 = q_give_titles.value("st3").toString();
        }
        ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
        ui->tableWidget_show_users_hs->verticalHeader()->hide();
        ui->tableWidget_show_users_hs->setStyleSheet("color:black;");
        QSqlQuery search("SELECT * FROM students;");
        QString p0,p1,p2,p3;
        int sss = 0;
        while (search.next())
        {
            p0 = search.value("p0").toString();
            p1 = search.value("p1").toString();
            p2 = search.value("p2").toString();
            p3 = search.value("p3").toString();

            ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
            ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
            ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
            ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
            sss++;
        }
        ui->groupBox_show_users_hs->show();
    }
}

void MainWindow::on_btn_change_user_pass_admin_clicked()
{
    ui->btn_show_adminloginslog_from_config->hide();
    ui->btn_return_home_from_config->hide();
    ui->groupBox_change_show->hide();
    ui->groupBox_change_database->hide();
    ui->txt_username_forchange->clear();
    ui->txt_password_forchange->clear();
    ui->groupBox_change_userpass_admin->show(); //will hide
    ui->groupBox_change_userpass_admin->setGeometry(100,130,511,171);
}

void MainWindow::on_btn_next_to_changeuserpass_clicked()
{
    if(ui->groupBox_change_userpass_admin->title() == "نام کاربری و کلمه عبور فعلی را وارد کنید")
    {
        QSqlQuery change_username_and_password("SELECT username,password FROM adminconfig;");
        while (change_username_and_password.next())
        {
            const QString username_will_be_change = change_username_and_password.value("username").toString();
            const QString password_will_be_change = change_username_and_password.value("password").toString();//HASH

            if(ui->txt_username_forchange->text() == username_will_be_change && ui->txt_password_forchange->text() == password_will_be_change)
            {
                ui->txt_password_forchange->setEchoMode(QLineEdit::Normal);
                ui->groupBox_change_userpass_admin->setTitle("نام کاربری و کلمه عبور جدید را وارد کنید");
                ui->btn_next_to_changeuserpass->setText("ثبت");
                ui->txt_username_forchange->clear();
                ui->txt_password_forchange->clear();
            }
            else
            {
                QMessageBox::critical(this," ","نام کاربری یا کلمه عبور اشتباه است");
            }
        }
    }
    else if(ui->groupBox_change_userpass_admin->title() == "نام کاربری و کلمه عبور جدید را وارد کنید" && ui->btn_next_to_changeuserpass->text() == "ثبت")
    {
        QSqlQuery update_new_user_admin_to_adminconfig("UPDATE adminconfig SET username='"+ui->txt_username_forchange->text()+"'");
        QSqlQuery update_new_pass_admin_to_adminconfig("UPDATE adminconfig SET password='"+ui->txt_password_forchange->text()+"'");
        QMessageBox::information(this," ","نام کاربری و کلمه عبور با موفقیت ویرایش شد");
        //this->close();
        ui->groupBox_change_userpass_admin->hide();
        ui->groupBox_change_show->show();
        ui->groupBox_change_database->show();
        ui->btn_show_adminloginslog_from_config->show();
        ui->btn_return_home_from_config->show();
    }
}

void MainWindow::on_btn_cancel_to_changeuserpass_clicked()
{
    ui->groupBox_change_userpass_admin->hide();
    ui->btn_show_adminloginslog_from_config->show();
    ui->btn_return_home_from_config->show();
    ui->groupBox_change_show->show();
    ui->groupBox_change_database->show();
}

void MainWindow::on_btn_change_maxtry_login_clicked()
{
    ui->btn_show_adminloginslog_from_config->hide();
    ui->btn_return_home_from_config->hide();

    ui->groupBox_change_show->hide();
    ui->groupBox_change_database->hide();
    ui->txt_new_value_for_maxtry->clear();
    ui->lbl_current_maxtry_value->clear();
    ui->groupBox_maxtry_change->setGeometry(100,130,511,171);
    ui->groupBox_maxtry_change->show();
    QSqlQuery change_maxtry("SELECT maxtry FROM adminconfig;");
    while (change_maxtry.next())
    {

        const QString show_value_of_maxtryValue = change_maxtry.value("maxtry").toString();
        ui->lbl_current_maxtry_value->setText(show_value_of_maxtryValue);
    }
}

void MainWindow::on_btn_edit_and_save_maxtry_clicked()
{
    if(ui->txt_new_value_for_maxtry->text().size() >0)
    {
        QSqlQuery update_maxtry_to_adminconfig("UPDATE adminconfig SET maxtry='"+ui->txt_new_value_for_maxtry->text()+"'");
        QMessageBox::information(this," ","مقدار حداکثر تلاش برای ورود با موفقیت ویرایش شد.");
        ui->groupBox_maxtry_change->hide();
        ui->btn_show_adminloginslog_from_config->show();
        ui->btn_return_home_from_config->show();
        ui->groupBox_change_show->show();
        ui->groupBox_change_database->show();
    }
    else
    {
        QMessageBox::critical(this," ","باید یک مقدار وارد کنید");
    }
}

void MainWindow::on_btn_cancel_maxtry_clicked()
{
    ui->txt_new_value_for_maxtry->clear();
    ui->lbl_current_maxtry_value->clear();

    ui->groupBox_maxtry_change->hide();
    ui->groupBox_change_show->show();
    ui->groupBox_change_database->show();
    ui->btn_show_adminloginslog_from_config->show();
    ui->btn_return_home_from_config->show();
}

void MainWindow::on_btn_change_currenttry_login_clicked()
{
    ui->txt_new_value_for_currenttry->clear();
    ui->lbl_current_currenttry_value->clear();
    ui->btn_show_adminloginslog_from_config->hide();
    ui->btn_return_home_from_config->hide();

    ui->groupBox_change_show->hide();
    ui->groupBox_change_database->hide();
    ui->groupBox_currenttry_change->setGeometry(100,130,511,171);
    ui->groupBox_currenttry_change->show();
    QSqlQuery change_maxtry("SELECT currenttry FROM adminconfig;");
    while (change_maxtry.next())
    {
        const QString show_value_of_maxtryValue = change_maxtry.value("currenttry").toString();
        ui->lbl_current_currenttry_value->setText(show_value_of_maxtryValue);
    }
}

void MainWindow::on_btn_edit_and_save_currenttry_clicked()
{
    if(ui->txt_new_value_for_currenttry->text().size() >0)
    {
        QSqlQuery update_maxtry_to_adminconfig("UPDATE adminconfig SET currenttry='"+ui->txt_new_value_for_currenttry->text()+"'");
        QMessageBox::information(this," ","مقدار  خطاهای موجود در ورود با موفیقت ویرایش شد.");
        ui->txt_new_value_for_currenttry->clear();
        ui->lbl_current_value_avatar_path_value->clear();
        ui->groupBox_currenttry_change->hide();
        ui->btn_show_adminloginslog_from_config->show();
        ui->btn_return_home_from_config->show();
        ui->groupBox_change_show->show();
        ui->groupBox_change_database->show();
    }
    else
    {
        QMessageBox::critical(this," ","باید یک مقدار وارد کنید");
    }
}

void MainWindow::on_btn_cancel_currenttry_clicked()
{
    ui->txt_new_value_for_currenttry->clear();
    ui->lbl_current_currenttry_value->clear();
    ui->groupBox_currenttry_change->hide();
    ui->groupBox_change_show->show();
    ui->btn_show_adminloginslog_from_config->show();
    ui->btn_return_home_from_config->show();
    ui->groupBox_change_database->show();
}

void MainWindow::on_btn_change_path_defualt_avatar_of_user_clicked()
{
    ui->btn_show_adminloginslog_from_config->hide();
    ui->btn_return_home_from_config->hide();

    ui->lbl_current_value_avatar_path_value->clear();
    ui->lbl_new_value_avatar_path_value->clear();
    ui->groupBox_change_show->hide();
    ui->groupBox_change_database->hide();
    ui->groupBox_avatar_path_change->setGeometry(70,30,561,331);
    ui->groupBox_avatar_path_change->show();
    QSqlQuery q_current_avatar_path("SELECT defualt_avatar FROM adminconfig;");
    while (q_current_avatar_path.next())
    {
        const QString show_value_of_current_avatar_path = q_current_avatar_path.value("defualt_avatar").toString();
        ui->lbl_current_value_avatar_path_value->setText(show_value_of_current_avatar_path);
        QPixmap set_current_path_avatar_to_preview(show_value_of_current_avatar_path);
        ui->lbl_avatar_current_from_avatar_path_change->setPixmap(show_value_of_current_avatar_path);
        ui->lbl_avatar_current_from_avatar_path_change->setScaledContents(true);
    }
}

void MainWindow::on_btn_edit_and_save_avatar_path_change_clicked()
{
    //    QMessageBox::information(this,"راهنما",
    //                             "برای جلوگیری از هرگونه تداخل در باگیری تصویر  \nتوجه داشته باشید که تصویر مورد نظر در یک فایل ثابت(ایمن) ذخیر کرده باشید. ");
    QString url_and_filename_avatar_for_default_path = QFileDialog::getOpenFileName(this,   tr("تصویر مورد نظر را انتخاب کنید"), "/", tr("Image Files (*.jpg)"));


    QString formatof = "";
    if(url_and_filename_avatar_for_default_path.endsWith(avatar_format) == true || url_and_filename_avatar_for_default_path.endsWith(avatar_format.toUpper()) == true)
        formatof = avatar_format;



    QFile::remove(defualt_avatar_hs_users+"defualt"+avatar_format);
    QFile::remove(defualt_avatar_hs_users+"defualt"+avatar_format.toUpper());




    QFile::copy(url_and_filename_avatar_for_default_path, defualt_avatar_hs_users+"defualt"+formatof);
    avatar_url = defualt_avatar_hs_users+"defualt"+formatof;

    //code9

    QPixmap pm(defualt_avatar_hs_users+ui->txt_register_0->text()+formatof);

    ui->lbl_new_value_avatar_path_value->setText(defualt_avatar_hs_users+"defualt"+formatof);

    ui->lbl_avatar_new_from_avatar_path_change->setPixmap(defualt_avatar_hs_users+"defualt"+formatof);
    ui->lbl_avatar_new_from_avatar_path_change->setScaledContents(true);
    //this new path update to adminconfig as default_avatar
    QSqlQuery avatar_new_path_defualt_will_save_as_adminconfig("UPDATE adminconfig SET defualt_avatar='"+defualt_avatar_hs_users+"defualt"+formatof+"'");
    QMessageBox::information(this," ","آدرس پیش فرض کاربر با موفقیت ویرایش شد");
    ui->lbl_avatar_current_from_avatar_path_change->clear();
    ui->lbl_current_value_avatar_path_value->clear();

    ui->lbl_new_value_avatar_path_value->clear();
    ui->lbl_avatar_new_from_avatar_path_change->clear();
    ui->groupBox_avatar_path_change->hide();
    ui->groupBox_send_cmd_to_db->hide();
    ui->btn_show_adminloginslog_from_config->show();
    ui->btn_return_home_from_config->show();
    ui->groupBox_change_show->show();
    ui->groupBox_change_database->show();
}

void MainWindow::on_btn_cancel_avatar_path_change_clicked()
{
    ui->lbl_avatar_current_from_avatar_path_change->clear();
    ui->lbl_current_value_avatar_path_value->clear();
    ui->lbl_new_value_avatar_path_value->clear();
    ui->lbl_avatar_new_from_avatar_path_change->clear();
    ui->groupBox_avatar_path_change->hide();
    ui->groupBox_send_cmd_to_db->hide();
    ui->btn_show_adminloginslog_from_config->show();
    ui->btn_return_home_from_config->show();
    ui->groupBox_change_show->show();
    ui->groupBox_change_database->show();
}

bool user_checked_adminloginslog_question = false;
void MainWindow::on_btn_show_adminloginslog_from_config_clicked()
{
    if(user_checked_adminloginslog_question == false)
    {
        ui->btn_return_home_from_config->hide();
        ui->btn_show_adminloginslog_from_config->hide();
        ui->groupBox_send_cmd_to_db->hide();
        ui->groupBox_change_show->hide();
        ui->groupBox_change_database->hide();
        ui->groupBox_history_of_admin_logins_log->setGeometry(150,30,381,381);
        ui->groupBox_history_of_admin_logins_log->show();

        QSqlQuery q_give_total_logins_from_adminconfig_for_loginslog("SELECT total_logins FROM adminconfig;");
        while (q_give_total_logins_from_adminconfig_for_loginslog.next())
        {
            const QString give_to_tmp_this_total_logins = q_give_total_logins_from_adminconfig_for_loginslog.value("total_logins").toString();
            ui->lbl_show_total_logins_at_adminloginslog->setText("مجموع ورودها : "+give_to_tmp_this_total_logins);
        }

        QSqlQuery q_give_data_from_adminloginslog("SELECT login_number,login_date FROM adminloginslog;");
        while(q_give_data_from_adminloginslog.next())
        {
            QString number_login_a = q_give_data_from_adminloginslog.value("login_number").toString();
            QString number_date_a = q_give_data_from_adminloginslog.value("login_date").toString();

            QHBoxLayout *horizonLayout_for_adminloginslog =new QHBoxLayout();
            QLabel *label_for_login_number_adminloginslog = new QLabel(number_login_a);
            QLabel *label_for_login_date_adminloginslog = new QLabel(number_date_a);

            horizonLayout_for_adminloginslog->addWidget(label_for_login_date_adminloginslog);
            horizonLayout_for_adminloginslog->addWidget(label_for_login_number_adminloginslog);

            ui->verticalLayout_base_of_log_labels->addLayout(horizonLayout_for_adminloginslog);
        }
        user_checked_adminloginslog_question = true;
    }
    else
    {
        ui->btn_return_home_from_config->hide();
        ui->btn_show_adminloginslog_from_config->hide();
        ui->groupBox_send_cmd_to_db->hide();
        ui->groupBox_change_show->hide();
        ui->groupBox_change_database->hide();
        ui->groupBox_history_of_admin_logins_log->setGeometry(150,30,381,381);
        ui->groupBox_history_of_admin_logins_log->show();
    }

}

void MainWindow::on_btn_exit_from_hisotry_adminloginslog_clicked()
{

    //    ui->scrollArea_adminlogins_log->horizontalScrollBar()->setValue(0);
    //    ui->scrollArea_adminlogins_log->verticalScrollBar();
    ui->scrollArea_adminlogins_log->ensureVisible(0,0, 0, 0);

    ui->groupBox_history_of_admin_logins_log->hide();
    //
    ui->btn_return_home_from_config->show();
    ui->btn_show_adminloginslog_from_config->show();

    ui->groupBox_change_database->show();
    ui->groupBox_change_show->show();

}

void MainWindow::on_btn_return_home_from_config_clicked()
{
    ui->groupBox_settings->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_action_settings_and_configuration_triggered()
{

//    QSqlQuery q_give_text_title_class_list("SELECT * FROM ;");
//    while(q_give_text_title_class_list.next())
//        ui->txt_change_title_class_list->setText(q_give_text_title_class_list.value("t_class_list").toString());

    QSqlQuery q_give_tab_titles("SELECT * FROM tabTitles;");
    while(q_give_tab_titles.next())
    {
        ui->tabWidget_settings->setTabText(0,q_give_tab_titles.value("tab_settings_0").toString());
        ui->tabWidget_settings->setTabText(1,q_give_tab_titles.value("tab_settings_1").toString());
    }



    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();
    //other
    ui->groupBox_change_window_title->hide();
    ui->groupBox_change_userpass_admin->hide(); ui->groupBox_maxtry_change->hide();
    ui->groupBox_avatar_path_change->hide(); ui->groupBox_currenttry_change->hide();
    ui->groupBox_send_cmd_to_db->hide(); ui->groupBox_history_of_admin_logins_log->hide();
    ui->groupBox_db_backup_config->hide();
    ui->groupBox_resetfactory_tables->hide();




    //hide button settings->forms->disable-hs!
    ui->btn_hs_set_disable->hide();
    ui->groupBox_settings->show();
    ui->groupBox_change_show->show();
    ui->groupBox_change_database->show();
}

void MainWindow::on_btn_restore_all_tbls_clicked()
{/*
    ui->groupBox_change_database->hide();
    ui->groupBox_change_show->hide();
    ui->btn_return_home_from_config->hide();
    ui->btn_show_adminloginslog_from_config->hide();
    ui->groupBox_resetfactory_tables->show();*/


    //mysql version !
    //    if(QMessageBox::question(this," ","آیا از بازگرداندن تمام اطلاعات سرور به روز اول (حذف) اطمینان دارید ؟") == QMessageBox::Yes)
    //    {
    //        QMessageBox::warning(this," ","لطفا تا دریافت تایید اتمام عمیلیات چهار مرحله ای صبر کنید");
    //        //make registration
    //        QSqlQuery droptblregistration("DROP TABLE registration;");
    //        QSqlQuery createTable("CREATE TABLE registration("
    //                              "p0 double NOT NULL,"
    //                              "PRIMARY KEY (p0));");
    //        for(int i=1;i<=29;i++)
    //        {
    //            QSqlQuery alterTable("ALTER TABLE registration ADD p"+QString::number(i)+" varchar(500);");
    //        }
    //        QSqlQuery alterTable("ALTER TABLE registration ADD p30 varchar(1000);");
    //        //-----------------------
    //        QMessageBox::information(this," ","(1/4) OK."
    //                                 "\n"
    //                                 "جدول اعضای حسینیه با موفقیت حذف شد"
    //                                 "\n"
    //                                 "لطفا تا پایان عملیات صبرکنید...");



    //        //make registrationTitles
    //        QSqlQuery droptblregistraionTitles("DROP TABLE registrationTitles;");
    //        QSqlQuery createTable_registrationTitles("CREATE TABLE registrationTitles(t0 VARCHAR(120));");
    //        for(int i=0;i<=29;i++)
    //        {
    //            QSqlQuery createTitles("ALTER TABLE registrationTitles ADD t"+QString::number(i)+" varchar(120);");
    //            QSqlQuery createDisabelStats("ALTER TABLE registrationTitles ADD disable_status"+QString::number(i)+" varchar(5);");
    //        }
    //        //defualt values
    //        QSqlQuery updateDefualtValuesToTitleForRegistraion("INSERT INTO `registrationTitles` (`t0`, `t1`, `t2`, `t3`, `t4`, `t5`, `t6`, `t7`, `t8`, `t9`, `t10`, `t11`, `t12`, `t13`, `t14`, `t15`, `t16`, `t17`, `t18`, `t19`, `t20`, `t21`, `t22`, `t23`, `t24`, `t25`, `t26`, `t27`, `t28`, `t29`, `disable_status0`, `disable_status1`, `disable_status2`, `disable_status3`, `disable_status4`, `disable_status5`, `disable_status6`, `disable_status7`, `disable_status8`, `disable_status9`, `disable_status10`, `disable_status11`, `disable_status12`, `disable_status13`, `disable_status14`, `disable_status15`, `disable_status16`, `disable_status17`, `disable_status18`, `disable_status19`, `disable_status20`, `disable_status21`, `disable_status22`, `disable_status23`, `disable_status24`, `disable_status25`, `disable_status26`, `disable_status27`, `disable_status28`, `disable_status29`) VALUES ('NULL', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);");
    //        //update and set default values
    //        for(int i=0;i<=29;i++)
    //        {
    //            QSqlQuery updateDefualtValuesToDisableStatusForRegistraion("UPDATE registrationTitles SET disable_status"+QString::number(i)+"='false'");
    //            QSqlQuery updateDefualtValuesToTitlesForRegistraion("UPDATE registrationTitles SET t"+QString::number(i)+"='t"+QString::number(i)+"'");
    //        }
    //        //-----------------------
    //        QMessageBox::information(this," ","(2/4) OK."
    //                                 "\n"
    //                                 "جدول عنوان (اعضای حسینیه) با موفیقت حذف شد"
    //                                 "\n"
    //                                 "لطفا تا پایان عملیات صبرکنید...");


    //        //make adminconfig
    //        QSqlQuery dropAdminConfig("DROP TABLE adminconfig;");
    //        QSqlQuery createAdminConfig("CREATE TABLE adminconfig(username VARCHAR(120),password VARCHAR(120),maxtry VARCHAR(10),currenttry VARCHAR(10),total_logins VARCHAR(1001),defualt_avatar VARCHAR(700));");
    //        QSqlQuery makeDefaultValuesToAdminCofnfig("INSERT INTO adminconfig (username,password,maxtry,currenttry,total_logins,defualt_avatar) VALUES ('admin','admin','5','0','0','NULL');");

    //    QSqlQuery add_new_update_with_none_command_up_autobackup("ALTER TABLE adminconfig ADD db_auto_backup VARCHAR(10);");
    //    cout << "db_auto_backup added." <<endl;
    //    QSqlQuery add_new_update_with_none_command_up_pathbackup("ALTER TABLE adminconfig ADD db_path_backup VARCHAR(300);");
    //    cout << "db_path_backup added." <<endl;
    //    QSqlQuery updateever ("UPDATE adminconfig SET db_path_backup='C:/Users/Public/Documents'");
    //    QSqlQuery newnewnew("UPDATE adminconfig SET db_auto_backup='open'");
    //        //-----------------------
    //        QMessageBox::information(this," ","(3/4) OK."
    //                                 "\n"
    //                                 "جدول پیکربندی با موفقیت حذف شد"
    //                                 "\n"
    //                                 "لطفا تا پایان عملیات صبرکنید...");


    //        //make adminloginslog
    //        QSqlQuery drop_table_adminloginslog("DROP TABLE adminloginslog;");
    //        QSqlQuery createTableAdminloginslog("CREATE TABLE adminloginslog(login_number VARCHAR(1000), login_date VARCHAR(200));");
    //        QSqlQuery add_Default_value_to_adminsloginlog("INSERT INTO adminloginslog (login_number,login_date) VALUES ('login_0','unknow date');");
    //        //-----------------------
    //        QMessageBox::information(this," ","(4/4) OK."
    //                                 "\n"
    //                                 "جدول تاریخچه ورود مدیر با موفیقت حذف شد"
    //                                 "\n");

    //        //reset totall adminslogin
    //        //QSqlQuery update_total_logins("UPDATE adminconfig SET total_logins='0';");
    //        //-----------------------

    //        //unblock admin account
    //        //QSqlQuery ubblock_admin("UPDATE adminconfig SET currenttry='0';");
    //        //-----------------------
    //        QMessageBox::information(this," ","تشکر از صبر شما"
    //                                 "\n"
    //                                 "تمامی جداول با موفقیت حذف و دوباره ساخته شدند");
    //    }
    //    else
    //    {
    //        //nothing..
    //    }
}

void MainWindow::on_btn_info_database_clicked()
{
    QMessageBox::information(this," ","اطلاعات پایگاه داده :"
                                      "\n"
                                      "Database Type: SQLite"
                                      "\n"
                                      "Database Name: hs.db");
}

void MainWindow::on_btn_cmd_to_database_clicked()
{
    if(QMessageBox::question(this," ", "آیا از ورود به بخش ارسال دستور به پایگاه داده اطمینان دارید ؟") == QMessageBox::Yes)
    {
        QMessageBox::critical(this," ","توجه داشته باشید ممکن است با اجرای دستور اشتباه و نسنجیده "
                                       "\n"
                                       "اطلاعات/جداول/دیتابیس یا برخی تنظیمات حذف یا حتی غیرقابل بازگشت بشوند"
                                       "\n");
        ui->groupBox_change_database->hide();
        ui->groupBox_change_show->hide();
        ui->btn_return_home_from_config->hide();
        ui->btn_show_adminloginslog_from_config->hide();
        //other hide..
        //ui->groupBox_settings->show();
        ui->groupBox_login->hide();
        ui->groupBox_hs_register->hide();
        ui->groupBox_hs_search_for_edit->hide();
        ui->groupBox_show_users_hs->hide();
        ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->hide();
        //other
        ui->groupBox_change_userpass_admin->hide();
        ui->groupBox_maxtry_change->hide();
        ui->groupBox_currenttry_change->hide();
        ui->groupBox_avatar_path_change->hide();
        ui->groupBox_history_of_admin_logins_log->hide();
        ui->groupBox_send_cmd_to_db->show();

    }
    else
    {
        //nothing
    }





}

void MainWindow::on_btn_send_cmd_to_db_clicked()
{
    if(ui->txt_cmd_to_db->text().size() >0)
    {
        if(QMessageBox::question(this," ", "آیا دستور زیر صحیح است و به پایگاه داده ارسال شود ؟"
                                 "\n"+ui->txt_cmd_to_db->text()) == QMessageBox::Yes)
        {
            QSqlQuery send_command_from_settings(ui->txt_cmd_to_db->text());
            QMessageBox::information(this," ", "دستور :"
                                               "\n"
                                     +ui->txt_cmd_to_db->text()+
                                     "\n"
                                     "با موفیقت به سرور ارسال شد."
                                     "\n"
                                     "در صورتی که تغییراتی که میخواستید اعمال نشده است"
                                     "\n"
                                     "از درست بودن و نداشتن اشکال دستور خود اطمینان حاصل فرمایید");


            //cancel and back to other
            ui->txt_cmd_to_db->clear();

            ui->groupBox_send_cmd_to_db->hide();
            ui->groupBox_login->hide();
            ui->groupBox_hs_register->hide();
            ui->groupBox_hs_search_for_edit->hide();
            ui->groupBox_show_users_hs->hide();
            ui->groupBox_hs_user_information->hide();
            ui->groupBox_home->hide();
            //other
            ui->groupBox_change_userpass_admin->hide();
            ui->groupBox_maxtry_change->hide();
            ui->groupBox_currenttry_change->hide();
            ui->groupBox_avatar_path_change->hide();
            ui->groupBox_history_of_admin_logins_log->hide();
            ui->groupBox_settings->show();
            ui->groupBox_change_database->show();
            ui->groupBox_change_show->show();
            ui->btn_return_home_from_config->show();
            ui->btn_show_adminloginslog_from_config->show();

        }
        else
        {
            ui->txt_cmd_to_db->clear();
        }
    }
    else
    {
        QMessageBox::critical(this," ","دستور نامتبر");
    }
}

void MainWindow::on_btn_cancel_send_cmd_to_db_clicked()
{


    ui->groupBox_send_cmd_to_db->hide();
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide();
    ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();
    //other
    ui->groupBox_change_userpass_admin->hide();
    ui->groupBox_maxtry_change->hide();
    ui->groupBox_currenttry_change->hide();
    ui->groupBox_avatar_path_change->hide();
    ui->groupBox_history_of_admin_logins_log->hide();
    //    ui->groupBox_settings->show();
    ui->groupBox_change_database->show();
    ui->groupBox_change_show->show();
    ui->btn_return_home_from_config->show();
    ui->btn_show_adminloginslog_from_config->show();
}

void MainWindow::on_btn_settings_of_backup_database_clicked()
{
    ui->groupBox_change_database->hide();
    ui->groupBox_change_show->hide();
    ui->btn_return_home_from_config->hide();
    ui->btn_show_adminloginslog_from_config->hide();
    //other hide..
    //ui->groupBox_settings->show();
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide();
    ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();
    //other
    ui->groupBox_change_userpass_admin->hide();
    ui->groupBox_maxtry_change->hide();
    ui->groupBox_currenttry_change->hide();
    ui->groupBox_avatar_path_change->hide();
    ui->groupBox_history_of_admin_logins_log->hide();
    ui->groupBox_send_cmd_to_db->hide();

    ui->groupBox_db_backup_config->show();
    ui->btn_open_path_of_db->hide();//hide button maybe later fix this ..
    QSqlQuery q_give_db_configs_from_adminconfig("SELECT * FROM adminconfig;");
    while(q_give_db_configs_from_adminconfig.next())
    {
        ui->lbl_dynamic_now_path->setText(q_give_db_configs_from_adminconfig.value("db_path_backup").toString());
        QString status_radio_buttons_on_database_auto_backup = q_give_db_configs_from_adminconfig.value("db_auto_backup").toString();
        if(status_radio_buttons_on_database_auto_backup == "open")
            ui->rbtn_backup_with_open_app->setChecked(true);
        else if(status_radio_buttons_on_database_auto_backup == "weak")
            ui->rbtn_backup_with_weak->setChecked(true);
        else
            ui->rbtn_backup_disable->setChecked(true);
    }



}

void MainWindow::on_btn_cancel_db_edit_backup_settings_clicked()
{
    ui->groupBox_db_backup_config->hide();

    ui->groupBox_send_cmd_to_db->hide();
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide();
    ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();
    //other
    ui->groupBox_change_userpass_admin->hide();
    ui->groupBox_maxtry_change->hide();
    ui->groupBox_currenttry_change->hide();
    ui->groupBox_avatar_path_change->hide();
    ui->groupBox_history_of_admin_logins_log->hide();
    //    ui->groupBox_settings->show();
    ui->groupBox_change_database->show();
    ui->groupBox_change_show->show();
    ui->btn_return_home_from_config->show();
    ui->btn_show_adminloginslog_from_config->show();
}

void MainWindow::on_btn_add_new_path_for_backup_database_clicked()
{
    QString url_to_new_database_path_backups = QFileDialog::getExistingDirectory(); //this
    while(url_to_new_database_path_backups == "" || url_to_new_database_path_backups == " " || url_to_new_database_path_backups == "   ")
    {
        QMessageBox::critical(this," ", "آدرس درستی برای مسیر پشتیبان گیری پایگاه داده انتخاب نشده است\nدوباره تلاش کنید");
        url_to_new_database_path_backups = QFileDialog::getExistingDirectory();
    }

    QSqlQuery update_new_url_database_path_backups("UPDATE adminconfig SET db_path_backup='"+url_to_new_database_path_backups+"';");
    QMessageBox::information(this, " " , "مسیر جدید پشتیبان گیری پایگاه داده با موفقیت ویراش شد");
    //ui->lbl_dynamic_new_path->setText("null");
    ui->lbl_dynamic_now_path->setText(url_to_new_database_path_backups);
    //    ui->lbl_dynamic_new_path->setText(url_to_new_database_path_backups);
}

void MainWindow::on_btn_open_path_of_db_clicked()
{
    //nothing ...
    // now hided !
}

void MainWindow::on_btn_edit_db_edit_backup_settings_clicked()
{
    //save everthing from this form!
    QString value_of_status_auto_backup_database = "";
    if(ui->rbtn_backup_with_open_app->isChecked() == true)
        value_of_status_auto_backup_database = "open";
    else if (ui->rbtn_backup_with_weak->isChecked() == true)
        value_of_status_auto_backup_database = "weak";
    else
        value_of_status_auto_backup_database = "disabled";

    QSqlQuery q_update_status_auto_backup_database("UPDATE adminconfig SET db_auto_backup='"+value_of_status_auto_backup_database+"';");
    QMessageBox::information(this, " " ,"زمان پشتیبان گیری خودکار با موفیقت ویراش شد");
    ui->groupBox_db_backup_config->hide();

    ui->groupBox_send_cmd_to_db->hide();
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide();
    ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();
    //other
    ui->groupBox_change_userpass_admin->hide();
    ui->groupBox_maxtry_change->hide();
    ui->groupBox_currenttry_change->hide();
    ui->groupBox_avatar_path_change->hide();
    ui->groupBox_history_of_admin_logins_log->hide();
    //    ui->groupBox_settings->show();
    //ui->lbl_dynamic_new_path->setText("null");
    ui->groupBox_change_database->show();
    ui->groupBox_change_show->show();
    ui->btn_return_home_from_config->show();
    ui->btn_show_adminloginslog_from_config->show();
}

void MainWindow::on_btn_give_backup_now_clicked()
{
    //now
    QSqlQuery q_give_db_path_backup("SELECT * FROM adminconfig;");
    QString address_of_path_backup;
    while(q_give_db_path_backup.next())
        address_of_path_backup = q_give_db_path_backup.value("db_path_backup").toString();

    if(address_of_path_backup == "" || address_of_path_backup == " ")
        QMessageBox::critical(this, " " , "آدرس برای گرفتن فایل پشتیبان از پایگاه داده درست نیست");

    else
    {
        QString time_and_date_current = QDateTime::currentDateTime().toString();
        time_and_date_current = time_and_date_current.replace(QString(" "), QString("-"));
        time_and_date_current = time_and_date_current.replace(QString(":"), QString("-"));
        time_and_date_current = time_and_date_current.toLower();

        QDir create_backup_directory( ""+address_of_path_backup + "/backup-"+ time_and_date_current);
        if(create_backup_directory.exists())
        {
            QMessageBox::information(this," ", "یک فایل پشتیبان با همین نام وجود دارد لطفا چند ثانیه دیگر امتحان کنید"+address_of_path_backup);
        }
        else
        {
            create_backup_directory.mkpath(".");
            create_backup_directory.mkdir("database");
            create_backup_directory.mkdir("avatar");
            create_backup_directory.mkdir("./avatar/defualt");


            QString ddatabase = address_of_path_backup+"/backup-"+ time_and_date_current+"/database/";
//            ddatabase = ddatabase.replace(QString("/"),QString("\\\\"));
//            std::string database_line = ddatabase.toStdString();
//            system(("XCOPY .\\\\database "+database_line).c_str());
            QFile::copy("./database/hs.db",ddatabase+"hs.db");



            //backup images folder!
            QString directory_avatar = address_of_path_backup+"/backup-"+ time_and_date_current+"/avatar/";

            QSqlQuery give_more_info_for_backup_images("SELECT * FROM students WHERE p30!='./avatar/defualt/defualt.jpg';");
            while(give_more_info_for_backup_images.next())
            {
                QString image_name_is_here = give_more_info_for_backup_images.value("p0").toString();

                if(QFileInfo(directory_avatar+image_name_is_here+avatar_format).exists())
                {
                   //nothing..
                }
                else
                {
                    QFile::copy(address_avatar_hs_users+image_name_is_here+avatar_format,directory_avatar+image_name_is_here+avatar_format);
                }
            }
            ///back up images for hsusers
            QSqlQuery give_more_info_for_backup_images_hs("SELECT * FROM registration WHERE p30!='./avatar/defualt/defualt.jpg';");
            while(give_more_info_for_backup_images_hs.next())
            {
                QString image_name_is_here = give_more_info_for_backup_images_hs.value("p0").toString();

                if(QFileInfo(directory_avatar+image_name_is_here+avatar_format).exists())
                {
                   //nothing..
                }
                else
                {
                    QFile::copy(address_avatar_hs_users+image_name_is_here+avatar_format,directory_avatar+image_name_is_here+avatar_format);
                }
            }
//            QString davatar = address_of_path_backup+"/backup-"+ time_and_date_current+"/avatar";
//            davatar = davatar.replace(QString("/"),QString("\\\\"));
//            std::string avatar_line = davatar.toStdString();
//            system(("XCOPY .\\\\avatar "+avatar_line).c_str());



            QString d_defualt_avatar = address_of_path_backup+"/backup-"+ time_and_date_current+"/avatar/defualt/";
//            d_defualt_avatar = d_defualt_avatar.replace(QString("/"),QString("\\\\"));
//            std::string defualt_avatar_line = d_defualt_avatar.toStdString();
//            system(("XCOPY .\\\\avatar\\\\defualt "+defualt_avatar_line).c_str());

            QFile::copy(address_avatar_hs_users+"/defualt/defualt"+avatar_format,d_defualt_avatar+"defualt"+avatar_format);







            QMessageBox::information(this," ","فایل های پشتیبان با موفیقت در آدرس :"
                                              "\n"
                                     +address_of_path_backup + "/backup-"+ time_and_date_current+"\n"
                                                                                                 ".ساخته شدند");
        }
    }
}

void MainWindow::on_btn_return_to_home_clicked()
{
    if(ui->btn_show_users_hs->text() == "افزودن")
    {
        ui->groupBox_insert_more_data_to_student_for_this_class->hide();
        ui->btn_show_users_hs->setText("نمایش اطلاعات");
        want_to_select_student_from_list_for_add_to_a_class= false;
        ui->groupBox_settings->hide();
        ui->groupBox_login->hide();
        ui->groupBox_hs_register->hide();
        ui->groupBox_hs_search_for_edit->hide();
        ui->groupBox_show_users_hs->hide();
        ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->show();
    }
    else
    {
        ui->groupBox_settings->hide();
        ui->groupBox_login->hide();
        ui->groupBox_hs_register->hide();
        ui->groupBox_hs_search_for_edit->hide();
        //    ui->groupBox_send_cmd_to_db->hide();
        //    ui->groupBox_show_users_hs->hide();    ----
        ui->groupBox_show_users_hs->hide();
        ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->show();
    }

}

void MainWindow::on_btn_return_to_home_from_settings_form_clicked()
{
    ui->groupBox_settings->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_btn_hs_set_title_clicked()
{

    ui->groupBox_side_right_forms->hide();
    ui->groupBox_side_left_forms->hide();

    ui->scrollArea_edit_titles_form_hs->ensureVisible(0,0,0,0);

    ui->btn_hs_set_disable->hide();
    ui->btn_return_to_home_from_settings_form->hide();
    ui->groupBox_hs_form->show();

    ui->txt_edit_tform_hs_0->setDisabled(true);
    ui->txt_edit_tform_hs_1->setDisabled(true);
    ui->txt_edit_tform_hs_2->setDisabled(true);
    ui->txt_edit_tform_hs_3->setDisabled(true);
    ui->cbox_stats_disable_0->setDisabled(true);    ui->cbox_stats_disable_2->setDisabled(true);
    ui->cbox_stats_disable_1->setDisabled(true);    ui->cbox_stats_disable_3->setDisabled(true);
    ui->cbox_stats_disable_0->setText("فعال");  ui->cbox_stats_disable_2->setText("فعال");
    ui->cbox_stats_disable_1->setText("فعال");  ui->cbox_stats_disable_3->setText("فعال");

    //update titles
    QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
    while (q_Hs_Load_Title.next())
    {
        ui->txt_edit_tform_hs_0->setText(q_Hs_Load_Title.value("t0").toString()); ui->txt_edit_tform_hs_1->setText(q_Hs_Load_Title.value("t1").toString()); ui->txt_edit_tform_hs_2->setText(q_Hs_Load_Title.value("t2").toString()); ui->txt_edit_tform_hs_3->setText(q_Hs_Load_Title.value("t3").toString()); ui->txt_edit_tform_hs_4->setText(q_Hs_Load_Title.value("t4").toString());                ui->txt_edit_tform_hs_5->setText(q_Hs_Load_Title.value("t5").toString()); ui->txt_edit_tform_hs_6->setText(q_Hs_Load_Title.value("t6").toString());               ui->txt_edit_tform_hs_7->setText(q_Hs_Load_Title.value("t7").toString());  ui->txt_edit_tform_hs_8->setText(q_Hs_Load_Title.value("t8").toString());              ui->txt_edit_tform_hs_9->setText(q_Hs_Load_Title.value("t9").toString()); ui->txt_edit_tform_hs_10->setText(q_Hs_Load_Title.value("t10").toString());                ui->txt_edit_tform_hs_11->setText(q_Hs_Load_Title.value("t11").toString()); ui->txt_edit_tform_hs_12->setText(q_Hs_Load_Title.value("t12").toString()); ui->txt_edit_tform_hs_13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->txt_edit_tform_hs_14->setText(q_Hs_Load_Title.value("t14").toString()); ui->txt_edit_tform_hs_15->setText(q_Hs_Load_Title.value("t15").toString());                ui->txt_edit_tform_hs_16->setText(q_Hs_Load_Title.value("t16").toString());  ui->txt_edit_tform_hs_17->setText(q_Hs_Load_Title.value("t17").toString()); ui->txt_edit_tform_hs_18->setText(q_Hs_Load_Title.value("t18").toString());ui->txt_edit_tform_hs_19->setText(q_Hs_Load_Title.value("t19").toString());ui->txt_edit_tform_hs_20->setText(q_Hs_Load_Title.value("t20").toString());ui->txt_edit_tform_hs_21->setText(q_Hs_Load_Title.value("t21").toString());ui->txt_edit_tform_hs_22->setText(q_Hs_Load_Title.value("t22").toString());ui->txt_edit_tform_hs_23->setText(q_Hs_Load_Title.value("t23").toString());ui->txt_edit_tform_hs_24->setText(q_Hs_Load_Title.value("t24").toString());ui->txt_edit_tform_hs_25->setText(q_Hs_Load_Title.value("t25").toString());ui->txt_edit_tform_hs_26->setText(q_Hs_Load_Title.value("t26").toString()); ui->txt_edit_tform_hs_27->setText(q_Hs_Load_Title.value("t27").toString());ui->txt_edit_tform_hs_28->setText(q_Hs_Load_Title.value("t28").toString()); ui->txt_edit_tform_hs_29->setText(q_Hs_Load_Title.value("t29").toString());
    }

    QSqlQuery q_hs_load_status_disable_or_not("SELECT * FROM registrationTitles");
    while (q_hs_load_status_disable_or_not.next())
    {
        ui->cbox_stats_disable_0->setChecked(!q_hs_load_status_disable_or_not.value("disable_status0").toInt());
        ui->cbox_stats_disable_1->setChecked(!q_hs_load_status_disable_or_not.value("disable_status1").toInt());
        ui->cbox_stats_disable_2->setChecked(!q_hs_load_status_disable_or_not.value("disable_status2").toInt());
        ui->cbox_stats_disable_3->setChecked(!q_hs_load_status_disable_or_not.value("disable_status3").toInt());
        ui->cbox_stats_disable_4->setChecked(!q_hs_load_status_disable_or_not.value("disable_status4").toInt());
        ui->cbox_stats_disable_5->setChecked(!q_hs_load_status_disable_or_not.value("disable_status5").toInt());
        ui->cbox_stats_disable_6->setChecked(!q_hs_load_status_disable_or_not.value("disable_status6").toInt());
        ui->cbox_stats_disable_7->setChecked(!q_hs_load_status_disable_or_not.value("disable_status7").toInt());
        ui->cbox_stats_disable_8->setChecked(!q_hs_load_status_disable_or_not.value("disable_status8").toInt());
        ui->cbox_stats_disable_9->setChecked(!q_hs_load_status_disable_or_not.value("disable_status9").toInt());
        ui->cbox_stats_disable_10->setChecked(!q_hs_load_status_disable_or_not.value("disable_status10").toInt());
        ui->cbox_stats_disable_11->setChecked(!q_hs_load_status_disable_or_not.value("disable_status11").toInt());
        ui->cbox_stats_disable_12->setChecked(!q_hs_load_status_disable_or_not.value("disable_status12").toInt());
        ui->cbox_stats_disable_13->setChecked(!q_hs_load_status_disable_or_not.value("disable_status13").toInt());
        ui->cbox_stats_disable_14->setChecked(!q_hs_load_status_disable_or_not.value("disable_status14").toInt());
        ui->cbox_stats_disable_15->setChecked(!q_hs_load_status_disable_or_not.value("disable_status15").toInt());
        ui->cbox_stats_disable_16->setChecked(!q_hs_load_status_disable_or_not.value("disable_status16").toInt());
        ui->cbox_stats_disable_17->setChecked(!q_hs_load_status_disable_or_not.value("disable_status17").toInt());
        ui->cbox_stats_disable_18->setChecked(!q_hs_load_status_disable_or_not.value("disable_status18").toInt());
        ui->cbox_stats_disable_19->setChecked(!q_hs_load_status_disable_or_not.value("disable_status19").toInt());
        ui->cbox_stats_disable_20->setChecked(!q_hs_load_status_disable_or_not.value("disable_status20").toInt());
        ui->cbox_stats_disable_21->setChecked(!q_hs_load_status_disable_or_not.value("disable_status21").toInt());
        ui->cbox_stats_disable_22->setChecked(!q_hs_load_status_disable_or_not.value("disable_status22").toInt());
        ui->cbox_stats_disable_23->setChecked(!q_hs_load_status_disable_or_not.value("disable_status23").toInt());
        ui->cbox_stats_disable_24->setChecked(!q_hs_load_status_disable_or_not.value("disable_status24").toInt());
        ui->cbox_stats_disable_25->setChecked(!q_hs_load_status_disable_or_not.value("disable_status25").toInt());
        ui->cbox_stats_disable_26->setChecked(!q_hs_load_status_disable_or_not.value("disable_status26").toInt());
        ui->cbox_stats_disable_27->setChecked(!q_hs_load_status_disable_or_not.value("disable_status27").toInt());
        ui->cbox_stats_disable_28->setChecked(!q_hs_load_status_disable_or_not.value("disable_status28").toInt());
        ui->cbox_stats_disable_29->setChecked(!q_hs_load_status_disable_or_not.value("disable_status29").toInt());
    }
    if(ui->cbox_stats_disable_4->isChecked() == false) {ui->cbox_stats_disable_4->setText("غیرفعال");} if(ui->cbox_stats_disable_17->isChecked() == false) {ui->cbox_stats_disable_17->setText("غیرفعال");}
    if(ui->cbox_stats_disable_5->isChecked() == false) {ui->cbox_stats_disable_5->setText("غیرفعال");} if(ui->cbox_stats_disable_18->isChecked() == false) {ui->cbox_stats_disable_18->setText("غیرفعال");}
    if(ui->cbox_stats_disable_6->isChecked() == false) {ui->cbox_stats_disable_6->setText("غیرفعال");} if(ui->cbox_stats_disable_19->isChecked() == false) {ui->cbox_stats_disable_19->setText("غیرفعال");}
    if(ui->cbox_stats_disable_7->isChecked() == false) {ui->cbox_stats_disable_7->setText("غیرفعال");} if(ui->cbox_stats_disable_20->isChecked() == false) {ui->cbox_stats_disable_20->setText("غیرفعال");}
    if(ui->cbox_stats_disable_8->isChecked() == false) {ui->cbox_stats_disable_8->setText("غیرفعال");} if(ui->cbox_stats_disable_21->isChecked() == false) {ui->cbox_stats_disable_21->setText("غیرفعال");}
    if(ui->cbox_stats_disable_9->isChecked() == false) {ui->cbox_stats_disable_9->setText("غیرفعال");} if(ui->cbox_stats_disable_22->isChecked() == false) {ui->cbox_stats_disable_22->setText("غیرفعال");}
    if(ui->cbox_stats_disable_10->isChecked() == false) {ui->cbox_stats_disable_10->setText("غیرفعال");} if(ui->cbox_stats_disable_23->isChecked() == false) {ui->cbox_stats_disable_23->setText("غیرفعال");}
    if(ui->cbox_stats_disable_11->isChecked() == false) {ui->cbox_stats_disable_11->setText("غیرفعال");} if(ui->cbox_stats_disable_24->isChecked() == false) {ui->cbox_stats_disable_24->setText("غیرفعال");}
    if(ui->cbox_stats_disable_12->isChecked() == false) {ui->cbox_stats_disable_12->setText("غیرفعال");} if(ui->cbox_stats_disable_25->isChecked() == false) {ui->cbox_stats_disable_25->setText("غیرفعال");}
    if(ui->cbox_stats_disable_13->isChecked() == false) {ui->cbox_stats_disable_13->setText("غیرفعال");} if(ui->cbox_stats_disable_26->isChecked() == false) {ui->cbox_stats_disable_26->setText("غیرفعال");}
    if(ui->cbox_stats_disable_14->isChecked() == false) {ui->cbox_stats_disable_14->setText("غیرفعال");} if(ui->cbox_stats_disable_27->isChecked() == false) {ui->cbox_stats_disable_27->setText("غیرفعال");}
    if(ui->cbox_stats_disable_15->isChecked() == false) {ui->cbox_stats_disable_15->setText("غیرفعال");} if(ui->cbox_stats_disable_28->isChecked() == false) {ui->cbox_stats_disable_28->setText("غیرفعال");}
    if(ui->cbox_stats_disable_16->isChecked() == false) {ui->cbox_stats_disable_16->setText("غیرفعال");} if(ui->cbox_stats_disable_29->isChecked() == false) {ui->cbox_stats_disable_29->setText("غیرفعال");}
}

void MainWindow::on_btn_cancel_edit_titles_hs_clicked()
{
    ui->groupBox_hs_form->hide();
    ui->btn_return_to_home_from_settings_form->show();
    ui->groupBox_side_right_forms->show();
    ui->groupBox_side_left_forms->show();

//    ui->txt_edit_tform_hs_0->clear();   ui->txt_edit_tform_hs_10->clear();   ui->txt_edit_tform_hs_20->clear();
//    ui->txt_edit_tform_hs_1->clear();   ui->txt_edit_tform_hs_11->clear();   ui->txt_edit_tform_hs_21->clear();
//    ui->txt_edit_tform_hs_2->clear();   ui->txt_edit_tform_hs_12->clear();   ui->txt_edit_tform_hs_22->clear();
//    ui->txt_edit_tform_hs_3->clear();   ui->txt_edit_tform_hs_13->clear();   ui->txt_edit_tform_hs_23->clear();
//    ui->txt_edit_tform_hs_4->clear();   ui->txt_edit_tform_hs_14->clear();   ui->txt_edit_tform_hs_24->clear();
//    ui->txt_edit_tform_hs_5->clear();   ui->txt_edit_tform_hs_15->clear();   ui->txt_edit_tform_hs_25->clear();
//    ui->txt_edit_tform_hs_6->clear();   ui->txt_edit_tform_hs_16->clear();   ui->txt_edit_tform_hs_26->clear();
//    ui->txt_edit_tform_hs_7->clear();   ui->txt_edit_tform_hs_17->clear();   ui->txt_edit_tform_hs_27->clear();
//    ui->txt_edit_tform_hs_8->clear();   ui->txt_edit_tform_hs_18->clear();   ui->txt_edit_tform_hs_28->clear();
//    ui->txt_edit_tform_hs_9->clear();   ui->txt_edit_tform_hs_19->clear();   ui->txt_edit_tform_hs_29->clear();

}

void MainWindow::on_btn_submit_edit_titles_hs_clicked()
{
//    ui->scrollArea_settings_change_titles->setGeometry(10,10,661,401);
    QSqlQuery q_Hs_Modify_userxx("UPDATE registrationTitles SET t4='"+ui->txt_edit_tform_hs_4->text()+"',t5='"+ui->txt_edit_tform_hs_5->text()+"',t6='"+ui->txt_edit_tform_hs_6->text()+"',t7='"+ui->txt_edit_tform_hs_7->text()+"',t8='"+ui->txt_edit_tform_hs_8->text()+"',t9='"+ui->txt_edit_tform_hs_9->text()+"',t10='"+ui->txt_edit_tform_hs_10->text()+"',t11='"+ui->txt_edit_tform_hs_11->text()+"',t12='"+ui->txt_edit_tform_hs_12->text()+"',t13='"+ui->txt_edit_tform_hs_13->text()+"',t14='"+ui->txt_edit_tform_hs_14->text()+"',t15='"+ui->txt_edit_tform_hs_15->text()+"',t16='"+ui->txt_edit_tform_hs_16->text()+"',t17='"+ui->txt_edit_tform_hs_17->text()+"',t18='"+ui->txt_edit_tform_hs_18->text()+"',t19='"+ui->txt_edit_tform_hs_19->text()+"',t20='"+ui->txt_edit_tform_hs_20->text()+"',t21='"+ui->txt_edit_tform_hs_21->text()+"',t22='"+ui->txt_edit_tform_hs_22->text()+"',t23='"+ui->txt_edit_tform_hs_23->text()+"',t24='"+ui->txt_edit_tform_hs_24->text()+"',t25='"+ui->txt_edit_tform_hs_25->text()+"',t26='"+ui->txt_edit_tform_hs_26->text()+"',t27='"+ui->txt_edit_tform_hs_27->text()+"',t28='"+ui->txt_edit_tform_hs_28->text()+"',t29='"+ui->txt_edit_tform_hs_29->text()+"';");
    QSqlQuery q_hs_modify_status_disbale_titleS_form_registration("UPDATE registrationTitles SET disable_status4='"+QString::number(!ui->cbox_stats_disable_4->isChecked())+"'"
                                                                                                                                                                            ",disable_status5='"+QString::number(!ui->cbox_stats_disable_5->isChecked())+"'"
                                                                                                                                                                                                                                                         ",disable_status6='"+QString::number(!ui->cbox_stats_disable_6->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                      ",disable_status7='"+QString::number(!ui->cbox_stats_disable_7->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                   ",disable_status8='"+QString::number(!ui->cbox_stats_disable_8->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ",disable_status9='"+QString::number(!ui->cbox_stats_disable_9->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ",disable_status10='"+QString::number(!ui->cbox_stats_disable_10->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ",disable_status11='"+QString::number(!ui->cbox_stats_disable_11->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ",disable_status12='"+QString::number(!ui->cbox_stats_disable_12->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ",disable_status13='"+QString::number(!ui->cbox_stats_disable_13->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ",disable_status14='"+QString::number(!ui->cbox_stats_disable_14->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        ",disable_status15='"+QString::number(!ui->cbox_stats_disable_15->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ",disable_status16='"+QString::number(!ui->cbox_stats_disable_16->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ",disable_status17='"+QString::number(!ui->cbox_stats_disable_17->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ",disable_status18='"+QString::number(!ui->cbox_stats_disable_18->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ",disable_status19='"+QString::number(!ui->cbox_stats_disable_19->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   ",disable_status20='"+QString::number(!ui->cbox_stats_disable_20->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ",disable_status21='"+QString::number(!ui->cbox_stats_disable_21->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 ",disable_status22='"+QString::number(!ui->cbox_stats_disable_22->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ",disable_status23='"+QString::number(!ui->cbox_stats_disable_23->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ",disable_status24='"+QString::number(!ui->cbox_stats_disable_24->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              ",disable_status25='"+QString::number(!ui->cbox_stats_disable_25->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             ",disable_status26='"+QString::number(!ui->cbox_stats_disable_26->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ",disable_status27='"+QString::number(!ui->cbox_stats_disable_27->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ",disable_status28='"+QString::number(!ui->cbox_stats_disable_28->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ",disable_status29='"+QString::number(!ui->cbox_stats_disable_29->isChecked())+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ";");
    //QMessageBox::information(this," ",QString::number(!ui->cbox_stats_disable_4->isChecked()));
    QMessageBox::information(this," ","عنوان های فرم ثبت نام حسینیه با موفیقت ویرایش شدند" );

    ui->groupBox_hs_form->hide();
    ui->btn_return_to_home_from_settings_form->show();
    ui->groupBox_side_right_forms->show();
    ui->groupBox_side_left_forms->show();

//    ui->txt_edit_tform_hs_0->clear();   ui->txt_edit_tform_hs_10->clear();   ui->txt_edit_tform_hs_20->clear();
//    ui->txt_edit_tform_hs_1->clear();   ui->txt_edit_tform_hs_11->clear();   ui->txt_edit_tform_hs_21->clear();
//    ui->txt_edit_tform_hs_2->clear();   ui->txt_edit_tform_hs_12->clear();   ui->txt_edit_tform_hs_22->clear();
//    ui->txt_edit_tform_hs_3->clear();   ui->txt_edit_tform_hs_13->clear();   ui->txt_edit_tform_hs_23->clear();
//    ui->txt_edit_tform_hs_4->clear();   ui->txt_edit_tform_hs_14->clear();   ui->txt_edit_tform_hs_24->clear();
//    ui->txt_edit_tform_hs_5->clear();   ui->txt_edit_tform_hs_15->clear();   ui->txt_edit_tform_hs_25->clear();
//    ui->txt_edit_tform_hs_6->clear();   ui->txt_edit_tform_hs_16->clear();   ui->txt_edit_tform_hs_26->clear();
//    ui->txt_edit_tform_hs_7->clear();   ui->txt_edit_tform_hs_17->clear();   ui->txt_edit_tform_hs_27->clear();
//    ui->txt_edit_tform_hs_8->clear();   ui->txt_edit_tform_hs_18->clear();   ui->txt_edit_tform_hs_28->clear();
//    ui->txt_edit_tform_hs_9->clear();   ui->txt_edit_tform_hs_19->clear();   ui->txt_edit_tform_hs_29->clear();
}

void MainWindow::on_cbox_stats_disable_all_stateChanged(int)
{
    bool statusx = false;
    QString statusx_text = "";
    if(ui->cbox_stats_disable_all->isChecked() == true)
    {
        statusx=true;
        statusx_text = "فعال";
        //ui->cbox_stats_disable_0->setChecked(statusx);
        ui->cbox_stats_disable_12->setChecked(statusx); ui->cbox_stats_disable_24->setChecked(statusx);
        //ui->cbox_stats_disable_1->setChecked(statusx);
        ui->cbox_stats_disable_13->setChecked(statusx); ui->cbox_stats_disable_25->setChecked(statusx);
        //ui->cbox_stats_disable_2->setChecked(statusx);
        ui->cbox_stats_disable_14->setChecked(statusx); ui->cbox_stats_disable_26->setChecked(statusx);
        //ui->cbox_stats_disable_3->setChecked(statusx);
        ui->cbox_stats_disable_15->setChecked(statusx); ui->cbox_stats_disable_27->setChecked(statusx);
        ui->cbox_stats_disable_4->setChecked(statusx); ui->cbox_stats_disable_16->setChecked(statusx); ui->cbox_stats_disable_28->setChecked(statusx);
        ui->cbox_stats_disable_5->setChecked(statusx); ui->cbox_stats_disable_17->setChecked(statusx); ui->cbox_stats_disable_29->setChecked(statusx);
        ui->cbox_stats_disable_6->setChecked(statusx); ui->cbox_stats_disable_18->setChecked(statusx);
        ui->cbox_stats_disable_7->setChecked(statusx); ui->cbox_stats_disable_19->setChecked(statusx);
        ui->cbox_stats_disable_8->setChecked(statusx); ui->cbox_stats_disable_20->setChecked(statusx);
        ui->cbox_stats_disable_9->setChecked(statusx); ui->cbox_stats_disable_21->setChecked(statusx);
        ui->cbox_stats_disable_10->setChecked(statusx); ui->cbox_stats_disable_22->setChecked(statusx);
        ui->cbox_stats_disable_11->setChecked(statusx); ui->cbox_stats_disable_23->setChecked(statusx);
        //set text
        ui->cbox_stats_disable_14->setText(statusx_text); ui->cbox_stats_disable_28->setText(statusx_text);
        //ui->cbox_stats_disable_1->setText(statusx_text);
        ui->cbox_stats_disable_15->setText(statusx_text); ui->cbox_stats_disable_29->setText(statusx_text);
        //ui->cbox_stats_disable_2->setText(statusx_text);
        ui->cbox_stats_disable_16->setText(statusx_text);
        //ui->cbox_stats_disable_3->setText(statusx_text);
        ui->cbox_stats_disable_17->setText(statusx_text);
        ui->cbox_stats_disable_4->setText(statusx_text); ui->cbox_stats_disable_18->setText(statusx_text);
        ui->cbox_stats_disable_5->setText(statusx_text); ui->cbox_stats_disable_19->setText(statusx_text);
        ui->cbox_stats_disable_6->setText(statusx_text); ui->cbox_stats_disable_20->setText(statusx_text);
        ui->cbox_stats_disable_7->setText(statusx_text); ui->cbox_stats_disable_21->setText(statusx_text);
        ui->cbox_stats_disable_8->setText(statusx_text); ui->cbox_stats_disable_22->setText(statusx_text);
        ui->cbox_stats_disable_9->setText(statusx_text); ui->cbox_stats_disable_23->setText(statusx_text);
        ui->cbox_stats_disable_10->setText(statusx_text); ui->cbox_stats_disable_24->setText(statusx_text);
        ui->cbox_stats_disable_11->setText(statusx_text); ui->cbox_stats_disable_25->setText(statusx_text);
        ui->cbox_stats_disable_12->setText(statusx_text); ui->cbox_stats_disable_26->setText(statusx_text);
        ui->cbox_stats_disable_13->setText(statusx_text); ui->cbox_stats_disable_27->setText(statusx_text);
        ui->cbox_stats_disable_all->setText("همه غیرفعال");
        ui->cbox_stats_disable_all->setChecked(false);



    }

    else
    {

        statusx=false;
        statusx_text= "غیر فعال";
        //ui->cbox_stats_disable_0->setChecked(statusx);
        ui->cbox_stats_disable_12->setChecked(statusx); ui->cbox_stats_disable_24->setChecked(statusx);
        //ui->cbox_stats_disable_1->setChecked(statusx);
        ui->cbox_stats_disable_13->setChecked(statusx); ui->cbox_stats_disable_25->setChecked(statusx);
        //ui->cbox_stats_disable_2->setChecked(statusx);
        ui->cbox_stats_disable_14->setChecked(statusx); ui->cbox_stats_disable_26->setChecked(statusx);
        //ui->cbox_stats_disable_3->setChecked(statusx);
        ui->cbox_stats_disable_15->setChecked(statusx); ui->cbox_stats_disable_27->setChecked(statusx);
        ui->cbox_stats_disable_4->setChecked(statusx); ui->cbox_stats_disable_16->setChecked(statusx); ui->cbox_stats_disable_28->setChecked(statusx);
        ui->cbox_stats_disable_5->setChecked(statusx); ui->cbox_stats_disable_17->setChecked(statusx); ui->cbox_stats_disable_29->setChecked(statusx);
        ui->cbox_stats_disable_6->setChecked(statusx); ui->cbox_stats_disable_18->setChecked(statusx);
        ui->cbox_stats_disable_7->setChecked(statusx); ui->cbox_stats_disable_19->setChecked(statusx);
        ui->cbox_stats_disable_8->setChecked(statusx); ui->cbox_stats_disable_20->setChecked(statusx);
        ui->cbox_stats_disable_9->setChecked(statusx); ui->cbox_stats_disable_21->setChecked(statusx);
        ui->cbox_stats_disable_10->setChecked(statusx); ui->cbox_stats_disable_22->setChecked(statusx);
        ui->cbox_stats_disable_11->setChecked(statusx); ui->cbox_stats_disable_23->setChecked(statusx);

        //set text
        ui->cbox_stats_disable_14->setText(statusx_text); ui->cbox_stats_disable_28->setText(statusx_text);
        //ui->cbox_stats_disable_1->setText(statusx_text);
        ui->cbox_stats_disable_15->setText(statusx_text); ui->cbox_stats_disable_29->setText(statusx_text);
        //ui->cbox_stats_disable_2->setText(statusx_text);
        ui->cbox_stats_disable_16->setText(statusx_text);
        //ui->cbox_stats_disable_3->setText(statusx_text);
        ui->cbox_stats_disable_17->setText(statusx_text);
        ui->cbox_stats_disable_4->setText(statusx_text); ui->cbox_stats_disable_18->setText(statusx_text);
        ui->cbox_stats_disable_5->setText(statusx_text); ui->cbox_stats_disable_19->setText(statusx_text);
        ui->cbox_stats_disable_6->setText(statusx_text); ui->cbox_stats_disable_20->setText(statusx_text);
        ui->cbox_stats_disable_7->setText(statusx_text); ui->cbox_stats_disable_21->setText(statusx_text);
        ui->cbox_stats_disable_8->setText(statusx_text); ui->cbox_stats_disable_22->setText(statusx_text);
        ui->cbox_stats_disable_9->setText(statusx_text); ui->cbox_stats_disable_23->setText(statusx_text);
        ui->cbox_stats_disable_10->setText(statusx_text); ui->cbox_stats_disable_24->setText(statusx_text);
        ui->cbox_stats_disable_11->setText(statusx_text); ui->cbox_stats_disable_25->setText(statusx_text);
        ui->cbox_stats_disable_12->setText(statusx_text); ui->cbox_stats_disable_26->setText(statusx_text);
        ui->cbox_stats_disable_13->setText(statusx_text); ui->cbox_stats_disable_27->setText(statusx_text);
        ui->cbox_stats_disable_all->setText("همه فعال");
        ui->cbox_stats_disable_all->setChecked(false);
    }
}

void MainWindow::on_cbox_stats_disable_0_stateChanged(int)
{
    if(ui->cbox_stats_disable_0->isChecked()== true)
        ui->cbox_stats_disable_0->setText("فعال");
    else
        ui->cbox_stats_disable_0->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_1_stateChanged(int)
{
    if(ui->cbox_stats_disable_1->isChecked()== true)
        ui->cbox_stats_disable_1->setText("فعال");
    else
        ui->cbox_stats_disable_1->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_2_stateChanged(int)
{
    if(ui->cbox_stats_disable_2->isChecked()== true)
        ui->cbox_stats_disable_2->setText("فعال");
    else
        ui->cbox_stats_disable_2->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_3_stateChanged(int)
{
    if(ui->cbox_stats_disable_3->isChecked()== true)
        ui->cbox_stats_disable_3->setText("فعال");
    else
        ui->cbox_stats_disable_3->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_4_stateChanged(int)
{
    if(ui->cbox_stats_disable_4->isChecked()== true)
        ui->cbox_stats_disable_4->setText("فعال");
    else
        ui->cbox_stats_disable_4->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_5_stateChanged(int)
{
    if(ui->cbox_stats_disable_5->isChecked()== true)
        ui->cbox_stats_disable_5->setText("فعال");
    else
        ui->cbox_stats_disable_5->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_6_stateChanged(int)
{
    if(ui->cbox_stats_disable_6->isChecked()== true)
        ui->cbox_stats_disable_6->setText("فعال");
    else
        ui->cbox_stats_disable_6->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_7_stateChanged(int)
{
    if(ui->cbox_stats_disable_7->isChecked()== true)
        ui->cbox_stats_disable_7->setText("فعال");
    else
        ui->cbox_stats_disable_7->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_8_stateChanged(int)
{
    if(ui->cbox_stats_disable_8->isChecked()== true)
        ui->cbox_stats_disable_8->setText("فعال");
    else
        ui->cbox_stats_disable_8->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_9_stateChanged(int)
{
    if(ui->cbox_stats_disable_9->isChecked()== true)
        ui->cbox_stats_disable_9->setText("فعال");
    else
        ui->cbox_stats_disable_9->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_10_stateChanged(int)
{
    if(ui->cbox_stats_disable_10->isChecked()== true)
        ui->cbox_stats_disable_10->setText("فعال");
    else
        ui->cbox_stats_disable_10->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_11_stateChanged(int)
{
    if(ui->cbox_stats_disable_11->isChecked()== true)
        ui->cbox_stats_disable_11->setText("فعال");
    else
        ui->cbox_stats_disable_11->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_12_stateChanged(int)
{
    if(ui->cbox_stats_disable_12->isChecked()== true)
        ui->cbox_stats_disable_12->setText("فعال");
    else
        ui->cbox_stats_disable_12->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_13_stateChanged(int)
{
    if(ui->cbox_stats_disable_13->isChecked()== true)
        ui->cbox_stats_disable_13->setText("فعال");
    else
        ui->cbox_stats_disable_13->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_14_stateChanged(int)
{
    if(ui->cbox_stats_disable_14->isChecked()== true)
        ui->cbox_stats_disable_14->setText("فعال");
    else
        ui->cbox_stats_disable_14->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_15_stateChanged(int)
{
    if(ui->cbox_stats_disable_15->isChecked()== true)
        ui->cbox_stats_disable_15->setText("فعال");
    else
        ui->cbox_stats_disable_15->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_16_stateChanged(int)
{
    if(ui->cbox_stats_disable_16->isChecked()== true)
        ui->cbox_stats_disable_16->setText("فعال");
    else
        ui->cbox_stats_disable_16->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_17_stateChanged(int)
{
    if(ui->cbox_stats_disable_17->isChecked()== true)
        ui->cbox_stats_disable_17->setText("فعال");
    else
        ui->cbox_stats_disable_17->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_18_stateChanged(int)
{
    if(ui->cbox_stats_disable_18->isChecked()== true)
        ui->cbox_stats_disable_18->setText("فعال");
    else
        ui->cbox_stats_disable_18->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_19_stateChanged(int)
{
    if(ui->cbox_stats_disable_19->isChecked()== true)
        ui->cbox_stats_disable_19->setText("فعال");
    else
        ui->cbox_stats_disable_19->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_20_stateChanged(int)
{
    if(ui->cbox_stats_disable_20->isChecked()== true)
        ui->cbox_stats_disable_20->setText("فعال");
    else
        ui->cbox_stats_disable_20->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_21_stateChanged(int)
{
    if(ui->cbox_stats_disable_21->isChecked()== true)
        ui->cbox_stats_disable_21->setText("فعال");
    else
        ui->cbox_stats_disable_21->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_22_stateChanged(int)
{
    if(ui->cbox_stats_disable_22->isChecked()== true)
        ui->cbox_stats_disable_22->setText("فعال");
    else
        ui->cbox_stats_disable_22->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_23_stateChanged(int)
{
    if(ui->cbox_stats_disable_23->isChecked()== true)
        ui->cbox_stats_disable_23->setText("فعال");
    else
        ui->cbox_stats_disable_23->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_24_stateChanged(int)
{
    if(ui->cbox_stats_disable_24->isChecked()== true)
        ui->cbox_stats_disable_24->setText("فعال");
    else
        ui->cbox_stats_disable_24->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_25_stateChanged(int)
{
    if(ui->cbox_stats_disable_25->isChecked()== true)
        ui->cbox_stats_disable_25->setText("فعال");
    else
        ui->cbox_stats_disable_25->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_26_stateChanged(int)
{
    if(ui->cbox_stats_disable_26->isChecked()== true)
        ui->cbox_stats_disable_26->setText("فعال");
    else
        ui->cbox_stats_disable_26->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_27_stateChanged(int)
{
    if(ui->cbox_stats_disable_27->isChecked()== true)
        ui->cbox_stats_disable_27->setText("فعال");
    else
        ui->cbox_stats_disable_27->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_28_stateChanged(int)
{
    if(ui->cbox_stats_disable_28->isChecked()== true)
        ui->cbox_stats_disable_28->setText("فعال");
    else
        ui->cbox_stats_disable_28->setText("غیرفعال");
}

void MainWindow::on_cbox_stats_disable_29_stateChanged(int)
{
    if(ui->cbox_stats_disable_29->isChecked()== true)
        ui->cbox_stats_disable_29->setText("فعال");
    else
        ui->cbox_stats_disable_29->setText("غیرفعال");
}

void MainWindow::on_btn_hs_return_to_home_clicked()
{
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_action_about_application_triggered()
{
    QMessageBox::information(this," ", "Version 1.0.0 [Stable]\n"
                                       "Database used sqlite.\n"
                                       "Compiled via minGW-32bit, C++11.\n"
                                       "Licenses: LGPL version 3, GPL version 2 and GPL version 3.\n"
                                       "Made by Qt Creator 4.11.1 [Based on Qt 5.14.1 (MSVC 2017,32bit)\n"
                                       "Source Code Address: https://github.com/andabout/management-app/\n");


}

void MainWindow::on_btn_goto_settings_from_home_clicked()
{


    //    QSqlQuery q_give_text_title_class_list("SELECT * FROM ;");
    //    while(q_give_text_title_class_list.next())
    //        ui->txt_change_title_class_list->setText(q_give_text_title_class_list.value("t_class_list").toString());

        QSqlQuery q_give_tab_titles("SELECT * FROM tabTitles;");
        while(q_give_tab_titles.next())
        {
            ui->tabWidget_settings->setTabText(0,q_give_tab_titles.value("tab_settings_0").toString());
            ui->tabWidget_settings->setTabText(1,q_give_tab_titles.value("tab_settings_1").toString());
        }



        ui->groupBox_login->hide();
        ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
        ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->hide();    ui->groupBox_settings->hide();
        ui->groupBox_search_hs_users->hide();
        ui->groupBox_search_result->hide();
        ui->groupBox_create_class->hide();
        ui->groupBox_show_class_info->hide();
        ui->groupBox_class_list->hide();
        ui->groupBox_question_select_one_part_for_edit_class->hide();
        ui->groupBox_edit_this_class->hide();
        ui->groupBox_edit_student_from_this_class->hide();
        ui->groupBox_edit_form_stu_from_class->hide();
        ui->groupBox_student_register->hide();
        ui->groupBox_show_students_list->hide();
        ui->groupBox_student_information->hide();
        ui->groupBox_qustion_add_student_to_this_class_by->hide();
        ui->groupBox_insert_more_data_to_student_for_this_class->hide();
        ui->groupBox_search_on_class->hide();
        ui->groupBox_result_search_class->hide();
        //other
        ui->groupBox_change_window_title->hide();
        ui->groupBox_change_userpass_admin->hide(); ui->groupBox_maxtry_change->hide();
        ui->groupBox_avatar_path_change->hide(); ui->groupBox_currenttry_change->hide();
        ui->groupBox_send_cmd_to_db->hide(); ui->groupBox_history_of_admin_logins_log->hide();
        ui->groupBox_db_backup_config->hide();
        ui->groupBox_resetfactory_tables->hide();




        //hide button settings->forms->disable-hs!
        ui->btn_hs_set_disable->hide();
        ui->groupBox_settings->show();
        ui->groupBox_change_show->show();
        ui->groupBox_change_database->show();
}

void MainWindow::on_btn_list_of_hs_from_home_clicked()
{
    //titleX set Text
    ui->groupBox_show_users_hs->show();
    ui->groupBox_show_users_hs->setTitle("لیست دانش آموزان");
    ui->listWidget_show_users_hs->clear();




    ui->scrollArea_register->ensureVisible(0,0,0,0);

    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();




    //remove all values from userinformation
    ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
    ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
    ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
    ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
    ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
    ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
    ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
    ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
    ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
    ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
    ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
    ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
    ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
    ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
    ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
    ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
    ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
    ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
    ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
    ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
    ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
    ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
    ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
    ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
    ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
    ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
    ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
    ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
    ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
    ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
    ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();

    ui->listWidget_show_users_hs->hide();
    ui->titleX->hide();
    ui->tableWidget_show_users_hs->clear();
    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM students;");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_show_users_hs->setColumnCount(4);
    QSqlQuery q_give_titles("SELECT * FROM studentTitles;");
    QString t0,t1,t2,t3;
    while(q_give_titles.next())
    {
        t0 = q_give_titles.value("st0").toString();
        t1 = q_give_titles.value("st1").toString();
        t2 = q_give_titles.value("st2").toString();
        t3 = q_give_titles.value("st3").toString();
    }
    ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
    ui->tableWidget_show_users_hs->verticalHeader()->hide();
    QSqlQuery search("SELECT * FROM students;");
    QString p0,p1,p2,p3;
    int sss = 0;
    while (search.next())
    {
        p0 = search.value("p0").toString();
        p1 = search.value("p1").toString();
        p2 = search.value("p2").toString();
        p3 = search.value("p3").toString();
        ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
        ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
        ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
        ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
        sss++;
    }
    ui->groupBox_show_users_hs->show();
}

void MainWindow::on_btn_register_user_hs_from_home_clicked()
{
    ui->scrollArea_register->ensureVisible(0,0,0,0);



    ui->groupBox_login->hide();
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();

    //hide btn delete user when page = registar || page != edit user
    ui->btn_edit_goto_delete_this_user->hide();


    ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg
    ui->groupBox_hs_register->show();
    ui->txt_register_0->setDisabled(false); ui->txt_register_1->setDisabled(false); ui->txt_register_2->setDisabled(false);
    ui->txt_register_0->setToolTip(""); ui->txt_register_1->setToolTip(""); ui->txt_register_2->setToolTip("");
    ui->groupBox_hs_register->setTitle("فرم ثبت نام عضو جدید در حسینیه");
    ui->btn_register_insert->setText("ثبت");
    //if want to back and make button clear/reset everything from form idcode(codr1)
    //ui->btn_register_clear->setText("تنظیم مجدد");
    QSqlQuery q_Hs_Load_Title("SELECT * FROM registrationTitles");
    while (q_Hs_Load_Title.next())
    {
        ui->lbl_register_t0->setText(q_Hs_Load_Title.value("t0").toString()); ui->lbl_register_t1->setText(q_Hs_Load_Title.value("t1").toString()); ui->lbl_register_t2->setText(q_Hs_Load_Title.value("t2").toString()); ui->lbl_register_t3->setText(q_Hs_Load_Title.value("t3").toString()); ui->lbl_register_t4->setText(q_Hs_Load_Title.value("t4").toString());                ui->lbl_register_t5->setText(q_Hs_Load_Title.value("t5").toString()); ui->lbl_register_t6->setText(q_Hs_Load_Title.value("t6").toString());               ui->lbl_register_t7->setText(q_Hs_Load_Title.value("t7").toString());  ui->lbl_register_t8->setText(q_Hs_Load_Title.value("t8").toString());              ui->lbl_register_t9->setText(q_Hs_Load_Title.value("t9").toString()); ui->lbl_register_t10->setText(q_Hs_Load_Title.value("t10").toString());                ui->lbl_register_t11->setText(q_Hs_Load_Title.value("t11").toString()); ui->lbl_register_t12->setText(q_Hs_Load_Title.value("t12").toString()); ui->lbl_register_t13->setText(q_Hs_Load_Title.value("t13").toString());                 ui->lbl_register_t14->setText(q_Hs_Load_Title.value("t14").toString()); ui->lbl_register_t15->setText(q_Hs_Load_Title.value("t15").toString());                ui->lbl_register_t16->setText(q_Hs_Load_Title.value("t16").toString());  ui->lbl_register_t17->setText(q_Hs_Load_Title.value("t17").toString()); ui->lbl_register_t18->setText(q_Hs_Load_Title.value("t18").toString());ui->lbl_register_t19->setText(q_Hs_Load_Title.value("t19").toString());ui->lbl_register_t20->setText(q_Hs_Load_Title.value("t20").toString());ui->lbl_register_t21->setText(q_Hs_Load_Title.value("t21").toString());ui->lbl_register_t22->setText(q_Hs_Load_Title.value("t22").toString());ui->lbl_register_t23->setText(q_Hs_Load_Title.value("t23").toString());ui->lbl_register_t24->setText(q_Hs_Load_Title.value("t24").toString());ui->lbl_register_t25->setText(q_Hs_Load_Title.value("t25").toString());ui->lbl_register_t26->setText(q_Hs_Load_Title.value("t26").toString()); ui->lbl_register_t27->setText(q_Hs_Load_Title.value("t27").toString());ui->lbl_register_t28->setText(q_Hs_Load_Title.value("t28").toString()); ui->lbl_register_t29->setText(q_Hs_Load_Title.value("t29").toString());
        //dbDynamic_disable_status_Text use this  disable_status
        const QString ds_number_0 = q_Hs_Load_Title.value("disable_status0").toString();
        if(ds_number_0 == dbDynamic_disable_status_Text) ui->txt_register_0->setDisabled(false); else ui->txt_register_0->setDisabled(true);
        const QString ds_number_1 = q_Hs_Load_Title.value("disable_status1").toString();
        if(ds_number_1 == dbDynamic_disable_status_Text) ui->txt_register_1->setDisabled(false); else ui->txt_register_1->setDisabled(true);
        const QString ds_number_2 = q_Hs_Load_Title.value("disable_status2").toString();
        if(ds_number_2 == dbDynamic_disable_status_Text) ui->txt_register_2->setDisabled(false); else ui->txt_register_2->setDisabled(true);
        const QString ds_number_3 = q_Hs_Load_Title.value("disable_status3").toString();
        if(ds_number_3 == dbDynamic_disable_status_Text) ui->txt_register_3->setDisabled(false); else ui->txt_register_3->setDisabled(true);
        const QString ds_number_4 = q_Hs_Load_Title.value("disable_status4").toString();
        if(ds_number_4 == dbDynamic_disable_status_Text) ui->txt_register_4->setDisabled(false); else ui->txt_register_4->setDisabled(true);
        const QString ds_number_5 = q_Hs_Load_Title.value("disable_status5").toString();
        if(ds_number_5 == dbDynamic_disable_status_Text) ui->txt_register_5->setDisabled(false); else ui->txt_register_5->setDisabled(true);
        const QString ds_number_6 = q_Hs_Load_Title.value("disable_status6").toString();
        if(ds_number_6 == dbDynamic_disable_status_Text) ui->txt_register_6->setDisabled(false); else ui->txt_register_6->setDisabled(true);
        const QString ds_number_7 = q_Hs_Load_Title.value("disable_status7").toString();
        if(ds_number_7 == dbDynamic_disable_status_Text) ui->txt_register_7->setDisabled(false); else ui->txt_register_7->setDisabled(true);
        const QString ds_number_8 = q_Hs_Load_Title.value("disable_status8").toString();
        if(ds_number_8 == dbDynamic_disable_status_Text) ui->txt_register_8->setDisabled(false); else ui->txt_register_8->setDisabled(true);
        const QString ds_number_9 = q_Hs_Load_Title.value("disable_status9").toString();
        if(ds_number_9 == dbDynamic_disable_status_Text) ui->txt_register_9->setDisabled(false); else ui->txt_register_9->setDisabled(true);
        const QString ds_number_10 = q_Hs_Load_Title.value("disable_status10").toString();
        if(ds_number_10 == dbDynamic_disable_status_Text) ui->txt_register_10->setDisabled(false); else ui->txt_register_10->setDisabled(true);
        const QString ds_number_11 = q_Hs_Load_Title.value("disable_status11").toString();
        if(ds_number_11 == dbDynamic_disable_status_Text) ui->txt_register_11->setDisabled(false); else ui->txt_register_11->setDisabled(true);
        const QString ds_number_12 = q_Hs_Load_Title.value("disable_status12").toString();
        if(ds_number_12 == dbDynamic_disable_status_Text) ui->txt_register_12->setDisabled(false); else ui->txt_register_12->setDisabled(true);
        const QString ds_number_13 = q_Hs_Load_Title.value("disable_status13").toString();
        if(ds_number_13 == dbDynamic_disable_status_Text) ui->txt_register_13->setDisabled(false); else ui->txt_register_13->setDisabled(true);
        const QString ds_number_14 = q_Hs_Load_Title.value("disable_status14").toString();
        if(ds_number_14 == dbDynamic_disable_status_Text) ui->txt_register_14->setDisabled(false); else ui->txt_register_14->setDisabled(true);
        const QString ds_number_15 = q_Hs_Load_Title.value("disable_status15").toString();
        if(ds_number_15 == dbDynamic_disable_status_Text) ui->txt_register_15->setDisabled(false); else ui->txt_register_15->setDisabled(true);
        const QString ds_number_16 = q_Hs_Load_Title.value("disable_status16").toString();
        if(ds_number_16 == dbDynamic_disable_status_Text) ui->txt_register_16->setDisabled(false); else ui->txt_register_16->setDisabled(true);
        const QString ds_number_17 = q_Hs_Load_Title.value("disable_status17").toString();
        if(ds_number_17 == dbDynamic_disable_status_Text) ui->txt_register_17->setDisabled(false); else ui->txt_register_17->setDisabled(true);
        const QString ds_number_18 = q_Hs_Load_Title.value("disable_status18").toString();
        if(ds_number_18 == dbDynamic_disable_status_Text) ui->txt_register_18->setDisabled(false); else ui->txt_register_18->setDisabled(true);
        const QString ds_number_19 = q_Hs_Load_Title.value("disable_status19").toString();
        if(ds_number_19 == dbDynamic_disable_status_Text) ui->txt_register_19->setDisabled(false); else ui->txt_register_19->setDisabled(true);
        const QString ds_number_20 = q_Hs_Load_Title.value("disable_status20").toString();
        if(ds_number_20 == dbDynamic_disable_status_Text) ui->txt_register_20->setDisabled(false); else ui->txt_register_20->setDisabled(true);
        const QString ds_number_21 = q_Hs_Load_Title.value("disable_status21").toString();
        if(ds_number_21 == dbDynamic_disable_status_Text) ui->txt_register_21->setDisabled(false); else ui->txt_register_21->setDisabled(true);
        const QString ds_number_22 = q_Hs_Load_Title.value("disable_status22").toString();
        if(ds_number_22 == dbDynamic_disable_status_Text) ui->txt_register_22->setDisabled(false); else ui->txt_register_22->setDisabled(true);
        const QString ds_number_23 = q_Hs_Load_Title.value("disable_status23").toString();
        if(ds_number_23 == dbDynamic_disable_status_Text) ui->txt_register_23->setDisabled(false); else ui->txt_register_23->setDisabled(true);
        const QString ds_number_24 = q_Hs_Load_Title.value("disable_status24").toString();
        if(ds_number_24 == dbDynamic_disable_status_Text) ui->txt_register_24->setDisabled(false); else ui->txt_register_24->setDisabled(true);
        const QString ds_number_25 = q_Hs_Load_Title.value("disable_status25").toString();
        if(ds_number_25 == dbDynamic_disable_status_Text) ui->txt_register_25->setDisabled(false); else ui->txt_register_25->setDisabled(true);
        const QString ds_number_26 = q_Hs_Load_Title.value("disable_status26").toString();
        if(ds_number_26 == dbDynamic_disable_status_Text) ui->txt_register_26->setDisabled(false); else ui->txt_register_26->setDisabled(true);
        const QString ds_number_27 = q_Hs_Load_Title.value("disable_status27").toString();
        if(ds_number_27 == dbDynamic_disable_status_Text) ui->txt_register_27->setDisabled(false); else ui->txt_register_27->setDisabled(true);
        const QString ds_number_28 = q_Hs_Load_Title.value("disable_status28").toString();
        if(ds_number_28 == dbDynamic_disable_status_Text) ui->txt_register_28->setDisabled(false); else ui->txt_register_28->setDisabled(true);
        const QString ds_number_29 = q_Hs_Load_Title.value("disable_status29").toString();
        if(ds_number_29 == dbDynamic_disable_status_Text) ui->txt_register_29->setDisabled(false); else ui->txt_register_29->setDisabled(true);
    }
    if(avatar_url == "")
    {
        QSqlQuery search_for_url_avatar_defualt("SELECT * FROM adminconfig;");
        //url
        while (search_for_url_avatar_defualt.next())
        {
            defualt_avatar = search_for_url_avatar_defualt.value("defualt_avatar").toString();
        }
        QPixmap pm(defualt_avatar); ui->lbl_register_avatar->setPixmap(defualt_avatar);
        ui->lbl_register_avatar->setScaledContents(true);
    }
}

void MainWindow::on_btb_change_window_title_clicked()
{
    ui->txt_window_title_text->clear();
    ui->btn_return_home_from_config->hide();
    ui->btn_show_adminloginslog_from_config->hide();
    ui->groupBox_change_show->hide();
    ui->groupBox_change_database->hide();
    ui->groupBox_change_window_title->show();

    QSqlQuery q_give_current_window_title_from_db("SELECT * FROM adminconfig;");
    QString current_window_title;
    while(q_give_current_window_title_from_db.next())
    {
        current_window_title = q_give_current_window_title_from_db.value("window_title").toString();
    }
    ui->txt_window_title_text->setText(current_window_title);
}

void MainWindow::on_btn_window_title_text_to_edit_clicked()
{
    QSqlQuery q_update_window_title_to_adminconfig("UPDATE adminconfig SET window_title='"+ui->txt_window_title_text->text()+"'");
    this->setWindowTitle(ui->txt_window_title_text->text());
    QMessageBox::information(this," ","عنوان برنامه با موفیقت تغییر یافت.");
    ui->txt_window_title_text->clear();
    ui->groupBox_change_window_title->hide();
    ui->btn_return_home_from_config->show();
    ui->btn_show_adminloginslog_from_config->show();
    ui->groupBox_change_show->show();
    ui->groupBox_change_database->show();
}

void MainWindow::on_btn_window_title_to_cancel_clicked()
{
    ui->txt_window_title_text->clear();
    ui->groupBox_change_window_title->hide();
    ui->btn_return_home_from_config->show();
    ui->btn_show_adminloginslog_from_config->show();
    ui->groupBox_change_show->show();
    ui->groupBox_change_database->show();
}

void MainWindow::on_btn_change_tabTitle_settings_clicked()
{
    ui->groupBox_side_right_forms->hide();
    ui->groupBox_side_left_forms->hide();
    ui->btn_return_to_home_from_settings_form->hide();


    ui->scrollArea_tabTitle_change->ensureVisible(0,0,0,0);
    ui->groupBox_set_tabTitles->show();
    QSqlQuery q_give_tabTitles("SELECT * FROM tabTitles;");
    while (q_give_tabTitles.next())
    {
        ui->txt_tabTitle_settings_index0->setText(q_give_tabTitles.value("tab_settings_0").toString());
        ui->txt_tabTitle_settings_index1->setText(q_give_tabTitles.value("tab_settings_1").toString());
        ui->txt_tabTitles_userinfo_index0->setText(q_give_tabTitles.value("tab_show_user_info_0").toString());
        ui->txt_tabTitles_userinfo_index1->setText(q_give_tabTitles.value("tab_show_user_info_1").toString());
        ui->txt_tabTitles_userinfo_index2->setText(q_give_tabTitles.value("tab_show_user_info_2").toString());
        ui->txt_tabTitles_userinfo_index3->setText(q_give_tabTitles.value("tab_show_user_info_3").toString());
        ui->txt_tabTitles_userinfo_index4->setText(q_give_tabTitles.value("tab_show_user_info_4").toString());


    }
}

void MainWindow::on_btn_cancel_changes_tabTitles_clicked()
{
    ui->groupBox_set_tabTitles->hide();
    ui->btn_return_to_home_from_settings_form->show();
    ui->groupBox_side_right_forms->show();
    ui->groupBox_side_left_forms->show();
}

void MainWindow::on_btn_save_changes_tabTitles_clicked()
{
    ui->tabWidget_settings->setTabText(0,ui->txt_tabTitle_settings_index0->text());
    ui->tabWidget_settings->setTabText(1,ui->txt_tabTitle_settings_index1->text());
    ui->tabWidget_hs_user_information->setTabText(0,ui->txt_tabTitles_userinfo_index0->text());
    ui->tabWidget_hs_user_information->setTabText(1,ui->txt_tabTitles_userinfo_index1->text());
    ui->tabWidget_hs_user_information->setTabText(2,ui->txt_tabTitles_userinfo_index2->text());
    ui->tabWidget_hs_user_information->setTabText(3,ui->txt_tabTitles_userinfo_index3->text());

    ui->scrollArea_tabTitle_change->ensureVisible(0,0,0,0);
    QSqlQuery q_update_tabTitles("UPDATE tabTitles SET tab_settings_0='"+ui->txt_tabTitle_settings_index0->text()+"',tab_settings_1='"+ui->txt_tabTitle_settings_index1->text()+"',tab_show_user_info_0='"+ui->txt_tabTitles_userinfo_index0->text()+"',tab_show_user_info_1='"+ui->txt_tabTitles_userinfo_index1->text()+"',tab_show_user_info_2='"+ui->txt_tabTitles_userinfo_index2->text()+"',tab_show_user_info_3='"+ui->txt_tabTitles_userinfo_index3->text()+"',tab_show_user_info_4='"+ui->txt_tabTitles_userinfo_index4->text()+"';");
    QMessageBox::information(this," ", "عنوان برگ ها با موفیقت ویرایش و ثبت شدند.");


    ui->groupBox_set_tabTitles->hide();
    ui->btn_return_to_home_from_settings_form->show();
    ui->groupBox_side_right_forms->show();
    ui->groupBox_side_left_forms->show();
}

void MainWindow::on_btn_reset_adminconfig_clicked()
{
    /*//groupBox_resetfactory_tables
    QMessageBox::information(this," ","شامل : تعداد ورودها - نام کاربری و کلمه عبور -  مسیر پشتیبان گیری\n - مسیر عکس پیشفرض -  تعداد (خطاها و حداکثر) مربوط به ورود\n عنوان برنامه");
    if(QMessageBox::question(this," ","آیا از راه اندازی مجدد جدول مدیر اطمینان دارید؟") == QMessageBox::Yes)
    {
        //------create adminconfig TAble
        QSqlQuery dropAdminConfig("DROP TABLE adminconfig;");
        QSqlQuery createAdminConfig("CREATE TABLE adminconfig(username TEXT,password TEXT,maxtry TEXT,currenttry TEXT,total_logins TEXT,defualt_avatar TEXT,db_auto_backup TEXT,db_path_backup TEXT,window_title TEXT);");
        QSqlQuery makeDefaultValuesToAdminCofnfig("INSERT INTO `adminconfig` (`username`,`password`,`maxtry`,`currenttry`,`total_logins`,`defualt_avatar`,`db_auto_backup`,`db_path_backup`) VALUES ('admin','admin','5','0','0','NULL','disable','C:/','management-application v0.3');");
        //------end of adminconfig creator..
        QMessageBox::information(this," ","عملیات با موفیقت تموم شد.");

    }
    else
    {
        //nothing..
    }*/
}

void MainWindow::on_btn_reset_adminloginslog_clicked()
{
    /*if(QMessageBox::question(this," ","آیا از راه اندازی مجدد جدول تاریخچه ورود مدیر اطمینان دارید؟") == QMessageBox::Yes)
    {
        //-----create adminloginslog
        QSqlQuery drop_table_adminloginslog("DROP TABLE adminloginslog;");
        QSqlQuery createTableAdminloginslog("CREATE TABLE adminloginslog(login_number TEXT, login_date TEXT);");
        QSqlQuery add_Default_value_to_adminsloginlog("INSERT INTO adminloginslog (`login_number`,`login_date`) VALUES ('login_0','unknow date');");
        //--------------------- end of adminloginlogs
        QMessageBox::information(this," ","عملیات با موفیقت تموم شد.");

    }
    else
    {
        //nothing..
    }*/
}

void MainWindow::on_btn_reset_hs_users_clicked()
{
    /*if(QMessageBox::question(this," ","آیا از راه اندازی مجدد جدول اعضای حسینیه اطمینان دارید؟") == QMessageBox::Yes)
    {
        //---------------- registreation auto creator table registration
        QSqlQuery droptblregistration("DROP TABLE registration;");
        QSqlQuery createTablex("CREATE TABLE registration(p0 TEXT);");
        for(int i=1;i<=29;i++)
            QSqlQuery createTablex("ALTER TABLE registration ADD p"+QString::number(i)+" TEXT;");

        QSqlQuery createTablexe("ALTER TABLE registration ADD p30 TEXT;");
        //--------------end of registreation auto creator
        QMessageBox::information(this," ","عملیات با موفیقت تموم شد.");

    }
    else
    {
        //nothing..
    }*/
}

void MainWindow::on_btn_reset_hs_titles_clicked()
{
    /*if(QMessageBox::question(this," ","آیا از راه اندازی مجدد جدول عناوین اعضای حسینیه اطمینان دارید؟") == QMessageBox::Yes)
    {
        //-------- create registrationTitles 0-29
        QSqlQuery droptblregistraionTitles("DROP TABLE registrationTitles;");
        QMessageBox::information(this," ","بدلیل سنگینی این عملیات لطفا تا پایان عملیات صبر کنید.");

        QSqlQuery createTable("CREATE TABLE registrationTitles(t0 TEXT);");
        for(int i=0;i<=29;i++)
        {
            QSqlQuery createTitles("ALTER TABLE registrationTitles ADD t"+QString::number(i)+" TEXT;");
            QSqlQuery createDisabelStats("ALTER TABLE registrationTitles ADD disable_status"+QString::number(i)+" TEXT;");
        }
        QSqlQuery updateDefualtValuesToTitleForRegistraion("INSERT INTO `registrationTitles` (`t0`, `t1`, `t2`, `t3`, `t4`, `t5`, `t6`, `t7`, `t8`, `t9`, `t10`, `t11`, `t12`, `t13`, `t14`, `t15`, `t16`, `t17`, `t18`, `t19`, `t20`, `t21`, `t22`, `t23`, `t24`, `t25`, `t26`, `t27`, `t28`, `t29`, `disable_status0`, `disable_status1`, `disable_status2`, `disable_status3`, `disable_status4`, `disable_status5`, `disable_status6`, `disable_status7`, `disable_status8`, `disable_status9`, `disable_status10`, `disable_status11`, `disable_status12`, `disable_status13`, `disable_status14`, `disable_status15`, `disable_status16`, `disable_status17`, `disable_status18`, `disable_status19`, `disable_status20`, `disable_status21`, `disable_status22`, `disable_status23`, `disable_status24`, `disable_status25`, `disable_status26`, `disable_status27`, `disable_status28`, `disable_status29`) VALUES ('NULL', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);");
        for(int i=0;i<=29;i++)
            QSqlQuery updateDefualtValuesToDisableStatusForRegistraion("UPDATE registrationTitles SET disable_status"+QString::number(i)+"='0'"); //false


        QSqlQuery updateDefualtValuesToTitlesForRegistraion("UPDATE registrationTitles SET t0='کدملی‌ :', t1='نام :', t2='نام خانوادگی‌ :', t3='نام پدر :';");

        for(int i=4;i<=29;i++)
            QSqlQuery updateDefualtValuesToTitlesForRegistraion("UPDATE registrationTitles SET t"+QString::number(i)+"='t"+QString::number(i)+"'");

        //------------- end of registrationTitles
        QMessageBox::information(this," ","عملیات با موفیقت تموم شد.");

    }
    else
    {
        //nothing..
    }*/
}

void MainWindow::on_btn_reset_tabTitles_clicked()
{
    /*if(QMessageBox::question(this," ","آیا از راه اندازی مجدد جدول عناوین برگ ها (تب) اطمینان دارید؟") == QMessageBox::Yes)
    {
        //------create tabTitles
        QSqlQuery droptbltabTitles("DROp TABLE tabTitles;");
        QSqlQuery createTabletabTitle("CREATE TABLE tabTitles(tab_settings_0 TEXT,tab_settings_1 TEXT,tab_show_user_info_0 TEXT, tab_show_user_info_1 TEXT, tab_show_user_info_2 TEXT, tab_show_user_info_3 TEXT);");
        QSqlQuery insert_defualt_values_to_tbl_tabTitle("INSET INTO tabTitles (`فرم ها`"
                                                        ",`پیکربندی`"
                                                        ",`مشخصات کاربر`"
                                                        ",`سایر ۱"
                                                        ",`سایر ۲`"
                                                        ",`سایر ۳`);");

        //---------------end of tabTitles
        QMessageBox::information(this," ","عملیات با موفیقت تموم شد.");
    }
    else
    {
        //nothing..
    }*/
}

void MainWindow::on_btn_cancel_from_resetfactory_clicked()
{
    /*ui->groupBox_resetfactory_tables->hide();
    ui->groupBox_change_database->show();
    ui->groupBox_change_show->show();
    ui->btn_return_home_from_config->show();
    ui->btn_show_adminloginslog_from_config->show();*/
}

void MainWindow::on_hs_search_triggered()
{
    im_from_hs_list = true;
    ui->groupBox_search_hs_users->setTitle("جستجو اعضای حسینیه");
    bool the_status_for_set_check_all=false;
    ui->cbox_select_all->setText("همه فعال");
    ui->rbutton_search_likes_from_hs_users_yes->setChecked(the_status_for_set_check_all);
    ui->rbutton_search_likes_from_hs_users_no->setChecked(the_status_for_set_check_all);
    ui->cbox_select_all->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t1->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t0->setChecked(the_status_for_set_check_all);   ui->cbox_select_t16->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t2->setChecked(the_status_for_set_check_all);   ui->cbox_select_t17->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t3->setChecked(the_status_for_set_check_all);   ui->cbox_select_t18->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t4->setChecked(the_status_for_set_check_all);   ui->cbox_select_t19->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t5->setChecked(the_status_for_set_check_all);   ui->cbox_select_t20->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t6->setChecked(the_status_for_set_check_all);   ui->cbox_select_t21->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t7->setChecked(the_status_for_set_check_all);   ui->cbox_select_t22->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t8->setChecked(the_status_for_set_check_all);   ui->cbox_select_t23->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t9->setChecked(the_status_for_set_check_all);   ui->cbox_select_t24->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t10->setChecked(the_status_for_set_check_all);   ui->cbox_select_t25->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t11->setChecked(the_status_for_set_check_all);   ui->cbox_select_t26->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t12->setChecked(the_status_for_set_check_all);   ui->cbox_select_t27->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t13->setChecked(the_status_for_set_check_all);   ui->cbox_select_t28->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t14->setChecked(the_status_for_set_check_all);   ui->cbox_select_t29->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t15->setChecked(the_status_for_set_check_all);


    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();



    ui->txt_text_search_for_hs_users->clear();



    ui->scrollArea_checkboxs_select_part_search_from_hs_users->ensureVisible(0,0,0,0);
    ui->groupBox_search_hs_users->show();
    QSqlQuery q_give_titles_from_hs_titles("SELECT * FROM registrationTitles");
    while(q_give_titles_from_hs_titles.next())
    {
        ui->cbox_select_t0->setText(q_give_titles_from_hs_titles.value("t0").toString());
        ui->cbox_select_t1->setText(q_give_titles_from_hs_titles.value("t1").toString());
        ui->cbox_select_t2->setText(q_give_titles_from_hs_titles.value("t2").toString());
        ui->cbox_select_t3->setText(q_give_titles_from_hs_titles.value("t3").toString());
        ui->cbox_select_t4->setText(q_give_titles_from_hs_titles.value("t4").toString());
        ui->cbox_select_t5->setText(q_give_titles_from_hs_titles.value("t5").toString());
        ui->cbox_select_t6->setText(q_give_titles_from_hs_titles.value("t6").toString());
        ui->cbox_select_t7->setText(q_give_titles_from_hs_titles.value("t7").toString());
        ui->cbox_select_t8->setText(q_give_titles_from_hs_titles.value("t8").toString());
        ui->cbox_select_t9->setText(q_give_titles_from_hs_titles.value("t9").toString());
        ui->cbox_select_t10->setText(q_give_titles_from_hs_titles.value("t10").toString());
        ui->cbox_select_t11->setText(q_give_titles_from_hs_titles.value("t11").toString());
        ui->cbox_select_t12->setText(q_give_titles_from_hs_titles.value("t12").toString());
        ui->cbox_select_t13->setText(q_give_titles_from_hs_titles.value("t13").toString());
        ui->cbox_select_t14->setText(q_give_titles_from_hs_titles.value("t14").toString());
        ui->cbox_select_t15->setText(q_give_titles_from_hs_titles.value("t15").toString());
        ui->cbox_select_t16->setText(q_give_titles_from_hs_titles.value("t16").toString());
        ui->cbox_select_t17->setText(q_give_titles_from_hs_titles.value("t17").toString());
        ui->cbox_select_t18->setText(q_give_titles_from_hs_titles.value("t18").toString());
        ui->cbox_select_t19->setText(q_give_titles_from_hs_titles.value("t19").toString());
        ui->cbox_select_t20->setText(q_give_titles_from_hs_titles.value("t20").toString());
        ui->cbox_select_t21->setText(q_give_titles_from_hs_titles.value("t21").toString());
        ui->cbox_select_t22->setText(q_give_titles_from_hs_titles.value("t22").toString());
        ui->cbox_select_t23->setText(q_give_titles_from_hs_titles.value("t23").toString());
        ui->cbox_select_t24->setText(q_give_titles_from_hs_titles.value("t24").toString());
        ui->cbox_select_t25->setText(q_give_titles_from_hs_titles.value("t25").toString());
        ui->cbox_select_t26->setText(q_give_titles_from_hs_titles.value("t26").toString());
        ui->cbox_select_t27->setText(q_give_titles_from_hs_titles.value("t27").toString());
        ui->cbox_select_t28->setText(q_give_titles_from_hs_titles.value("t28").toString());
        ui->cbox_select_t29->setText(q_give_titles_from_hs_titles.value("t29").toString());
    }

}

void MainWindow::on_btn_cancel_search_from_hs_users_clicked()
{

    if(ui->btn_goto_this_user_from_search_result->text() == "افزودن")
    {
        ui->btn_goto_this_user_from_search_result->setText("نمایش اطلاعات");
        im_want_to_select_student_from_list_students_for_add_to_class=false;
        bool the_status_for_set_check_all=false;
        ui->cbox_select_all->setText("همه فعال");
        ui->rbutton_search_likes_from_hs_users_yes->setChecked(the_status_for_set_check_all);
        ui->rbutton_search_likes_from_hs_users_no->setChecked(the_status_for_set_check_all);
        ui->cbox_select_all->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t1->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t0->setChecked(the_status_for_set_check_all);   ui->cbox_select_t16->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t2->setChecked(the_status_for_set_check_all);   ui->cbox_select_t17->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t3->setChecked(the_status_for_set_check_all);   ui->cbox_select_t18->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t4->setChecked(the_status_for_set_check_all);   ui->cbox_select_t19->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t5->setChecked(the_status_for_set_check_all);   ui->cbox_select_t20->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t6->setChecked(the_status_for_set_check_all);   ui->cbox_select_t21->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t7->setChecked(the_status_for_set_check_all);   ui->cbox_select_t22->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t8->setChecked(the_status_for_set_check_all);   ui->cbox_select_t23->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t9->setChecked(the_status_for_set_check_all);   ui->cbox_select_t24->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t10->setChecked(the_status_for_set_check_all);   ui->cbox_select_t25->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t11->setChecked(the_status_for_set_check_all);   ui->cbox_select_t26->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t12->setChecked(the_status_for_set_check_all);   ui->cbox_select_t27->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t13->setChecked(the_status_for_set_check_all);   ui->cbox_select_t28->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t14->setChecked(the_status_for_set_check_all);   ui->cbox_select_t29->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t15->setChecked(the_status_for_set_check_all);

        ui->groupBox_search_hs_users->hide();
        ui->groupBox_home->show();
    }
    else
    {
        bool the_status_for_set_check_all=false;
        ui->cbox_select_all->setText("همه فعال");
        ui->rbutton_search_likes_from_hs_users_yes->setChecked(the_status_for_set_check_all);
        ui->rbutton_search_likes_from_hs_users_no->setChecked(the_status_for_set_check_all);
        ui->cbox_select_all->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t1->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t0->setChecked(the_status_for_set_check_all);   ui->cbox_select_t16->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t2->setChecked(the_status_for_set_check_all);   ui->cbox_select_t17->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t3->setChecked(the_status_for_set_check_all);   ui->cbox_select_t18->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t4->setChecked(the_status_for_set_check_all);   ui->cbox_select_t19->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t5->setChecked(the_status_for_set_check_all);   ui->cbox_select_t20->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t6->setChecked(the_status_for_set_check_all);   ui->cbox_select_t21->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t7->setChecked(the_status_for_set_check_all);   ui->cbox_select_t22->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t8->setChecked(the_status_for_set_check_all);   ui->cbox_select_t23->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t9->setChecked(the_status_for_set_check_all);   ui->cbox_select_t24->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t10->setChecked(the_status_for_set_check_all);   ui->cbox_select_t25->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t11->setChecked(the_status_for_set_check_all);   ui->cbox_select_t26->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t12->setChecked(the_status_for_set_check_all);   ui->cbox_select_t27->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t13->setChecked(the_status_for_set_check_all);   ui->cbox_select_t28->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t14->setChecked(the_status_for_set_check_all);   ui->cbox_select_t29->setChecked(the_status_for_set_check_all);
        ui->cbox_select_t15->setChecked(the_status_for_set_check_all);

        ui->groupBox_search_hs_users->hide();
        ui->groupBox_home->show();
    }



}

void MainWindow::on_btn_go_search_from_hs_users_clicked()
{
    if(ui->rbutton_search_likes_from_hs_users_no->isChecked() == false && ui->rbutton_search_likes_from_hs_users_yes->isChecked() == false)
    {
        QMessageBox::information(this," ","لطفا در بخش (نمونه های مشابه هم نمایش داده شوند) یک مورد را انتخاب کنید");
    }
    else
    {
        if(ui->txt_text_search_for_hs_users->text().size() <= 0)
        {
            QMessageBox::information(this," ", "پرکردن یک مقدار برای جستجو در فیلد اجباری است");
        }
        else
        {

            //load title
            ui->tableWidget_search_result->clear();




            ui->tableWidget_search_result->verticalHeader()->hide();
            ui->listWidget_search_result->hide();
            ui->lbl_title_from_search_result->hide();

            int ssss=0;
            int rowcount = 0;
            ui->tableWidget_search_result->setRowCount(rowcount);
            ui->tableWidget_search_result->setColumnCount(4);
            QSqlQuery q_guve("SELECT * FROM headers;");
            while(q_guve.next())
            {
                ui->tableWidget_search_result->setHorizontalHeaderLabels(QString(q_guve.value("sr0").toString()+";"+q_guve.value("sr1").toString()+";"+q_guve.value("sr2").toString()+";"+q_guve.value("sr3").toString()+";").split(";"));
            }

            QString para0,para1,para2,para3;
            QString table_name_is_here = "";
            if(ui->groupBox_search_hs_users->title() == "جستجو دانش آموزان")
            {
                table_name_is_here = "students";
            }

            else if(ui->groupBox_search_hs_users->title() == "جستجو اعضای حسینیه")
            {
                table_name_is_here = "registration";
            }
//            ui->listWidget_search_result->clear();
            QString space_betweens_packages = "\t";
            QString big_space_betweens_packages = "\t\t";
            ui->groupBox_search_hs_users->hide();
            ui->groupBox_search_result->show();
            if(ui->rbutton_search_likes_from_hs_users_yes->isChecked() == true)
            {

                //--- Data 0
                if(ui->cbox_select_t0->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p0 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p0").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ big_space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + space_betweens_packages + q_give_for_cbox_t0.value("p0").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                    //add item after here with this name : ui->cbox_select_t0->text();
                }

                //--- Data 1
                if(ui->cbox_select_t1->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p1 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p1").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p1").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 2
                if(ui->cbox_select_t2->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p2 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p2").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p2").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }


                //--- Data 3
                if(ui->cbox_select_t3->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p3 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p3").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p3").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }
                //--- Data 4
                if(ui->cbox_select_t4->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p4 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p4").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p4").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 5
                if(ui->cbox_select_t5->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p5 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p5").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p5").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 6
                if(ui->cbox_select_t6->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p6 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p6").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p6").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 7
                if(ui->cbox_select_t7->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p7 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p7").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p7").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 8
                if(ui->cbox_select_t8->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p8 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p8").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p8").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 9
                if(ui->cbox_select_t9->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p9 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p9").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p9").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 10
                if(ui->cbox_select_t10->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p10 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p10").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p10").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 11
                if(ui->cbox_select_t11->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p11 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p11").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p11").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 12
                if(ui->cbox_select_t12->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p12 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p12").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p12").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 13
                if(ui->cbox_select_t13->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p13 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p13").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p13").toString();                ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 14
                if(ui->cbox_select_t14->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p14 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p14").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p14").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 15
                if(ui->cbox_select_t15->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p15 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p15").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p15").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 16
                if(ui->cbox_select_t16->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p16 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p16").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p16").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 17
                if(ui->cbox_select_t17->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p17 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p17").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p17").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 18
                if(ui->cbox_select_t18->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p18 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p18").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p18").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }


                //--- Data 19
                if(ui->cbox_select_t19->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p19 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p19").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p19").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 20
                if(ui->cbox_select_t20->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p20 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p20").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p20").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 21
                if(ui->cbox_select_t21->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p21 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p21").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p21").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 22
                if(ui->cbox_select_t22->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p22 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p22").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p22").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 23
                if(ui->cbox_select_t23->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p23 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p23").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p23").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }    //void on_hs_search_triggered();


                //--- Data 24
                if(ui->cbox_select_t24->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p24 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p24").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p24").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 25
                if(ui->cbox_select_t25->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p25 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p25").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p25").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 26
                if(ui->cbox_select_t26->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p26 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p26").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p26").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 27
                if(ui->cbox_select_t27->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p27 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p27").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p27").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 28
                if(ui->cbox_select_t28->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p28 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p28").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p28").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 29
                if(ui->cbox_select_t29->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p29 LIKE '%"+ui->txt_text_search_for_hs_users->text()+"%';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p29").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p29").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }
            }
            else
            {
                QString space_betweens_packages = "\t";
                QString big_space_betweens_packages = "\t\t";
                //--- Data 0
                if(ui->cbox_select_t0->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p0='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p0").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p0").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                    //add item after here with this name : ui->cbox_select_t0->text();
                }

                //--- Data 1
                if(ui->cbox_select_t1->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p1='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p1").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p1").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 2
                if(ui->cbox_select_t2->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p2='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p2").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p2").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }


                //--- Data 3
                if(ui->cbox_select_t3->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p3='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p3").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p3").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }
                //--- Data 4
                if(ui->cbox_select_t4->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p4='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p4").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p4").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 5
                if(ui->cbox_select_t5->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p5='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p5").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p5").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 6
                if(ui->cbox_select_t6->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p6='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                   {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p6").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p6").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 7
                if(ui->cbox_select_t7->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p7='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p7").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p7").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 8
                if(ui->cbox_select_t8->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p8='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p8").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p8").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 9
                if(ui->cbox_select_t9->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p9='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p9").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p9").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 10
                if(ui->cbox_select_t10->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p10='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p10").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p10").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 11
                if(ui->cbox_select_t11->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p11='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p11").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p11").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 12
                if(ui->cbox_select_t12->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p12='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p12").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p12").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 13
                if(ui->cbox_select_t13->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p13='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p13").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p13").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 14
                if(ui->cbox_select_t14->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p14='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p14").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p14").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 15
                if(ui->cbox_select_t15->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p15='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p15").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p15").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 16
                if(ui->cbox_select_t16->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p16='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p16").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p16").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 17
                if(ui->cbox_select_t17->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p17='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p17").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p17").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 18
                if(ui->cbox_select_t18->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p18='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p18").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p18").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }


                //--- Data 19
                if(ui->cbox_select_t19->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p19='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p19").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p19").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 20
                if(ui->cbox_select_t20->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p20='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p20").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p20").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 21
                if(ui->cbox_select_t21->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p21='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p21").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p21").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 22
                if(ui->cbox_select_t22->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p22='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p22").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p22").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 23
                if(ui->cbox_select_t23->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p23='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p23").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p23").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }    //void on_hs_search_triggered();


                //--- Data 24
                if(ui->cbox_select_t24->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p24='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p24").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p24").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 25
                if(ui->cbox_select_t25->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p25='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p25").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p25").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 26
                if(ui->cbox_select_t26->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p26='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p26").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p26").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 27
                if(ui->cbox_select_t27->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p27='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p27").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p27").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 28
                if(ui->cbox_select_t28->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p28='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p28").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p28").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }

                //--- Data 29
                if(ui->cbox_select_t29->isChecked() == true)
                {
                    QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE p29='"+ui->txt_text_search_for_hs_users->text()+"';");
                    while(q_give_for_cbox_t0.next())
                    {
                        ++rowcount;
                        ui->tableWidget_search_class_result->setRowCount(rowcount);
                        para0 = q_give_for_cbox_t0.value("p0").toString();
                        para1 = q_give_for_cbox_t0.value("p1").toString();
                        para2 = q_give_for_cbox_t0.value("p2").toString();
                        para3 = q_give_for_cbox_t0.value("p29").toString();
                        ui->tableWidget_search_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                        ui->tableWidget_search_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                        ui->tableWidget_search_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                        ui->tableWidget_search_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                        ssss++;
//                        QString data_package = q_give_for_cbox_t0.value("p0").toString()+ space_betweens_packages+ q_give_for_cbox_t0.value("p1").toString()+ space_betweens_packages + q_give_for_cbox_t0.value("p2").toString() + big_space_betweens_packages + q_give_for_cbox_t0.value("p29").toString();
//                        ui->listWidget_search_result->addItem(data_package);
                    }
                }
            }
        }
    }
}


void MainWindow::on_cbox_select_all_stateChanged(int)
{
    bool the_status_for_set_check_all=true;
    if(ui->cbox_select_all->text()== "همه فعال")
    {
        the_status_for_set_check_all = true;
        ui->cbox_select_all->setText("همه غیرفعال");
    }
    else
    {
        the_status_for_set_check_all = false;
        ui->cbox_select_all->setText("همه فعال");
    }
    ui->cbox_select_t1->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t0->setChecked(the_status_for_set_check_all);   ui->cbox_select_t16->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t2->setChecked(the_status_for_set_check_all);   ui->cbox_select_t17->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t3->setChecked(the_status_for_set_check_all);   ui->cbox_select_t18->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t4->setChecked(the_status_for_set_check_all);   ui->cbox_select_t19->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t5->setChecked(the_status_for_set_check_all);   ui->cbox_select_t20->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t6->setChecked(the_status_for_set_check_all);   ui->cbox_select_t21->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t7->setChecked(the_status_for_set_check_all);   ui->cbox_select_t22->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t8->setChecked(the_status_for_set_check_all);   ui->cbox_select_t23->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t9->setChecked(the_status_for_set_check_all);   ui->cbox_select_t24->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t10->setChecked(the_status_for_set_check_all);   ui->cbox_select_t25->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t11->setChecked(the_status_for_set_check_all);   ui->cbox_select_t26->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t12->setChecked(the_status_for_set_check_all);   ui->cbox_select_t27->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t13->setChecked(the_status_for_set_check_all);   ui->cbox_select_t28->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t14->setChecked(the_status_for_set_check_all);   ui->cbox_select_t29->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t15->setChecked(the_status_for_set_check_all);
}

void MainWindow::on_btn_goto_this_user_from_search_result_clicked()
{
    QString what_title_change = "";
    QString what_table_change = "";
    QString fileds_title_table = "";
    if(im_want_to_select_student_from_list_students_for_add_to_class == true)
    {
//        if(ui->listWidget_search_result->selectedItems().size() > 0)
//        {
//            QString name = ui->listWidget_search_result->currentItem()->text();
//            QStringRef user_code_id = name.leftRef(10);
//            code_meli = user_code_id.toString();
//        }
//        else
//        {
//            QMessageBox::critical(this," ","هیچ کاربری انتخاب نشده است.");
//        }

        int row = ui->tableWidget_search_result->currentRow();
        int column = ui->tableWidget_search_result->currentColumn();
        QString student_idcode = ui->tableWidget_search_result->model()->index(row,column).data().toString();
        code_meli = student_idcode;

        ui->scrollArea_need_data_to_add_student_to_this_class->ensureVisible(0,0,0,0);
        ui->groupBox_search_result->hide();
        ui->listWidget_search_result->clear();
        QSqlQuery q_give_student_info_for_insert_to_class("SELECT * FROM students WHERE p0='"+code_meli+"';");
        QString my_temp_variable,my_temp_variable1,my_temp_variable2,my_temp_variable3;
        while(q_give_student_info_for_insert_to_class.next())
        {
            my_temp_variable = q_give_student_info_for_insert_to_class.value("p0").toString();
            my_temp_variable1 = q_give_student_info_for_insert_to_class.value("p1").toString();
            my_temp_variable2 = q_give_student_info_for_insert_to_class.value("p2").toString();
            my_temp_variable3 = q_give_student_info_for_insert_to_class.value("p3").toString();
        }
        //        QMessageBox::information(this," ","im in my_temp_variable and value="+my_temp_variable);
        QSqlQuery q_add_a_student_to_this_class0("INSERT INTO "+class_id_is_herex+" (cp0) VALUES ('"+my_temp_variable+"');");
        QSqlQuery q_update_cid_now("UPDATE "+class_id_is_herex+" SET cp1='"+my_temp_variable1+"',cp2='"+my_temp_variable2+"',cp3='"+my_temp_variable3+"' WHERE cp0='"+my_temp_variable+"';");


        ui->txt_stu_data_to_this_class_0->setText(my_temp_variable);
        ui->txt_stu_data_to_this_class_1->setText(my_temp_variable1);
        ui->txt_stu_data_to_this_class_2->setText(my_temp_variable2);
        ui->txt_stu_data_to_this_class_3->setText(my_temp_variable3);
        ui->txt_stu_data_to_this_class_4->clear(); ui->txt_stu_data_to_this_class_5->clear(); ui->txt_stu_data_to_this_class_6->clear();ui->txt_stu_data_to_this_class_7->clear();ui->txt_stu_data_to_this_class_8->clear();ui->txt_stu_data_to_this_class_9->clear();ui->txt_stu_data_to_this_class_10->clear();ui->txt_stu_data_to_this_class_11->clear();ui->txt_stu_data_to_this_class_12->clear();ui->txt_stu_data_to_this_class_13->clear();ui->txt_stu_data_to_this_class_14->clear();
        ui->btn_show_users_hs->setText("نمایش اطلاعات");

        QSqlQuery q_give_class_parameters_from_classid("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
        while(q_give_class_parameters_from_classid.next())
        {
            ui->lbl_stu_data_to_this_class_0->setText(q_give_class_parameters_from_classid.value("cp0").toString());
            ui->lbl_stu_data_to_this_class_1->setText(q_give_class_parameters_from_classid.value("cp1").toString());
            ui->lbl_stu_data_to_this_class_2->setText(q_give_class_parameters_from_classid.value("cp2").toString());
            ui->lbl_stu_data_to_this_class_3->setText(q_give_class_parameters_from_classid.value("cp3").toString());
            ui->lbl_stu_data_to_this_class_4->setText(q_give_class_parameters_from_classid.value("cp4").toString());
            ui->lbl_stu_data_to_this_class_5->setText(q_give_class_parameters_from_classid.value("cp5").toString());
            ui->lbl_stu_data_to_this_class_6->setText(q_give_class_parameters_from_classid.value("cp6").toString());
            ui->lbl_stu_data_to_this_class_7->setText(q_give_class_parameters_from_classid.value("cp7").toString());
            ui->lbl_stu_data_to_this_class_8->setText(q_give_class_parameters_from_classid.value("cp8").toString());
            ui->lbl_stu_data_to_this_class_9->setText(q_give_class_parameters_from_classid.value("cp9").toString());
            ui->lbl_stu_data_to_this_class_10->setText(q_give_class_parameters_from_classid.value("cp10").toString());
            ui->lbl_stu_data_to_this_class_11->setText(q_give_class_parameters_from_classid.value("cp11").toString());
            ui->lbl_stu_data_to_this_class_12->setText(q_give_class_parameters_from_classid.value("cp12").toString());
            ui->lbl_stu_data_to_this_class_13->setText(q_give_class_parameters_from_classid.value("cp13").toString());
            ui->lbl_stu_data_to_this_class_14->setText(q_give_class_parameters_from_classid.value("cp14").toString());
        }
        ui->groupBox_insert_more_data_to_student_for_this_class->show();
        ui->btn_goto_this_user_from_search_result->setText("نمایش");
        im_want_to_select_student_from_list_students_for_add_to_class=false;
    }
    else if(ui->groupBox_search_hs_users->title() == "جستجو اعضای حسینیه")
    {
        ui->tabWidget_hs_user_information->setTabEnabled(4,false);
        what_title_change = "registrationTitles";
        what_table_change = "registration";
        fileds_title_table = "t";

        ui->groupBox_search_result->hide();
        ui->btn_hs_userinfo_return_to_users_list->setText("بازگشت به لیست جستجو");
        QSqlQuery q_give_tab_titles("SELECT * FROM tabTitles;");
        while(q_give_tab_titles.next())
        {
            ui->tabWidget_hs_user_information->setTabText(0,q_give_tab_titles.value("tab_show_user_info_0").toString());
            ui->tabWidget_hs_user_information->setTabText(1,q_give_tab_titles.value("tab_show_user_info_1").toString());
            ui->tabWidget_hs_user_information->setTabText(2,q_give_tab_titles.value("tab_show_user_info_2").toString());
            ui->tabWidget_hs_user_information->setTabText(3,q_give_tab_titles.value("tab_show_user_info_3").toString());
            ui->tabWidget_hs_user_information->setTabText(4,q_give_tab_titles.value("tab_show_user_info_4").toString());

        }
        ui->scrollArea_register->ensureVisible(0,0,0,0);
//        if(ui->listWidget_search_result->selectedItems().size() > 0)
//        {
//            QString name = ui->listWidget_search_result->currentItem()->text();
//            QString user_code_id = name.left(10);
            int row = ui->tableWidget_search_result->currentRow();
            int column = ui->tableWidget_search_result->currentColumn();
            QString user_code_id = ui->tableWidget_search_result->model()->index(row,column).data().toString();


            //do other
            ui->groupBox_search_result->hide();
            ui->groupBox_hs_user_information->show();
            //remove all values from userinformation
            ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
            ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
            ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
            ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
            ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
            ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
            ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
            ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
            ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
            ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
            ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
            ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
            ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
            ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
            ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
            ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
            ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
            ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
            ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
            ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
            ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
            ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
            ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
            ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
            ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
            ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
            ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
            ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
            ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
            ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
            ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();

            //give titles
            QSqlQuery q_Hs_Load_Title("SELECT * FROM "+what_title_change+";");
            while (q_Hs_Load_Title.next())
            {
                ui->lbl_hs_userinfo_t0->setText(q_Hs_Load_Title.value(fileds_title_table+"0").toString()); ui->lbl_hs_userinfo_t1->setText(q_Hs_Load_Title.value(fileds_title_table+"1").toString()); ui->lbl_hs_userinfo_t2->setText(q_Hs_Load_Title.value(fileds_title_table+"2").toString()); ui->lbl_hs_userinfo_t3->setText(q_Hs_Load_Title.value(fileds_title_table+"3").toString()); ui->lbl_hs_userinfo_t4->setText(q_Hs_Load_Title.value(fileds_title_table+"4").toString());                ui->lbl_hs_userinfo_t5->setText(q_Hs_Load_Title.value(fileds_title_table+"5").toString()); ui->lbl_hs_userinfo_t6->setText(q_Hs_Load_Title.value(fileds_title_table+"6").toString());               ui->lbl_hs_userinfo_t7->setText(q_Hs_Load_Title.value(fileds_title_table+"7").toString());  ui->lbl_hs_userinfo_t8->setText(q_Hs_Load_Title.value(fileds_title_table+"8").toString());              ui->lbl_hs_userinfo_t9->setText(q_Hs_Load_Title.value(fileds_title_table+"9").toString()); ui->lbl_hs_userinfo_t10->setText(q_Hs_Load_Title.value(fileds_title_table+"10").toString());                ui->lbl_hs_userinfo_t11->setText(q_Hs_Load_Title.value(fileds_title_table+"11").toString()); ui->lbl_hs_userinfo_t12->setText(q_Hs_Load_Title.value(fileds_title_table+"12").toString()); ui->lbl_hs_userinfo_t13->setText(q_Hs_Load_Title.value(fileds_title_table+"13").toString());                 ui->lbl_hs_userinfo_t14->setText(q_Hs_Load_Title.value(fileds_title_table+"14").toString()); ui->lbl_hs_userinfo_t15->setText(q_Hs_Load_Title.value(fileds_title_table+"15").toString());                ui->lbl_hs_userinfo_t16->setText(q_Hs_Load_Title.value(fileds_title_table+"16").toString());  ui->lbl_hs_userinfo_t17->setText(q_Hs_Load_Title.value(fileds_title_table+"17").toString()); ui->lbl_hs_userinfo_t18->setText(q_Hs_Load_Title.value(fileds_title_table+"18").toString());ui->lbl_hs_userinfo_t19->setText(q_Hs_Load_Title.value(fileds_title_table+"19").toString());ui->lbl_hs_userinfo_t20->setText(q_Hs_Load_Title.value(fileds_title_table+"20").toString());ui->lbl_hs_userinfo_t21->setText(q_Hs_Load_Title.value(fileds_title_table+"21").toString());ui->lbl_hs_userinfo_t22->setText(q_Hs_Load_Title.value(fileds_title_table+"22").toString());ui->lbl_hs_userinfo_t23->setText(q_Hs_Load_Title.value(fileds_title_table+"23").toString());ui->lbl_hs_userinfo_t24->setText(q_Hs_Load_Title.value(fileds_title_table+"24").toString());ui->lbl_hs_userinfo_t25->setText(q_Hs_Load_Title.value(fileds_title_table+"25").toString());ui->lbl_hs_userinfo_t26->setText(q_Hs_Load_Title.value(fileds_title_table+"26").toString()); ui->lbl_hs_userinfo_t27->setText(q_Hs_Load_Title.value(fileds_title_table+"27").toString());ui->lbl_hs_userinfo_t28->setText(q_Hs_Load_Title.value(fileds_title_table+"28").toString()); ui->lbl_hs_userinfo_t29->setText(q_Hs_Load_Title.value(fileds_title_table+"29").toString());
            }

            //give data WHERE idcode = database
            QSqlQuery q_hs_userinformation_show("SELECT * FROM "+what_table_change+" WHERE p0='"+user_code_id+"';");
            while (q_hs_userinformation_show.next())
            {
                ui->lbl_hs_userinfo_p0->setText(q_hs_userinformation_show.value("p0").toString());   ui->lbl_hs_userinfo_p1->setText(q_hs_userinformation_show.value("p1").toString());
                ui->lbl_hs_userinfo_p2->setText(q_hs_userinformation_show.value("p2").toString());   ui->lbl_hs_userinfo_p3->setText(q_hs_userinformation_show.value("p3").toString());
                ui->lbl_hs_userinfo_p4->setText(q_hs_userinformation_show.value("p4").toString());   ui->lbl_hs_userinfo_p5->setText(q_hs_userinformation_show.value("p5").toString());
                ui->lbl_hs_userinfo_p6->setText(q_hs_userinformation_show.value("p6").toString());   ui->lbl_hs_userinfo_p7->setText(q_hs_userinformation_show.value("p7").toString());
                ui->lbl_hs_userinfo_p8->setText(q_hs_userinformation_show.value("p8").toString());   ui->lbl_hs_userinfo_p9->setText(q_hs_userinformation_show.value("p9").toString());
                ui->lbl_hs_userinfo_p10->setText(q_hs_userinformation_show.value("p10").toString()); ui->lbl_hs_userinfo_p11->setText(q_hs_userinformation_show.value("p11").toString());
                ui->lbl_hs_userinfo_p12->setText(q_hs_userinformation_show.value("p12").toString()); ui->lbl_hs_userinfo_p13->setText(q_hs_userinformation_show.value("p13").toString());
                ui->lbl_hs_userinfo_p14->setText(q_hs_userinformation_show.value("p14").toString()); ui->lbl_hs_userinfo_p15->setText(q_hs_userinformation_show.value("p15").toString());
                ui->lbl_hs_userinfo_p16->setText(q_hs_userinformation_show.value("p16").toString()); ui->lbl_hs_userinfo_p17->setText(q_hs_userinformation_show.value("p17").toString());
                ui->lbl_hs_userinfo_p18->setText(q_hs_userinformation_show.value("p18").toString()); ui->lbl_hs_userinfo_p19->setText(q_hs_userinformation_show.value("p19").toString());
                ui->lbl_hs_userinfo_p20->setText(q_hs_userinformation_show.value("p20").toString()); ui->lbl_hs_userinfo_p21->setText(q_hs_userinformation_show.value("p21").toString());
                ui->lbl_hs_userinfo_p22->setText(q_hs_userinformation_show.value("p22").toString()); ui->lbl_hs_userinfo_p23->setText(q_hs_userinformation_show.value("p23").toString());
                ui->lbl_hs_userinfo_p24->setText(q_hs_userinformation_show.value("p24").toString()); ui->lbl_hs_userinfo_p25->setText(q_hs_userinformation_show.value("p25").toString());
                ui->lbl_hs_userinfo_p26->setText(q_hs_userinformation_show.value("p26").toString()); ui->lbl_hs_userinfo_p27->setText(q_hs_userinformation_show.value("p27").toString());
                ui->lbl_hs_userinfo_p28->setText(q_hs_userinformation_show.value("p28").toString()); ui->lbl_hs_userinfo_p29->setText(q_hs_userinformation_show.value("p29").toString());
                avatar_url = q_hs_userinformation_show.value("p30").toString();
                QPixmap avatar_from_edit(avatar_url); ui->lbl_hs_userinfo_avatar->setPixmap(avatar_url); ui->lbl_hs_userinfo_avatar->setScaledContents(true);
            }



            ui->listWidget_show_student_scores->clear();
            QSqlQuery q_give_scores_of_this_student("SELECT * FROM score_"+ui->lbl_hs_userinfo_p0->text()+";");
            //{
            while(q_give_scores_of_this_student.next())
            {
                QString space_between = "\t  ";
                QString i_will_make_a_package_of_this_student_information =
                        q_give_scores_of_this_student.value("p0").toString()+ space_between +
                        q_give_scores_of_this_student.value("p1").toString()+ space_between +
                        q_give_scores_of_this_student.value("p2").toString()+ space_between +
                        q_give_scores_of_this_student.value("p3").toString()+ space_between +
                        q_give_scores_of_this_student.value("p4").toString()+ space_between +
                        q_give_scores_of_this_student.value("p5").toString()+ space_between +
                        q_give_scores_of_this_student.value("p6").toString()+ space_between +
                        q_give_scores_of_this_student.value("p7").toString()+ space_between +
                        q_give_scores_of_this_student.value("p8").toString()+ space_between +
                        q_give_scores_of_this_student.value("p9").toString()+ space_between +
                        q_give_scores_of_this_student.value("p10").toString()+ space_between +
                        //                            q_give_scores_of_this_student.value("p11").toString()+ space_between +
                        //                            q_give_scores_of_this_student.value("p12").toString()+ space_between +
                        //                            q_give_scores_of_this_student.value("p13").toString()+ space_between +
                        //                            q_give_scores_of_this_student.value("p14").toString()+ space_between +
                        q_give_scores_of_this_student.value("p15").toString()+ space_between +
                        q_give_scores_of_this_student.value("p16").toString()+ space_between +
                        q_give_scores_of_this_student.value("p17").toString()+ space_between +
                        q_give_scores_of_this_student.value("p18").toString()+ space_between +
                        q_give_scores_of_this_student.value("p19").toString()+ space_between +
                        q_give_scores_of_this_student.value("p20").toString()+ space_between +
                        q_give_scores_of_this_student.value("p21").toString()+ space_between +
                        q_give_scores_of_this_student.value("p22").toString()+ space_between +
                        q_give_scores_of_this_student.value("p23").toString()+ space_between +
                        q_give_scores_of_this_student.value("p24").toString()+ space_between +
                        q_give_scores_of_this_student.value("p25").toString()+ space_between +
                        q_give_scores_of_this_student.value("p26").toString()+ space_between +
                        q_give_scores_of_this_student.value("p27").toString()+ space_between +
                        q_give_scores_of_this_student.value("p28").toString()+ space_between +
                        q_give_scores_of_this_student.value("p29").toString();


                ui->listWidget_show_student_scores->addItem(i_will_make_a_package_of_this_student_information);
            }
//        }

//        else
//        {
//            QMessageBox::critical(this," ","هیچ کاربری انتخاب نشده است.");
//        }
    }
    else if(ui->groupBox_search_hs_users->title() == "جستجو دانش آموزان")
    {
        ui->tabWidget_hs_user_information->setTabEnabled(4,true);
        what_title_change = "studentTitles";
        what_table_change = "students";
        fileds_title_table = "st";
        //load score to tabScore !!!!!
        ui->groupBox_search_result->hide();
        ui->btn_hs_userinfo_return_to_users_list->setText("بازگشت به لیست جستجو");
        QSqlQuery q_give_tab_titles("SELECT * FROM tabTitles;");
        while(q_give_tab_titles.next())
        {
            ui->tabWidget_hs_user_information->setTabText(0,q_give_tab_titles.value("tab_show_user_info_0").toString());
            ui->tabWidget_hs_user_information->setTabText(1,q_give_tab_titles.value("tab_show_user_info_1").toString());
            ui->tabWidget_hs_user_information->setTabText(2,q_give_tab_titles.value("tab_show_user_info_2").toString());
            ui->tabWidget_hs_user_information->setTabText(3,q_give_tab_titles.value("tab_show_user_info_3").toString());
            ui->tabWidget_hs_user_information->setTabText(4,q_give_tab_titles.value("tab_show_user_info_4").toString());

        }
        ui->scrollArea_register->ensureVisible(0,0,0,0);
//        if(ui->listWidget_search_result->selectedItems().size() > 0)
//        {
//            QString name = ui->listWidget_search_result->currentItem()->text();
//            QString user_code_id = name.left(10);
        int row = ui->tableWidget_search_result->currentRow();
        int column = ui->tableWidget_search_result->currentColumn();
        QString user_code_id = ui->tableWidget_search_result->model()->index(row,column).data().toString();

            //do other
            ui->groupBox_search_result->hide();
            ui->groupBox_hs_user_information->show();
            //remove all values from userinformation
            ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
            ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
            ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
            ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
            ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
            ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
            ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
            ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
            ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
            ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
            ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
            ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
            ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
            ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
            ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
            ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
            ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
            ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
            ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
            ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
            ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
            ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
            ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
            ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
            ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
            ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
            ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
            ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
            ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
            ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
            ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();

            //give titles
            QSqlQuery q_Hs_Load_Title("SELECT * FROM "+what_title_change+";");
            while (q_Hs_Load_Title.next())
            {
                ui->lbl_hs_userinfo_t0->setText(q_Hs_Load_Title.value(fileds_title_table+"0").toString()); ui->lbl_hs_userinfo_t1->setText(q_Hs_Load_Title.value(fileds_title_table+"1").toString()); ui->lbl_hs_userinfo_t2->setText(q_Hs_Load_Title.value(fileds_title_table+"2").toString()); ui->lbl_hs_userinfo_t3->setText(q_Hs_Load_Title.value(fileds_title_table+"3").toString()); ui->lbl_hs_userinfo_t4->setText(q_Hs_Load_Title.value(fileds_title_table+"4").toString());                ui->lbl_hs_userinfo_t5->setText(q_Hs_Load_Title.value(fileds_title_table+"5").toString()); ui->lbl_hs_userinfo_t6->setText(q_Hs_Load_Title.value(fileds_title_table+"6").toString());               ui->lbl_hs_userinfo_t7->setText(q_Hs_Load_Title.value(fileds_title_table+"7").toString());  ui->lbl_hs_userinfo_t8->setText(q_Hs_Load_Title.value(fileds_title_table+"8").toString());              ui->lbl_hs_userinfo_t9->setText(q_Hs_Load_Title.value(fileds_title_table+"9").toString()); ui->lbl_hs_userinfo_t10->setText(q_Hs_Load_Title.value(fileds_title_table+"10").toString());                ui->lbl_hs_userinfo_t11->setText(q_Hs_Load_Title.value(fileds_title_table+"11").toString()); ui->lbl_hs_userinfo_t12->setText(q_Hs_Load_Title.value(fileds_title_table+"12").toString()); ui->lbl_hs_userinfo_t13->setText(q_Hs_Load_Title.value(fileds_title_table+"13").toString());                 ui->lbl_hs_userinfo_t14->setText(q_Hs_Load_Title.value(fileds_title_table+"14").toString()); ui->lbl_hs_userinfo_t15->setText(q_Hs_Load_Title.value(fileds_title_table+"15").toString());                ui->lbl_hs_userinfo_t16->setText(q_Hs_Load_Title.value(fileds_title_table+"16").toString());  ui->lbl_hs_userinfo_t17->setText(q_Hs_Load_Title.value(fileds_title_table+"17").toString()); ui->lbl_hs_userinfo_t18->setText(q_Hs_Load_Title.value(fileds_title_table+"18").toString());ui->lbl_hs_userinfo_t19->setText(q_Hs_Load_Title.value(fileds_title_table+"19").toString());ui->lbl_hs_userinfo_t20->setText(q_Hs_Load_Title.value(fileds_title_table+"20").toString());ui->lbl_hs_userinfo_t21->setText(q_Hs_Load_Title.value(fileds_title_table+"21").toString());ui->lbl_hs_userinfo_t22->setText(q_Hs_Load_Title.value(fileds_title_table+"22").toString());ui->lbl_hs_userinfo_t23->setText(q_Hs_Load_Title.value(fileds_title_table+"23").toString());ui->lbl_hs_userinfo_t24->setText(q_Hs_Load_Title.value(fileds_title_table+"24").toString());ui->lbl_hs_userinfo_t25->setText(q_Hs_Load_Title.value(fileds_title_table+"25").toString());ui->lbl_hs_userinfo_t26->setText(q_Hs_Load_Title.value(fileds_title_table+"26").toString()); ui->lbl_hs_userinfo_t27->setText(q_Hs_Load_Title.value(fileds_title_table+"27").toString());ui->lbl_hs_userinfo_t28->setText(q_Hs_Load_Title.value(fileds_title_table+"28").toString()); ui->lbl_hs_userinfo_t29->setText(q_Hs_Load_Title.value(fileds_title_table+"29").toString());
            }

            //give data WHERE idcode = database
            QSqlQuery q_hs_userinformation_show("SELECT * FROM "+what_table_change+" WHERE p0='"+user_code_id+"';");
            while (q_hs_userinformation_show.next())
            {
                ui->lbl_hs_userinfo_p0->setText(q_hs_userinformation_show.value("p0").toString());   ui->lbl_hs_userinfo_p1->setText(q_hs_userinformation_show.value("p1").toString());
                ui->lbl_hs_userinfo_p2->setText(q_hs_userinformation_show.value("p2").toString());   ui->lbl_hs_userinfo_p3->setText(q_hs_userinformation_show.value("p3").toString());
                ui->lbl_hs_userinfo_p4->setText(q_hs_userinformation_show.value("p4").toString());   ui->lbl_hs_userinfo_p5->setText(q_hs_userinformation_show.value("p5").toString());
                ui->lbl_hs_userinfo_p6->setText(q_hs_userinformation_show.value("p6").toString());   ui->lbl_hs_userinfo_p7->setText(q_hs_userinformation_show.value("p7").toString());
                ui->lbl_hs_userinfo_p8->setText(q_hs_userinformation_show.value("p8").toString());   ui->lbl_hs_userinfo_p9->setText(q_hs_userinformation_show.value("p9").toString());
                ui->lbl_hs_userinfo_p10->setText(q_hs_userinformation_show.value("p10").toString()); ui->lbl_hs_userinfo_p11->setText(q_hs_userinformation_show.value("p11").toString());
                ui->lbl_hs_userinfo_p12->setText(q_hs_userinformation_show.value("p12").toString()); ui->lbl_hs_userinfo_p13->setText(q_hs_userinformation_show.value("p13").toString());
                ui->lbl_hs_userinfo_p14->setText(q_hs_userinformation_show.value("p14").toString()); ui->lbl_hs_userinfo_p15->setText(q_hs_userinformation_show.value("p15").toString());
                ui->lbl_hs_userinfo_p16->setText(q_hs_userinformation_show.value("p16").toString()); ui->lbl_hs_userinfo_p17->setText(q_hs_userinformation_show.value("p17").toString());
                ui->lbl_hs_userinfo_p18->setText(q_hs_userinformation_show.value("p18").toString()); ui->lbl_hs_userinfo_p19->setText(q_hs_userinformation_show.value("p19").toString());
                ui->lbl_hs_userinfo_p20->setText(q_hs_userinformation_show.value("p20").toString()); ui->lbl_hs_userinfo_p21->setText(q_hs_userinformation_show.value("p21").toString());
                ui->lbl_hs_userinfo_p22->setText(q_hs_userinformation_show.value("p22").toString()); ui->lbl_hs_userinfo_p23->setText(q_hs_userinformation_show.value("p23").toString());
                ui->lbl_hs_userinfo_p24->setText(q_hs_userinformation_show.value("p24").toString()); ui->lbl_hs_userinfo_p25->setText(q_hs_userinformation_show.value("p25").toString());
                ui->lbl_hs_userinfo_p26->setText(q_hs_userinformation_show.value("p26").toString()); ui->lbl_hs_userinfo_p27->setText(q_hs_userinformation_show.value("p27").toString());
                ui->lbl_hs_userinfo_p28->setText(q_hs_userinformation_show.value("p28").toString()); ui->lbl_hs_userinfo_p29->setText(q_hs_userinformation_show.value("p29").toString());
                avatar_url = q_hs_userinformation_show.value("p30").toString();
                QPixmap avatar_from_edit(avatar_url); ui->lbl_hs_userinfo_avatar->setPixmap(avatar_url); ui->lbl_hs_userinfo_avatar->setScaledContents(true);
            }



            ui->tableWidget_show_student_scores->clear();


            ui->listWidget_show_student_scores->hide();

            QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM score_"+ui->lbl_hs_userinfo_p0->text()+";");
            QString count_show_users_hs;
            while(q_count_show_users_hs.next())
                count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

            ui->tableWidget_show_student_scores->setRowCount(count_show_users_hs.toInt());
            ui->tableWidget_show_student_scores->setColumnCount(30);
            QSqlQuery q_guve("SELECT * FROM headers;");
            while(q_guve.next())
            {
               ui->tableWidget_show_student_scores->setHorizontalHeaderLabels(QString(q_guve.value("s0").toString()+";"+q_guve.value("s1").toString()+";"+q_guve.value("s2").toString()+";"+q_guve.value("s3").toString()+";"+q_guve.value("s4").toString()+";"+q_guve.value("s5").toString()+";"+q_guve.value("s6").toString()+";"+q_guve.value("s7").toString()+";"+q_guve.value("s8").toString()+";"+q_guve.value("s9").toString()+";"+q_guve.value("s10").toString()+";"+q_guve.value("s11").toString()+";"+q_guve.value("s12").toString()+";"+q_guve.value("s13").toString()+";"+q_guve.value("s14").toString()+";"+q_guve.value("s15").toString()+";"+q_guve.value("s16").toString()+";"+q_guve.value("s17").toString()+";"+q_guve.value("s18").toString()+";"+q_guve.value("s19").toString()+";"+q_guve.value("s20").toString()+";"+q_guve.value("s21").toString()+";"+q_guve.value("s22").toString()+";"+q_guve.value("s23").toString()+";"+q_guve.value("s24").toString()+";"+q_guve.value("s25").toString()+";"+q_guve.value("s26").toString()+";"+q_guve.value("s27").toString()+";"+q_guve.value("s28").toString()+";"+q_guve.value("s29").toString()+";").split(";"));
            }
            ui->tableWidget_show_student_scores->verticalHeader()->hide();
            ui->tableWidget_show_student_scores->setStyleSheet("color:black;");


            int sss = 0;
            QSqlQuery q_give_scores_of_this_student("SELECT * FROM score_"+ui->lbl_hs_userinfo_p0->text()+";");
            //{
            while(q_give_scores_of_this_student.next())
            {
                ui->tableWidget_show_student_scores->setItem(sss, 0, new QTableWidgetItem(q_give_scores_of_this_student.value("p0").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 1, new QTableWidgetItem(q_give_scores_of_this_student.value("p1").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 2, new QTableWidgetItem(q_give_scores_of_this_student.value("p2").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 3, new QTableWidgetItem(q_give_scores_of_this_student.value("p3").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 4, new QTableWidgetItem(q_give_scores_of_this_student.value("p4").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 5, new QTableWidgetItem(q_give_scores_of_this_student.value("p5").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 6, new QTableWidgetItem(q_give_scores_of_this_student.value("p6").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 7, new QTableWidgetItem(q_give_scores_of_this_student.value("p7").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 8, new QTableWidgetItem(q_give_scores_of_this_student.value("p8").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 9, new QTableWidgetItem(q_give_scores_of_this_student.value("p9").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 10, new QTableWidgetItem(q_give_scores_of_this_student.value("p10").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 11, new QTableWidgetItem(q_give_scores_of_this_student.value("p11").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 12, new QTableWidgetItem(q_give_scores_of_this_student.value("p12").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 13, new QTableWidgetItem(q_give_scores_of_this_student.value("p13").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 14, new QTableWidgetItem(q_give_scores_of_this_student.value("p14").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 15, new QTableWidgetItem(q_give_scores_of_this_student.value("p15").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 16, new QTableWidgetItem(q_give_scores_of_this_student.value("p16").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 17, new QTableWidgetItem(q_give_scores_of_this_student.value("p17").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 18, new QTableWidgetItem(q_give_scores_of_this_student.value("p18").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 19, new QTableWidgetItem(q_give_scores_of_this_student.value("p19").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 20, new QTableWidgetItem(q_give_scores_of_this_student.value("p20").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 21, new QTableWidgetItem(q_give_scores_of_this_student.value("p21").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 22, new QTableWidgetItem(q_give_scores_of_this_student.value("p22").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 23, new QTableWidgetItem(q_give_scores_of_this_student.value("p23").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 24, new QTableWidgetItem(q_give_scores_of_this_student.value("p24").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 25, new QTableWidgetItem(q_give_scores_of_this_student.value("p25").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 26, new QTableWidgetItem(q_give_scores_of_this_student.value("p26").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 27, new QTableWidgetItem(q_give_scores_of_this_student.value("p27").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 28, new QTableWidgetItem(q_give_scores_of_this_student.value("p28").toString()));
                ui->tableWidget_show_student_scores->setItem(sss, 29, new QTableWidgetItem(q_give_scores_of_this_student.value("p29").toString()));
                sss++;

            }
//            ui->listWidget_show_student_scores->clear();
//            QSqlQuery q_give_scores_of_this_student("SELECT * FROM score_"+ui->lbl_hs_userinfo_p0->text()+";");
//            //{
//            while(q_give_scores_of_this_student.next())
//            {
//                QString space_between = "\t  ";
//                QString i_will_make_a_package_of_this_student_information =
//                        q_give_scores_of_this_student.value("p0").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p1").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p2").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p3").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p4").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p5").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p6").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p7").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p8").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p9").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p10").toString()+ space_between +
//                        //                            q_give_scores_of_this_student.value("p11").toString()+ space_between +
//                        //                            q_give_scores_of_this_student.value("p12").toString()+ space_between +
//                        //                            q_give_scores_of_this_student.value("p13").toString()+ space_between +
//                        //                            q_give_scores_of_this_student.value("p14").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p15").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p16").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p17").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p18").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p19").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p20").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p21").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p22").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p23").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p24").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p25").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p26").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p27").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p28").toString()+ space_between +
//                        q_give_scores_of_this_student.value("p29").toString();


//                ui->listWidget_show_student_scores->addItem(i_will_make_a_package_of_this_student_information);
//            }
//        }

//        else
//        {
//            QMessageBox::critical(this," ","هیچ کاربری انتخاب نشده است.");
//        }
    }
}

void MainWindow::on_btn_cancel_from_search_result_clicked()
{

    if(ui->btn_goto_this_user_from_search_result->text() == "افزودن")
    {
        ui->btn_goto_this_user_from_search_result->setText("نمایش اطلاعات");
        im_want_to_select_student_from_list_students_for_add_to_class=false;
        ui->groupBox_search_result->hide();
        ui->groupBox_home->show();
        ui->listWidget_search_result->clear();
    }
    else
    {
        ui->groupBox_search_result->hide();
        ui->groupBox_home->show();
        ui->listWidget_search_result->clear();
    }

}

void MainWindow::on_class_create_triggered()
{

    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();




    //clear time
    //ui->txt_class_info_0->clear(); its auto filled!
    ui->txt_class_info_0->clear();
    ui->txt_class_info_1->clear();
    ui->txt_class_info_2->clear();
    ui->txt_class_info_3->clear();
    ui->txt_class_info_4->clear();
    ui->txt_class_info_5->clear();
    ui->txt_class_info_6->clear();
    ui->txt_class_info_7->clear();
    ui->txt_class_info_8->clear();
    ui->txt_class_info_9->clear();
    ui->txt_class_info_10->clear();
    ui->txt_class_info_11->clear();
    ui->txt_class_info_12->clear();
    ui->txt_class_info_13->clear();
    ui->txt_class_info_14->clear();
    ui->txt_class_parameter_0->clear();
    ui->txt_class_parameter_1->clear();
    ui->txt_class_parameter_2->clear();
    ui->txt_class_parameter_3->clear();
    ui->txt_class_parameter_4->clear();
    ui->txt_class_parameter_5->clear();
    ui->txt_class_parameter_6->clear();
    ui->txt_class_parameter_7->clear();
    ui->txt_class_parameter_8->clear();
    ui->txt_class_parameter_9->clear();
    ui->txt_class_parameter_10->clear();
    ui->txt_class_parameter_11->clear();
    ui->txt_class_parameter_12->clear();
    ui->txt_class_parameter_13->clear();
    ui->txt_class_parameter_14->clear();


    ui->btn_save_class->setText("ثبت");
    ui->groupBox_create_class->setTitle("ایجاد کلاس");
    //everything hide!

    //give LAST CLASS ID
    QSqlQuery q_give_last_cid("SELECT * FROM adminconfig;");
    while(q_give_last_cid.next())
    {
        last_class_id_integer = q_give_last_cid.value("last_cid").toInt();
    }
    ui->txt_class_id->setText("cid_"+QString::number(last_class_id_integer));
    //set titls !
    QSqlQuery q_give_titles_class_and_insert("SELECT * FROM t_class_info;");
    while(q_give_titles_class_and_insert.next())
    {
        ui->lbl_class_id->setText(q_give_titles_class_and_insert.value("t_cid").toString());
        ui->lbl_class_info_0->setText(q_give_titles_class_and_insert.value("t_cinfo0").toString());
        ui->lbl_class_info_1->setText(q_give_titles_class_and_insert.value("t_cinfo1").toString());
        ui->lbl_class_info_2->setText(q_give_titles_class_and_insert.value("t_cinfo2").toString());
        ui->lbl_class_info_3->setText(q_give_titles_class_and_insert.value("t_cinfo3").toString());
        ui->lbl_class_info_4->setText(q_give_titles_class_and_insert.value("t_cinfo4").toString());
        ui->lbl_class_info_5->setText(q_give_titles_class_and_insert.value("t_cinfo5").toString());
        ui->lbl_class_info_6->setText(q_give_titles_class_and_insert.value("t_cinfo6").toString());
        ui->lbl_class_info_7->setText(q_give_titles_class_and_insert.value("t_cinfo7").toString());
        ui->lbl_class_info_8->setText(q_give_titles_class_and_insert.value("t_cinfo8").toString());
        ui->lbl_class_info_9->setText(q_give_titles_class_and_insert.value("t_cinfo9").toString());
        ui->lbl_class_info_10->setText(q_give_titles_class_and_insert.value("t_cinfo10").toString());
        ui->lbl_class_info_11->setText(q_give_titles_class_and_insert.value("t_cinfo11").toString());
        ui->lbl_class_info_12->setText(q_give_titles_class_and_insert.value("t_cinfo12").toString());
        ui->lbl_class_info_13->setText(q_give_titles_class_and_insert.value("t_cinfo13").toString());
        ui->lbl_class_info_14->setText(q_give_titles_class_and_insert.value("t_cinfo14").toString());

        ui->lbl_class_parameter_0->setText(q_give_titles_class_and_insert.value("t_cpara0").toString());
        ui->lbl_class_parameter_1->setText(q_give_titles_class_and_insert.value("t_cpara1").toString());
        ui->lbl_class_parameter_2->setText(q_give_titles_class_and_insert.value("t_cpara2").toString());
        ui->lbl_class_parameter_3->setText(q_give_titles_class_and_insert.value("t_cpara3").toString());
        ui->lbl_class_parameter_4->setText(q_give_titles_class_and_insert.value("t_cpara4").toString());
        ui->lbl_class_parameter_5->setText(q_give_titles_class_and_insert.value("t_cpara5").toString());
        ui->lbl_class_parameter_6->setText(q_give_titles_class_and_insert.value("t_cpara6").toString());
        ui->lbl_class_parameter_7->setText(q_give_titles_class_and_insert.value("t_cpara7").toString());
        ui->lbl_class_parameter_8->setText(q_give_titles_class_and_insert.value("t_cpara8").toString());
        ui->lbl_class_parameter_9->setText(q_give_titles_class_and_insert.value("t_cpara9").toString());
        ui->lbl_class_parameter_10->setText(q_give_titles_class_and_insert.value("t_cpara10").toString());
        ui->lbl_class_parameter_11->setText(q_give_titles_class_and_insert.value("t_cpara11").toString());
        ui->lbl_class_parameter_12->setText(q_give_titles_class_and_insert.value("t_cpara12").toString());
        ui->lbl_class_parameter_13->setText(q_give_titles_class_and_insert.value("t_cpara13").toString());
        ui->lbl_class_parameter_14->setText(q_give_titles_class_and_insert.value("t_cpara14").toString());
    }
    ui->groupBox_create_class->show();
    ui->scrollArea_class_modify_create->ensureVisible(0,0,0,0);
}

void MainWindow::on_btn_cancel_class_clicked()
{
    ui->groupBox_create_class->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_btn_save_class_clicked()
{
    if(ui->btn_save_class->text() == "ثبت")
    {
        QMessageBox::information(this," ","درحال ساخت کلاس لطفا صبر کنید");

        QSqlQuery q_update_cid_to_adminconfig("UPDATE adminconfig SET last_cid='"+QString::number(++last_class_id_integer)+"';");
        last_class_id_integer = 0;

        QSqlQuery q_save_everything_to_class("INSERT INTO `class_list` (`cid`,`ci0`,`ci1`,`ci2`,`ci3`,`ci4`,`ci5`,`ci6`,`ci7`,`ci8`,`ci9`,`ci10`,`ci11`,`ci12`,`ci13`,`ci14`,`cp0`,`cp1`,`cp2`,`cp3`,`cp4`,`cp5`,`cp6`,`cp7`,`cp8`,`cp9`,`cp10`,`cp11`,`cp12`,`cp13`,`cp14`) VALUES ('"+ui->txt_class_id->text()+"','"+ui->txt_class_info_0->text()+"','"+ui->txt_class_info_1->text()+"','"+ui->txt_class_info_2->text()+"','"+ui->txt_class_info_3->text()+"','"+ui->txt_class_info_4->text()+"','"+ui->txt_class_info_5->text()+"','"+ui->txt_class_info_6->text()+"','"+ui->txt_class_info_7->text()+"','"+ui->txt_class_info_8->text()+"','"+ui->txt_class_info_9->text()+"','"+ui->txt_class_info_10->text()+"','"+ui->txt_class_info_11->text()+"','"+ui->txt_class_info_12->text()+"','"+ui->txt_class_info_13->text()+"','"+ui->txt_class_info_14->text()+"','"+ui->txt_class_parameter_0->text()+"','"+ui->txt_class_parameter_1->text()+"','"+ui->txt_class_parameter_2->text()+"','"+ui->txt_class_parameter_3->text()+"','"+ui->txt_class_parameter_4->text()+"','"+ui->txt_class_parameter_5->text()+"','"+ui->txt_class_parameter_6->text()+"','"+ui->txt_class_parameter_7->text()+"','"+ui->txt_class_parameter_8->text()+"','"+ui->txt_class_parameter_9->text()+"','"+ui->txt_class_parameter_10->text()+"','"+ui->txt_class_parameter_11->text()+"','"+ui->txt_class_parameter_12->text()+"','"+ui->txt_class_parameter_13->text()+"','"+ui->txt_class_parameter_14->text()+"');");


        QSqlQuery q_create_table_with_cid_name_for_class("CREATE TABLE "+ui->txt_class_id->text()+" (cp0 TEXT);");
        QSqlQuery createDisabelStats("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp1 TEXT;");
        QSqlQuery createDisabelStats1("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp2 TEXT;");
        QSqlQuery createDisabelStats2("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp3 TEXT;");
        QSqlQuery createDisabelStats3("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp4 TEXT;");
        QSqlQuery createDisabelStats4("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp5 TEXT;");
        QSqlQuery createDisabelStats5("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp6 TEXT;");
        QSqlQuery createDisabelStats6("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp7 TEXT;");
        QSqlQuery createDisabelStats7("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp8 TEXT;");
        QSqlQuery createDisabelStats9("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp9 TEXT;");
        QSqlQuery createDisabelStats8("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp10 TEXT;");
        QSqlQuery createDisabelStats10("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp11 TEXT;");
        QSqlQuery createDisabelStats11("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp12 TEXT;");
        QSqlQuery createDisabelStats12("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp13 TEXT;");
        QSqlQuery createDisabelStats13("ALTER TABLE "+ui->txt_class_id->text()+" ADD cp14 TEXT;");
        QMessageBox::information(this," ","کلاس با مشخصات داده شده ساخته شد");

//        if(QMessageBox::question(this," ","کلاس با مشخصات داده شده ساخته شد") == QMessageBox::Yes)
//        {
//            //hide this groupBox and show List Students for select and insert to class
//            ui->groupBox_create_class->hide();
//            ui->groupBox_qustion_add_student_to_this_class_by->show();
//            want_to_select_student_from_list_for_add_to_a_class = true;
//        }
//        else
//        {
//            ui->groupBox_create_class->hide();
//            ui->groupBox_home->show();
//        }
        ui->groupBox_create_class->hide();
        ui->groupBox_home->show();
    }
    else
    {
        //it's for modify ..
    }
}

void MainWindow::on_btn_set_class_titles_clicked()
{
    ui->groupBox_side_right_forms->hide();
    ui->groupBox_side_left_forms->hide();
    ui->scrollArea_change_class_titles->ensureVisible(0,0,0,0);

    ui->btn_return_to_home_from_settings_form->hide();
    ui->groupBox_change_class_titles->show();


    QSqlQuery q_give_titles_class("SELECT * FROM t_class_info;");
    while(q_give_titles_class.next())
    {
        ui->txt_cid_change_title_class->setText(q_give_titles_class.value("t_cid").toString());
        ui->txt_ci0_change_title_class->setText(q_give_titles_class.value("t_cinfo0").toString());
        ui->txt_ci1_change_title_class->setText(q_give_titles_class.value("t_cinfo1").toString());
        ui->txt_ci2_change_title_class->setText(q_give_titles_class.value("t_cinfo2").toString());
        ui->txt_ci3_change_title_class->setText(q_give_titles_class.value("t_cinfo3").toString());
        ui->txt_ci4_change_title_class->setText(q_give_titles_class.value("t_cinfo4").toString());
        ui->txt_ci5_change_title_class->setText(q_give_titles_class.value("t_cinfo5").toString());
        ui->txt_ci6_change_title_class->setText(q_give_titles_class.value("t_cinfo6").toString());
        ui->txt_ci7_change_title_class->setText(q_give_titles_class.value("t_cinfo7").toString());
        ui->txt_ci8_change_title_class->setText(q_give_titles_class.value("t_cinfo8").toString());
        ui->txt_ci9_change_title_class->setText(q_give_titles_class.value("t_cinfo9").toString());
        ui->txt_ci10_change_title_class->setText(q_give_titles_class.value("t_cinfo10").toString());
        ui->txt_ci11_change_title_class->setText(q_give_titles_class.value("t_cinfo11").toString());
        ui->txt_ci12_change_title_class->setText(q_give_titles_class.value("t_cinfo12").toString());
        ui->txt_ci13_change_title_class->setText(q_give_titles_class.value("t_cinfo13").toString());
        ui->txt_ci14_change_title_class->setText(q_give_titles_class.value("t_cinfo14").toString());

        ui->txt_cp0_change_title_class->setText(q_give_titles_class.value("t_cpara0").toString());
        ui->txt_cp1_change_title_class->setText(q_give_titles_class.value("t_cpara1").toString());
        ui->txt_cp2_change_title_class->setText(q_give_titles_class.value("t_cpara2").toString());
        ui->txt_cp3_change_title_class->setText(q_give_titles_class.value("t_cpara3").toString());
        ui->txt_cp4_change_title_class->setText(q_give_titles_class.value("t_cpara4").toString());
        ui->txt_cp5_change_title_class->setText(q_give_titles_class.value("t_cpara5").toString());
        ui->txt_cp6_change_title_class->setText(q_give_titles_class.value("t_cpara6").toString());
        ui->txt_cp7_change_title_class->setText(q_give_titles_class.value("t_cpara7").toString());
        ui->txt_cp8_change_title_class->setText(q_give_titles_class.value("t_cpara8").toString());
        ui->txt_cp9_change_title_class->setText(q_give_titles_class.value("t_cpara9").toString());
        ui->txt_cp10_change_title_class->setText(q_give_titles_class.value("t_cpara10").toString());
        ui->txt_cp11_change_title_class->setText(q_give_titles_class.value("t_cpara11").toString());
        ui->txt_cp12_change_title_class->setText(q_give_titles_class.value("t_cpara12").toString());
        ui->txt_cp13_change_title_class->setText(q_give_titles_class.value("t_cpara13").toString());
        ui->txt_cp14_change_title_class->setText(q_give_titles_class.value("t_cpara14").toString());
    }
}

void MainWindow::on_btn_save_change_titles_class_clicked()
{
    QSqlQuery q_save_all_title_class_changes("UPDATE t_class_info SET t_cid='"+ui->txt_cid_change_title_class->text()+"', t_cinfo0='"+ui->txt_ci0_change_title_class->text()+"', t_cinfo1='"+ui->txt_ci1_change_title_class->text()+"', t_cinfo2='"+ui->txt_ci2_change_title_class->text()+"', t_cinfo3='"+ui->txt_ci3_change_title_class->text()+"', t_cinfo4='"+ui->txt_ci4_change_title_class->text()+"', t_cinfo5='"+ui->txt_ci5_change_title_class->text()+"', t_cinfo6='"+ui->txt_ci6_change_title_class->text()+"', t_cinfo7='"+ui->txt_ci7_change_title_class->text()+"',t_cinfo8='"+ui->txt_ci8_change_title_class->text()+"',t_cinfo9='"+ui->txt_ci9_change_title_class->text()+"',t_cinfo10='"+ui->txt_ci10_change_title_class->text()+"',t_cinfo11='"+ui->txt_ci11_change_title_class->text()+"',t_cinfo12='"+ui->txt_ci12_change_title_class->text()+"',t_cinfo13='"+ui->txt_ci13_change_title_class->text()+"',t_cinfo14='"+ui->txt_ci14_change_title_class->text()+"'"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ",t_cpara0='"+ui->txt_cp0_change_title_class->text()+"',t_cpara1='"+ui->txt_cp1_change_title_class->text()+"',t_cpara2='"+ui->txt_cp2_change_title_class->text()+"',t_cpara3='"+ui->txt_cp3_change_title_class->text()+"',t_cpara4='"+ui->txt_cp4_change_title_class->text()+"',t_cpara5='"+ui->txt_cp5_change_title_class->text()+"',t_cpara6='"+ui->txt_cp6_change_title_class->text()+"',t_cpara7='"+ui->txt_cp7_change_title_class->text()+"',t_cpara8='"+ui->txt_cp8_change_title_class->text()+"',t_cpara9='"+ui->txt_cp9_change_title_class->text()+"',t_cpara10='"+ui->txt_cp10_change_title_class->text()+"',t_cpara11='"+ui->txt_cp11_change_title_class->text()+"',t_cpara12='"+ui->txt_cp12_change_title_class->text()+"',t_cpara13='"+ui->txt_cp13_change_title_class->text()+"',t_cpara14='"+ui->txt_cp14_change_title_class->text()+"';");

    QMessageBox::information(this," ", "فرم ایجاد کلاس با موفیقت ویرایش و ثبت شد.");

    ui->groupBox_change_class_titles->hide();
    ui->btn_return_to_home_from_settings_form->show();
    ui->groupBox_side_right_forms->show();
    ui->groupBox_side_left_forms->show();

}

void MainWindow::on_btn_cancel_change_titles_class_clicked()
{

    ui->groupBox_change_class_titles->hide();
    ui->btn_return_to_home_from_settings_form->show();
    ui->groupBox_side_right_forms->show();
    ui->groupBox_side_left_forms->show();

}

void MainWindow::on_class_list_triggered()
{
//    QSqlQuery q_give_title_class_list("SELECt * FROM adminconfig;");
//    while(q_give_title_class_list.next())
//        ui->txt_class_list_title->setText(q_give_title_class_list.value("t_class_list").toString());


    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();







    ui->groupBox_class_list->show();
    ui->listWidget_class_list->hide();
    ui->txt_class_list_title->hide();
    ui->tableWidget_class_list->clear();



    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM class_list;");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_class_list->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_class_list->setColumnCount(16);
    QSqlQuery q_guve("SELECT * FROM headers;");
    while(q_guve.next())
    {
        ui->tableWidget_class_list->setHorizontalHeaderLabels(QString(q_guve.value("cl0").toString()+";"+q_guve.value("cl1").toString()+";"+q_guve.value("cl2").toString()+";"+q_guve.value("cl3").toString()+";"+q_guve.value("cl4").toString()+";"+q_guve.value("cl5").toString()+";"+q_guve.value("cl6").toString()+";"+q_guve.value("cl7").toString()+";"+q_guve.value("cl8").toString()+";"+q_guve.value("cl9").toString()+";"+q_guve.value("cl10").toString()+";"+q_guve.value("cl11").toString()+";"+q_guve.value("cl12").toString()+";"+q_guve.value("cl13").toString()+";"+q_guve.value("cl14").toString()+";"+q_guve.value("cl15").toString()+";").split(";"));
    }
    ui->tableWidget_class_list->verticalHeader()->hide();
    ui->tableWidget_class_list->setStyleSheet("color:black;");
    QSqlQuery search("SELECT * FROM class_list;");
    QString pid,p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14;
    int sss = 0;
    while (search.next())
    {
        pid = search.value("cid").toString();
        p0 = search.value("ci0").toString();
        p1 = search.value("ci1").toString();
        p2 = search.value("ci2").toString();
        p3 = search.value("ci3").toString();
        p4 = search.value("ci4").toString();
        p5 = search.value("ci5").toString();
        p6 = search.value("ci6").toString();
        p7 = search.value("ci7").toString();
        p8 = search.value("ci8").toString();
        p9 = search.value("ci9").toString();
        p10 = search.value("ci10").toString();
        p11 = search.value("ci11").toString();
        p12 = search.value("ci12").toString();
        p13 = search.value("ci13").toString();
        p14 = search.value("ci14").toString();
        ui->tableWidget_class_list->setItem(sss, 0, new QTableWidgetItem(pid));
        ui->tableWidget_class_list->setItem(sss, 1, new QTableWidgetItem(p0));
        ui->tableWidget_class_list->setItem(sss, 2, new QTableWidgetItem(p1));
        ui->tableWidget_class_list->setItem(sss, 3, new QTableWidgetItem(p2));
        ui->tableWidget_class_list->setItem(sss, 4, new QTableWidgetItem(p3));
        ui->tableWidget_class_list->setItem(sss, 5, new QTableWidgetItem(p4));
        ui->tableWidget_class_list->setItem(sss, 6, new QTableWidgetItem(p5));
        ui->tableWidget_class_list->setItem(sss, 7, new QTableWidgetItem(p6));
        ui->tableWidget_class_list->setItem(sss, 8, new QTableWidgetItem(p7));
        ui->tableWidget_class_list->setItem(sss, 9, new QTableWidgetItem(p8));
        ui->tableWidget_class_list->setItem(sss, 10, new QTableWidgetItem(p9));
        ui->tableWidget_class_list->setItem(sss, 11, new QTableWidgetItem(p10));
        ui->tableWidget_class_list->setItem(sss, 12, new QTableWidgetItem(p11));
        ui->tableWidget_class_list->setItem(sss, 13, new QTableWidgetItem(p12));
        ui->tableWidget_class_list->setItem(sss, 14, new QTableWidgetItem(p13));
        ui->tableWidget_class_list->setItem(sss, 15, new QTableWidgetItem(p14));
        sss++;
    }


//    QString space_betwen_here = "\t";
//    QSqlQuery q_give_class_list("SELECT * FROM class_list;");
//    while (q_give_class_list.next())
//    {
//        ui->listWidget_class_list->addItem(q_give_class_list.value("cid").toString()+"`"
//                                           +space_betwen_here
//                                           +q_give_class_list.value("ci0").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci1").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci2").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci3").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci4").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci5").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci6").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci7").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci8").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci9").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci10").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci11").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci12").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci13").toString()+
//                                           space_betwen_here
//                                           +q_give_class_list.value("ci14").toString());
//  }
}

void MainWindow::on_btn_cancel_from_class_list_clicked()
{
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_btn_change_title_class_list_clicked()
{
//    QSqlQuery q_update_header_class_list("UPDATE headers SET class_list='"+ui->txt_change_title_class_list->text()+"';");
//    ui->txt_class_list_title->setText(ui->txt_change_title_class_list->text());
//    QMessageBox::information(this," ","سرصفحه ی لیست کلاسها باموفیقت ویرایش شد.");
}

void MainWindow::on_btn_show_this_class_clicked()
{
//    if(ui->listWidget_class_list->selectedItems().size() > 0)
//    {
//        QString class_id_is_here_men = ui->listWidget_class_list->currentItem()->text();
//        int j = 0;
//        int number_for_cut = 0;
//        while ((j = class_id_is_here_men.indexOf("`", j)) != -1)
//        {
//            number_for_cut = j;
//            break;
//        }


//        QStringRef ref_class_charecters = class_id_is_here_men.leftRef(number_for_cut);
//        QString remove_cid_charecters = ref_class_charecters.toString();
//        remove_cid_charecters.remove(QString("cid_"), Qt::CaseInsensitive);
//        remove_cid_charecters.replace(QString(" "), QString(""));
//        remove_cid_charecters.remove(QString("`"), Qt::CaseInsensitive);

    int row = ui->tableWidget_class_list->currentRow();
    int column = ui->tableWidget_class_list->currentColumn();
    QString student_idcode = ui->tableWidget_class_list->model()->index(row,column).data().toString();

    QString remove_cid_charecters = student_idcode;
        class_id_is_herex = student_idcode;




        ui->groupBox_class_list->hide();
        ui->scrollArea_class_detials_from_classinfoshow->ensureVisible(0,0,0,0);
        ui->scrollArea_class_info_from_classinfoshow->ensureVisible(0,0,0,0);
        QSqlQuery q_give_titles_and_info_from_t_classinfo_and_class_list("SELECT * FROM t_class_info;");
        while(q_give_titles_and_info_from_t_classinfo_and_class_list.next())
        {
            ui->lbl_show_classinfo_t_cinfo_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo0").toString());
            ui->lbl_show_classinfo_t_cinfo_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo1").toString());
            ui->lbl_show_classinfo_t_cinfo_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo2").toString());
            ui->lbl_show_classinfo_t_cinfo_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo3").toString());
            ui->lbl_show_classinfo_t_cinfo_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo4").toString());
            ui->lbl_show_classinfo_t_cinfo_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo5").toString());
            ui->lbl_show_classinfo_t_cinfo_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo6").toString());
            ui->lbl_show_classinfo_t_cinfo_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo7").toString());
            ui->lbl_show_classinfo_t_cinfo_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo8").toString());
            ui->lbl_show_classinfo_t_cinfo_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo9").toString());
            ui->lbl_show_classinfo_t_cinfo_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo10").toString());
            ui->lbl_show_classinfo_t_cinfo_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo11").toString());
            ui->lbl_show_classinfo_t_cinfo_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo12").toString());
            ui->lbl_show_classinfo_t_cinfo_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo13").toString());
            ui->lbl_show_classinfo_t_cinfo_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo14").toString());

            ui->lbl_show_classinfo_t_cpara_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara0").toString());
            ui->lbl_show_classinfo_t_cpara_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara1").toString());
            ui->lbl_show_classinfo_t_cpara_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara2").toString());
            ui->lbl_show_classinfo_t_cpara_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara3").toString());
            ui->lbl_show_classinfo_t_cpara_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara4").toString());
            ui->lbl_show_classinfo_t_cpara_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara5").toString());
            ui->lbl_show_classinfo_t_cpara_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara6").toString());
            ui->lbl_show_classinfo_t_cpara_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara7").toString());
            ui->lbl_show_classinfo_t_cpara_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara8").toString());
            ui->lbl_show_classinfo_t_cpara_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara9").toString());
            ui->lbl_show_classinfo_t_cpara_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara10").toString());
            ui->lbl_show_classinfo_t_cpara_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara11").toString());
            ui->lbl_show_classinfo_t_cpara_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara12").toString());
            ui->lbl_show_classinfo_t_cpara_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara13").toString());
            ui->lbl_show_classinfo_t_cpara_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara14").toString());
        }

        QSqlQuery q_give_info_from_clasS_list("SELECT * FROM class_list WHERE cid='"+remove_cid_charecters+"';");
        while(q_give_info_from_clasS_list.next())
        {
            ui->lbl_show_classinfo_ci_0->setText(q_give_info_from_clasS_list.value("ci0").toString());
            ui->lbl_show_classinfo_ci_1->setText(q_give_info_from_clasS_list.value("ci1").toString());
            ui->lbl_show_classinfo_ci_2->setText(q_give_info_from_clasS_list.value("ci2").toString());
            ui->lbl_show_classinfo_ci_3->setText(q_give_info_from_clasS_list.value("ci3").toString());
            ui->lbl_show_classinfo_ci_4->setText(q_give_info_from_clasS_list.value("ci4").toString());
            ui->lbl_show_classinfo_ci_5->setText(q_give_info_from_clasS_list.value("ci5").toString());
            ui->lbl_show_classinfo_ci_6->setText(q_give_info_from_clasS_list.value("ci6").toString());
            ui->lbl_show_classinfo_ci_7->setText(q_give_info_from_clasS_list.value("ci7").toString());
            ui->lbl_show_classinfo_ci_8->setText(q_give_info_from_clasS_list.value("ci8").toString());
            ui->lbl_show_classinfo_ci_9->setText(q_give_info_from_clasS_list.value("ci9").toString());
            ui->lbl_show_classinfo_ci_10->setText(q_give_info_from_clasS_list.value("ci10").toString());
            ui->lbl_show_classinfo_ci_11->setText(q_give_info_from_clasS_list.value("ci11").toString());
            ui->lbl_show_classinfo_ci_12->setText(q_give_info_from_clasS_list.value("ci12").toString());
            ui->lbl_show_classinfo_ci_13->setText(q_give_info_from_clasS_list.value("ci13").toString());
            ui->lbl_show_classinfo_ci_14->setText(q_give_info_from_clasS_list.value("ci14").toString());

            ui->lbl_show_classinfo_cp_0->setText(q_give_info_from_clasS_list.value("cp0").toString());
            ui->lbl_show_classinfo_cp_1->setText(q_give_info_from_clasS_list.value("cp1").toString());
            ui->lbl_show_classinfo_cp_2->setText(q_give_info_from_clasS_list.value("cp2").toString());
            ui->lbl_show_classinfo_cp_3->setText(q_give_info_from_clasS_list.value("cp3").toString());
            ui->lbl_show_classinfo_cp_4->setText(q_give_info_from_clasS_list.value("cp4").toString());
            ui->lbl_show_classinfo_cp_5->setText(q_give_info_from_clasS_list.value("cp5").toString());
            ui->lbl_show_classinfo_cp_6->setText(q_give_info_from_clasS_list.value("cp6").toString());
            ui->lbl_show_classinfo_cp_7->setText(q_give_info_from_clasS_list.value("cp7").toString());
            ui->lbl_show_classinfo_cp_8->setText(q_give_info_from_clasS_list.value("cp8").toString());
            ui->lbl_show_classinfo_cp_9->setText(q_give_info_from_clasS_list.value("cp9").toString());
            ui->lbl_show_classinfo_cp_10->setText(q_give_info_from_clasS_list.value("cp10").toString());
            ui->lbl_show_classinfo_cp_11->setText(q_give_info_from_clasS_list.value("cp11").toString());
            ui->lbl_show_classinfo_cp_12->setText(q_give_info_from_clasS_list.value("cp12").toString());
            ui->lbl_show_classinfo_cp_13->setText(q_give_info_from_clasS_list.value("cp13").toString());
            ui->lbl_show_classinfo_cp_14->setText(q_give_info_from_clasS_list.value("cp14").toString());
        }










        ui->tableWidget_list_of_sutdents_for_show_to_class_info->clear();
        ui->listWidget_list_of_sutdents_for_show_to_class_info->hide();

        QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM "+remove_cid_charecters+";");
        QString count_show_users_hs;
        while(q_count_show_users_hs.next())
            count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setRowCount(count_show_users_hs.toInt());
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setColumnCount(15);

        QSqlQuery q_guve("SELECT * FROM headers;");
        while(q_guve.next())
        {
           ui->tableWidget_list_of_sutdents_for_show_to_class_info->setHorizontalHeaderLabels(QString(ui->lbl_show_classinfo_cp_0->text()+";"+ui->lbl_show_classinfo_cp_1->text()+";"+ui->lbl_show_classinfo_cp_2->text()+";"+ui->lbl_show_classinfo_cp_3->text()+";"+ui->lbl_show_classinfo_cp_4->text()+";"+ui->lbl_show_classinfo_cp_5->text()+";"+ui->lbl_show_classinfo_cp_6->text()+";"+ui->lbl_show_classinfo_cp_7->text()+";"+ui->lbl_show_classinfo_cp_8->text()+";"+ui->lbl_show_classinfo_cp_9->text()+";"+ui->lbl_show_classinfo_cp_10->text()+";"+ui->lbl_show_classinfo_cp_11->text()+";"+ui->lbl_show_classinfo_cp_12->text()+";"+ui->lbl_show_classinfo_cp_13->text()+";"+ui->lbl_show_classinfo_cp_14->text()+";").split(";"));
        }

        ui->tableWidget_list_of_sutdents_for_show_to_class_info->verticalHeader()->hide();
        int sss = 0;


        QSqlQuery q_give_students_from_this_class("SELECT * FROM "+remove_cid_charecters+";");
        QString space_between_student_data = "\t\t";
        while(q_give_students_from_this_class.next())
        {

            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 0, new QTableWidgetItem(q_give_students_from_this_class.value("cp0").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 1, new QTableWidgetItem(q_give_students_from_this_class.value("cp1").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 2, new QTableWidgetItem(q_give_students_from_this_class.value("cp2").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 3, new QTableWidgetItem(q_give_students_from_this_class.value("cp3").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 4, new QTableWidgetItem(q_give_students_from_this_class.value("cp4").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 5, new QTableWidgetItem(q_give_students_from_this_class.value("cp5").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 6, new QTableWidgetItem(q_give_students_from_this_class.value("cp6").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 7, new QTableWidgetItem(q_give_students_from_this_class.value("cp7").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 8, new QTableWidgetItem(q_give_students_from_this_class.value("cp8").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 9, new QTableWidgetItem(q_give_students_from_this_class.value("cp9").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 10, new QTableWidgetItem(q_give_students_from_this_class.value("cp10").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 11, new QTableWidgetItem(q_give_students_from_this_class.value("cp11").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 12, new QTableWidgetItem(q_give_students_from_this_class.value("cp12").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 13, new QTableWidgetItem(q_give_students_from_this_class.value("cp13").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 14, new QTableWidgetItem(q_give_students_from_this_class.value("cp14").toString()));
            sss++;
//            QString data_student_will_here_gose_to_package = q_give_students_from_this_class.value("cp0").toString()+  space_between_student_data+
//                    q_give_students_from_this_class.value("cp1").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp2").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp3").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp4").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp5").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp6").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp7").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp8").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp9").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp10").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp11").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp12").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp13").toString()+ space_between_student_data+
//                    q_give_students_from_this_class.value("cp14").toString();

//            ui->listWidget_list_of_sutdents_for_show_to_class_info->addItem(data_student_will_here_gose_to_package);
        }
        ui->groupBox_show_class_info->show();
//    }
//    else
//    {
//        QMessageBox::critical(this," ","هیچ کلاسی انتخاب نشده است.");
//    }
}

//void MainWindow::on_btn_change_score_this_student_in_this_class_clicked()
//{

//    code_student_for_edit_score = ui->listWidget_list_of_sutdents_for_show_to_class_info->currentItem()->text();
//    QStringRef ref_code_student = code_student_for_edit_score.leftRef(10);
//    code_student_for_edit_score = ref_code_student.toString();

//    ui->listWidget_list_of_sutdents_for_show_to_class_info->hide();
//    ui->btn_change_score_this_student_in_this_class->hide();

//    ui->txt_new_score_sutdent_on_this_class->show();
//    ui->btn_save_score_for_this_student->show();
//    ui->btn_cancel_score_for_this_student->show();

//}

//void MainWindow::on_btn_save_score_for_this_student_clicked()
//{
////    QSqlQuery q_update_sutdent_score("UPDATE score_"+code_student_for_edit_score+" SET score='"+ui->txt_new_score_sutdent_on_this_class->text()+"';");
////    ui->txt_new_score_sutdent_on_this_class->hide();
////    ui->btn_save_score_for_this_student->hide();
////    ui->btn_cancel_score_for_this_student->hide();
////    ui->listWidget_list_of_sutdents_for_show_to_class_info->show();
////    ui->btn_change_score_this_student_in_this_class->show();
//}

void MainWindow::on_btn_cancel_score_for_this_student_clicked()
{

}

void MainWindow::on_btn_goto_edit_this_class_clicked()
{
    ui->groupBox_show_class_info->hide();
    ui->groupBox_question_select_one_part_for_edit_class->show();
}

void MainWindow::on_btn_return_to_class_list_clicked()
{
    class_id_is_herex = "";
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->show();

    ui->listWidget_class_list->clear();
    QString space_betwen_here = "\t";
    QSqlQuery q_give_class_list("SELECT * FROM class_list;");
    while (q_give_class_list.next())
    {

        ui->listWidget_class_list->addItem(q_give_class_list.value("cid").toString()+"`"
                                           +space_betwen_here
                                           +q_give_class_list.value("ci0").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci1").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci2").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci3").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci4").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci5").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci6").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci7").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci8").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci9").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci10").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci11").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci12").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci13").toString()+
                                           space_betwen_here
                                           +q_give_class_list.value("ci14").toString());
    }
}

void MainWindow::on_btn_edit_the_info_this_class_clicked()
{
    ui->scrollArea_edit_this_class->ensureVisible(0,0,0,0);
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->show();
    ui->groupBox_edit_this_class->setTitle("ویرایش مشخصات کلاس");
    QSqlQuery q_give_data_and_set_to_titles_for_edit_this_class("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
    while(q_give_data_and_set_to_titles_for_edit_this_class.next())
    {
        ui->txt_edit_this_class_0->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci0").toString());
        ui->txt_edit_this_class_1->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci1").toString());
        ui->txt_edit_this_class_2->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci2").toString());
        ui->txt_edit_this_class_3->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci3").toString());
        ui->txt_edit_this_class_4->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci4").toString());
        ui->txt_edit_this_class_5->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci5").toString());
        ui->txt_edit_this_class_6->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci6").toString());
        ui->txt_edit_this_class_7->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci7").toString());
        ui->txt_edit_this_class_8->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci8").toString());
        ui->txt_edit_this_class_9->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci9").toString());
        ui->txt_edit_this_class_10->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci10").toString());
        ui->txt_edit_this_class_11->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci11").toString());
        ui->txt_edit_this_class_12->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci12").toString());
        ui->txt_edit_this_class_13->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci13").toString());
        ui->txt_edit_this_class_14->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("ci14").toString());
    }
    QSqlQuery q_give_titles_and_info_from_t_classinfo_and_class_list("SELECT * FROM t_class_info;");
    while(q_give_titles_and_info_from_t_classinfo_and_class_list.next())
    {
        ui->lbl_edit_this_class_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo0").toString());
        ui->lbl_edit_this_class_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo1").toString());
        ui->lbl_edit_this_class_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo2").toString());
        ui->lbl_edit_this_class_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo3").toString());
        ui->lbl_edit_this_class_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo4").toString());
        ui->lbl_edit_this_class_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo5").toString());
        ui->lbl_edit_this_class_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo6").toString());
        ui->lbl_edit_this_class_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo7").toString());
        ui->lbl_edit_this_class_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo8").toString());
        ui->lbl_edit_this_class_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo9").toString());
        ui->lbl_edit_this_class_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo10").toString());
        ui->lbl_edit_this_class_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo11").toString());
        ui->lbl_edit_this_class_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo12").toString());
        ui->lbl_edit_this_class_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo13").toString());
        ui->lbl_edit_this_class_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo14").toString());
    }
}

void MainWindow::on_btn_edit_the_parameters_this_class_clicked()
{
    ui->scrollArea_edit_this_class->ensureVisible(0,0,0,0);
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->show();
    ui->groupBox_edit_this_class->setTitle("ویرایش اطلاعات کلاس");
    QSqlQuery q_give_data_and_set_to_titles_for_edit_this_class("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
    while(q_give_data_and_set_to_titles_for_edit_this_class.next())
    {
        ui->txt_edit_this_class_0->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp0").toString());
        ui->txt_edit_this_class_1->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp1").toString());
        ui->txt_edit_this_class_2->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp2").toString());
        ui->txt_edit_this_class_3->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp3").toString());
        ui->txt_edit_this_class_4->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp4").toString());
        ui->txt_edit_this_class_5->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp5").toString());
        ui->txt_edit_this_class_6->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp6").toString());
        ui->txt_edit_this_class_7->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp7").toString());
        ui->txt_edit_this_class_8->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp8").toString());
        ui->txt_edit_this_class_9->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp9").toString());
        ui->txt_edit_this_class_10->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp10").toString());
        ui->txt_edit_this_class_11->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp11").toString());
        ui->txt_edit_this_class_12->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp12").toString());
        ui->txt_edit_this_class_13->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp13").toString());
        ui->txt_edit_this_class_14->setText(q_give_data_and_set_to_titles_for_edit_this_class.value("cp14").toString());
    }

    QSqlQuery q_guve("SELECT * FROM headers;");
    while(q_guve.next())
    {
       ui->tableWidget_list_of_sutdents_for_show_to_class_info->setHorizontalHeaderLabels(QString(ui->lbl_show_classinfo_cp_0->text()+";"+ui->lbl_show_classinfo_cp_1->text()+";"+ui->lbl_show_classinfo_cp_2->text()+";"+ui->lbl_show_classinfo_cp_3->text()+";"+ui->lbl_show_classinfo_cp_4->text()+";"+ui->lbl_show_classinfo_cp_5->text()+";"+ui->lbl_show_classinfo_cp_6->text()+";"+ui->lbl_show_classinfo_cp_7->text()+";"+ui->lbl_show_classinfo_cp_8->text()+";"+ui->lbl_show_classinfo_cp_9->text()+";"+ui->lbl_show_classinfo_cp_10->text()+";"+ui->lbl_show_classinfo_cp_11->text()+";"+ui->lbl_show_classinfo_cp_12->text()+";"+ui->lbl_show_classinfo_cp_13->text()+";"+ui->lbl_show_classinfo_cp_14->text()+";").split(";"));
    }

    QSqlQuery q_give_titles_and_info_from_t_classinfo_and_class_list("SELECT * FROM t_class_info;");
    while(q_give_titles_and_info_from_t_classinfo_and_class_list.next())
    {
        ui->lbl_edit_this_class_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara0").toString());
        ui->lbl_edit_this_class_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara1").toString());
        ui->lbl_edit_this_class_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara2").toString());
        ui->lbl_edit_this_class_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara3").toString());
        ui->lbl_edit_this_class_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara4").toString());
        ui->lbl_edit_this_class_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara5").toString());
        ui->lbl_edit_this_class_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara6").toString());
        ui->lbl_edit_this_class_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara7").toString());
        ui->lbl_edit_this_class_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara8").toString());
        ui->lbl_edit_this_class_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara9").toString());
        ui->lbl_edit_this_class_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara10").toString());
        ui->lbl_edit_this_class_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara11").toString());
        ui->lbl_edit_this_class_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara12").toString());
        ui->lbl_edit_this_class_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara13").toString());
        ui->lbl_edit_this_class_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara14").toString());
    }
}

void MainWindow::on_btn_edit_the_students_this_class_clicked()
{
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_student_from_this_class->show();
    ui->listWidget_edit_student_from_this_class->clear();

    QSqlQuery q_load_titles("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
    while(q_load_titles.next())
    {
        ui->lbl_form_edit_stu_from_class_0->setText(q_load_titles.value("cp0").toString());
        ui->lbl_form_edit_stu_from_class_1->setText(q_load_titles.value("cp1").toString());
        ui->lbl_form_edit_stu_from_class_2->setText(q_load_titles.value("cp2").toString());
        ui->lbl_form_edit_stu_from_class_3->setText(q_load_titles.value("cp3").toString());
        ui->lbl_form_edit_stu_from_class_4->setText(q_load_titles.value("cp4").toString());
        ui->lbl_form_edit_stu_from_class_5->setText(q_load_titles.value("cp5").toString());
        ui->lbl_form_edit_stu_from_class_6->setText(q_load_titles.value("cp6").toString());
        ui->lbl_form_edit_stu_from_class_7->setText(q_load_titles.value("cp7").toString());
        ui->lbl_form_edit_stu_from_class_8->setText(q_load_titles.value("cp8").toString());
        ui->lbl_form_edit_stu_from_class_9->setText(q_load_titles.value("cp9").toString());
        ui->lbl_form_edit_stu_from_class_10->setText(q_load_titles.value("cp10").toString());
        ui->lbl_form_edit_stu_from_class_11->setText(q_load_titles.value("cp11").toString());
        ui->lbl_form_edit_stu_from_class_12->setText(q_load_titles.value("cp12").toString());
        ui->lbl_form_edit_stu_from_class_13->setText(q_load_titles.value("cp13").toString());
        ui->lbl_form_edit_stu_from_class_14->setText(q_load_titles.value("cp14").toString());
    }

    ui->tableWidget_edit_student_from_this_class->clear();
    ui->listWidget_edit_student_from_this_class->hide();



    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM "+class_id_is_herex+";");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_edit_student_from_this_class->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_edit_student_from_this_class->setColumnCount(15);
    QSqlQuery q_guve("SELECT * FROM headers;");
    while(q_guve.next())
    {
       ui->tableWidget_edit_student_from_this_class->setHorizontalHeaderLabels(QString(ui->lbl_show_classinfo_cp_0->text()+";"+ui->lbl_show_classinfo_cp_1->text()+";"+ui->lbl_show_classinfo_cp_2->text()+";"+ui->lbl_show_classinfo_cp_3->text()+";"+ui->lbl_show_classinfo_cp_4->text()+";"+ui->lbl_show_classinfo_cp_5->text()+";"+ui->lbl_show_classinfo_cp_6->text()+";"+ui->lbl_show_classinfo_cp_7->text()+";"+ui->lbl_show_classinfo_cp_8->text()+";"+ui->lbl_show_classinfo_cp_9->text()+";"+ui->lbl_show_classinfo_cp_10->text()+";"+ui->lbl_show_classinfo_cp_11->text()+";"+ui->lbl_show_classinfo_cp_12->text()+";"+ui->lbl_show_classinfo_cp_13->text()+";"+ui->lbl_show_classinfo_cp_14->text()+";").split(";"));
    }


    //
    ui->tableWidget_edit_student_from_this_class->verticalHeader()->hide();

    int sss = 0;

//    QString space_between_student_data = "\t\t";
    QSqlQuery q_give_students_in_this_class("SELECT * FROM "+class_id_is_herex+";");
    while(q_give_students_in_this_class.next())
    {
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 0, new QTableWidgetItem(q_give_students_in_this_class.value("cp0").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 1, new QTableWidgetItem(q_give_students_in_this_class.value("cp1").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 2, new QTableWidgetItem(q_give_students_in_this_class.value("cp2").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 3, new QTableWidgetItem(q_give_students_in_this_class.value("cp3").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 4, new QTableWidgetItem(q_give_students_in_this_class.value("cp4").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 5, new QTableWidgetItem(q_give_students_in_this_class.value("cp5").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 6, new QTableWidgetItem(q_give_students_in_this_class.value("cp6").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 7, new QTableWidgetItem(q_give_students_in_this_class.value("cp7").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 8, new QTableWidgetItem(q_give_students_in_this_class.value("cp8").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 9, new QTableWidgetItem(q_give_students_in_this_class.value("cp9").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 10, new QTableWidgetItem(q_give_students_in_this_class.value("cp10").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 11, new QTableWidgetItem(q_give_students_in_this_class.value("cp11").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 12, new QTableWidgetItem(q_give_students_in_this_class.value("cp12").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 13, new QTableWidgetItem(q_give_students_in_this_class.value("cp13").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 14, new QTableWidgetItem(q_give_students_in_this_class.value("cp14").toString()));
        sss++;
    }


//        QString data_student_will_here_gose_to_package = q_give_students_in_this_class.value("cp0").toString()+  space_between_student_data+
//                q_give_students_in_this_class.value("cp1").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp2").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp3").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp4").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp5").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp6").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp7").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp8").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp9").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp10").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp11").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp12").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp13").toString()+ space_between_student_data+
//                q_give_students_in_this_class.value("cp14").toString();

//        ui->listWidget_edit_student_from_this_class->addItem(data_student_will_here_gose_to_package);
    //}
}

void MainWindow::on_btn_cancel_this_class_edit_clicked()
{
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_question_select_one_part_for_edit_class->show();
}

void MainWindow::on_btn_save_this_class_edit_clicked()
{
    if(ui->groupBox_edit_this_class->title() == "ویرایش مشخصات کلاس")
    {

        QSqlQuery q_update_this_class_info("UPDATE class_list SET ci0='"+ui->txt_edit_this_class_0->text()+"',ci1='"+ui->txt_edit_this_class_1->text()+"',ci2='"+ui->txt_edit_this_class_2->text()+"',ci3='"+ui->txt_edit_this_class_3->text()+"',ci4='"+ui->txt_edit_this_class_4->text()+"',ci5='"+ui->txt_edit_this_class_5->text()+"',ci6='"+ui->txt_edit_this_class_6->text()+"',ci7='"+ui->txt_edit_this_class_7->text()+"',ci8='"+ui->txt_edit_this_class_8->text()+"',ci9='"+ui->txt_edit_this_class_9->text()+"',ci10='"+ui->txt_edit_this_class_10->text()+"',ci11='"+ui->txt_edit_this_class_11->text()+"',ci12='"+ui->txt_edit_this_class_12->text()+"',ci13='"+ui->txt_edit_this_class_13->text()+"',ci14='"+ui->txt_edit_this_class_14->text()+"' WHERE cid='"+class_id_is_herex+"';");
        QMessageBox::information(this," ","مشخصات این کلاس با موفیقت ویرایش شد.");
        ui->groupBox_edit_this_class->hide();
        ui->groupBox_show_class_info->show();

        ui->scrollArea_class_detials_from_classinfoshow->ensureVisible(0,0,0,0);
        ui->scrollArea_class_info_from_classinfoshow->ensureVisible(0,0,0,0);
        QSqlQuery q_give_titles_and_info_from_t_classinfo_and_class_list("SELECT * FROM t_class_info;");
        while(q_give_titles_and_info_from_t_classinfo_and_class_list.next())
        {
            ui->lbl_show_classinfo_t_cinfo_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo0").toString());
            ui->lbl_show_classinfo_t_cinfo_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo1").toString());
            ui->lbl_show_classinfo_t_cinfo_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo2").toString());
            ui->lbl_show_classinfo_t_cinfo_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo3").toString());
            ui->lbl_show_classinfo_t_cinfo_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo4").toString());
            ui->lbl_show_classinfo_t_cinfo_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo5").toString());
            ui->lbl_show_classinfo_t_cinfo_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo6").toString());
            ui->lbl_show_classinfo_t_cinfo_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo7").toString());
            ui->lbl_show_classinfo_t_cinfo_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo8").toString());
            ui->lbl_show_classinfo_t_cinfo_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo9").toString());
            ui->lbl_show_classinfo_t_cinfo_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo10").toString());
            ui->lbl_show_classinfo_t_cinfo_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo11").toString());
            ui->lbl_show_classinfo_t_cinfo_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo12").toString());
            ui->lbl_show_classinfo_t_cinfo_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo13").toString());
            ui->lbl_show_classinfo_t_cinfo_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo14").toString());

            ui->lbl_show_classinfo_t_cpara_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara0").toString());
            ui->lbl_show_classinfo_t_cpara_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara1").toString());
            ui->lbl_show_classinfo_t_cpara_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara2").toString());
            ui->lbl_show_classinfo_t_cpara_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara3").toString());
            ui->lbl_show_classinfo_t_cpara_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara4").toString());
            ui->lbl_show_classinfo_t_cpara_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara5").toString());
            ui->lbl_show_classinfo_t_cpara_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara6").toString());
            ui->lbl_show_classinfo_t_cpara_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara7").toString());
            ui->lbl_show_classinfo_t_cpara_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara8").toString());
            ui->lbl_show_classinfo_t_cpara_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara9").toString());
            ui->lbl_show_classinfo_t_cpara_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara10").toString());
            ui->lbl_show_classinfo_t_cpara_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara11").toString());
            ui->lbl_show_classinfo_t_cpara_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara12").toString());
            ui->lbl_show_classinfo_t_cpara_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara13").toString());
            ui->lbl_show_classinfo_t_cpara_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara14").toString());
        }

        QSqlQuery q_give_info_from_clasS_list("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
        while(q_give_info_from_clasS_list.next())
        {
            ui->lbl_show_classinfo_ci_0->setText(q_give_info_from_clasS_list.value("ci0").toString());
            ui->lbl_show_classinfo_ci_1->setText(q_give_info_from_clasS_list.value("ci1").toString());
            ui->lbl_show_classinfo_ci_2->setText(q_give_info_from_clasS_list.value("ci2").toString());
            ui->lbl_show_classinfo_ci_3->setText(q_give_info_from_clasS_list.value("ci3").toString());
            ui->lbl_show_classinfo_ci_4->setText(q_give_info_from_clasS_list.value("ci4").toString());
            ui->lbl_show_classinfo_ci_5->setText(q_give_info_from_clasS_list.value("ci5").toString());
            ui->lbl_show_classinfo_ci_6->setText(q_give_info_from_clasS_list.value("ci6").toString());
            ui->lbl_show_classinfo_ci_7->setText(q_give_info_from_clasS_list.value("ci7").toString());
            ui->lbl_show_classinfo_ci_8->setText(q_give_info_from_clasS_list.value("ci8").toString());
            ui->lbl_show_classinfo_ci_9->setText(q_give_info_from_clasS_list.value("ci9").toString());
            ui->lbl_show_classinfo_ci_10->setText(q_give_info_from_clasS_list.value("ci10").toString());
            ui->lbl_show_classinfo_ci_11->setText(q_give_info_from_clasS_list.value("ci11").toString());
            ui->lbl_show_classinfo_ci_12->setText(q_give_info_from_clasS_list.value("ci12").toString());
            ui->lbl_show_classinfo_ci_13->setText(q_give_info_from_clasS_list.value("ci13").toString());
            ui->lbl_show_classinfo_ci_14->setText(q_give_info_from_clasS_list.value("ci14").toString());

            ui->lbl_show_classinfo_cp_0->setText(q_give_info_from_clasS_list.value("cp0").toString());
            ui->lbl_show_classinfo_cp_1->setText(q_give_info_from_clasS_list.value("cp1").toString());
            ui->lbl_show_classinfo_cp_2->setText(q_give_info_from_clasS_list.value("cp2").toString());
            ui->lbl_show_classinfo_cp_3->setText(q_give_info_from_clasS_list.value("cp3").toString());
            ui->lbl_show_classinfo_cp_4->setText(q_give_info_from_clasS_list.value("cp4").toString());
            ui->lbl_show_classinfo_cp_5->setText(q_give_info_from_clasS_list.value("cp5").toString());
            ui->lbl_show_classinfo_cp_6->setText(q_give_info_from_clasS_list.value("cp6").toString());
            ui->lbl_show_classinfo_cp_7->setText(q_give_info_from_clasS_list.value("cp7").toString());
            ui->lbl_show_classinfo_cp_8->setText(q_give_info_from_clasS_list.value("cp8").toString());
            ui->lbl_show_classinfo_cp_9->setText(q_give_info_from_clasS_list.value("cp9").toString());
            ui->lbl_show_classinfo_cp_10->setText(q_give_info_from_clasS_list.value("cp10").toString());
            ui->lbl_show_classinfo_cp_11->setText(q_give_info_from_clasS_list.value("cp11").toString());
            ui->lbl_show_classinfo_cp_12->setText(q_give_info_from_clasS_list.value("cp12").toString());
            ui->lbl_show_classinfo_cp_13->setText(q_give_info_from_clasS_list.value("cp13").toString());
            ui->lbl_show_classinfo_cp_14->setText(q_give_info_from_clasS_list.value("cp14").toString());
        }



        ui->listWidget_list_of_sutdents_for_show_to_class_info->clear();
        QSqlQuery q_give_students_from_this_class("SELECT * FROM "+class_id_is_herex+";");
        QString space_between_student_data = "\t\t";
        while(q_give_students_from_this_class.next())
        {
            QString data_student_will_here_gose_to_package = q_give_students_from_this_class.value("cp0").toString()+  space_between_student_data+
                    q_give_students_from_this_class.value("cp1").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp2").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp3").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp4").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp5").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp6").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp7").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp8").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp9").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp10").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp11").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp12").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp13").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp14").toString();

            ui->listWidget_list_of_sutdents_for_show_to_class_info->addItem(data_student_will_here_gose_to_package);
        }
    }
    else if(ui->groupBox_edit_this_class->title() == "ویرایش اطلاعات کلاس")
    {
        QSqlQuery q_update_this_class_info("UPDATE class_list SET cp0='"+ui->txt_edit_this_class_0->text()+"',cp1='"+ui->txt_edit_this_class_1->text()+"',cp2='"+ui->txt_edit_this_class_2->text()+"',cp3='"+ui->txt_edit_this_class_3->text()+"',cp4='"+ui->txt_edit_this_class_4->text()+"',cp5='"+ui->txt_edit_this_class_5->text()+"',cp6='"+ui->txt_edit_this_class_6->text()+"',cp7='"+ui->txt_edit_this_class_7->text()+"',cp8='"+ui->txt_edit_this_class_8->text()+"',cp9='"+ui->txt_edit_this_class_9->text()+"',cp10='"+ui->txt_edit_this_class_10->text()+"',cp11='"+ui->txt_edit_this_class_11->text()+"',cp12='"+ui->txt_edit_this_class_12->text()+"',cp13='"+ui->txt_edit_this_class_13->text()+"',cp14='"+ui->txt_edit_this_class_14->text()+"' WHERE cid='"+class_id_is_herex+"';");
        QMessageBox::information(this," ","اطلاعات این کلاس با موفیقت ویرایش شد.");
        ui->groupBox_edit_this_class->hide();
        ui->groupBox_show_class_info->show();

        ui->scrollArea_class_detials_from_classinfoshow->ensureVisible(0,0,0,0);
        ui->scrollArea_class_info_from_classinfoshow->ensureVisible(0,0,0,0);
        QSqlQuery q_give_titles_and_info_from_t_classinfo_and_class_list("SELECT * FROM t_class_info;");
        while(q_give_titles_and_info_from_t_classinfo_and_class_list.next())
        {
            ui->lbl_show_classinfo_t_cinfo_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo0").toString());
            ui->lbl_show_classinfo_t_cinfo_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo1").toString());
            ui->lbl_show_classinfo_t_cinfo_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo2").toString());
            ui->lbl_show_classinfo_t_cinfo_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo3").toString());
            ui->lbl_show_classinfo_t_cinfo_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo4").toString());
            ui->lbl_show_classinfo_t_cinfo_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo5").toString());
            ui->lbl_show_classinfo_t_cinfo_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo6").toString());
            ui->lbl_show_classinfo_t_cinfo_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo7").toString());
            ui->lbl_show_classinfo_t_cinfo_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo8").toString());
            ui->lbl_show_classinfo_t_cinfo_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo9").toString());
            ui->lbl_show_classinfo_t_cinfo_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo10").toString());
            ui->lbl_show_classinfo_t_cinfo_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo11").toString());
            ui->lbl_show_classinfo_t_cinfo_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo12").toString());
            ui->lbl_show_classinfo_t_cinfo_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo13").toString());
            ui->lbl_show_classinfo_t_cinfo_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo14").toString());

            ui->lbl_show_classinfo_t_cpara_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara0").toString());
            ui->lbl_show_classinfo_t_cpara_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara1").toString());
            ui->lbl_show_classinfo_t_cpara_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara2").toString());
            ui->lbl_show_classinfo_t_cpara_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara3").toString());
            ui->lbl_show_classinfo_t_cpara_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara4").toString());
            ui->lbl_show_classinfo_t_cpara_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara5").toString());
            ui->lbl_show_classinfo_t_cpara_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara6").toString());
            ui->lbl_show_classinfo_t_cpara_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara7").toString());
            ui->lbl_show_classinfo_t_cpara_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara8").toString());
            ui->lbl_show_classinfo_t_cpara_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara9").toString());
            ui->lbl_show_classinfo_t_cpara_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara10").toString());
            ui->lbl_show_classinfo_t_cpara_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara11").toString());
            ui->lbl_show_classinfo_t_cpara_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara12").toString());
            ui->lbl_show_classinfo_t_cpara_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara13").toString());
            ui->lbl_show_classinfo_t_cpara_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara14").toString());
        }

        QSqlQuery q_give_info_from_clasS_list("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
        while(q_give_info_from_clasS_list.next())
        {
            ui->lbl_show_classinfo_ci_0->setText(q_give_info_from_clasS_list.value("ci0").toString());
            ui->lbl_show_classinfo_ci_1->setText(q_give_info_from_clasS_list.value("ci1").toString());
            ui->lbl_show_classinfo_ci_2->setText(q_give_info_from_clasS_list.value("ci2").toString());
            ui->lbl_show_classinfo_ci_3->setText(q_give_info_from_clasS_list.value("ci3").toString());
            ui->lbl_show_classinfo_ci_4->setText(q_give_info_from_clasS_list.value("ci4").toString());
            ui->lbl_show_classinfo_ci_5->setText(q_give_info_from_clasS_list.value("ci5").toString());
            ui->lbl_show_classinfo_ci_6->setText(q_give_info_from_clasS_list.value("ci6").toString());
            ui->lbl_show_classinfo_ci_7->setText(q_give_info_from_clasS_list.value("ci7").toString());
            ui->lbl_show_classinfo_ci_8->setText(q_give_info_from_clasS_list.value("ci8").toString());
            ui->lbl_show_classinfo_ci_9->setText(q_give_info_from_clasS_list.value("ci9").toString());
            ui->lbl_show_classinfo_ci_10->setText(q_give_info_from_clasS_list.value("ci10").toString());
            ui->lbl_show_classinfo_ci_11->setText(q_give_info_from_clasS_list.value("ci11").toString());
            ui->lbl_show_classinfo_ci_12->setText(q_give_info_from_clasS_list.value("ci12").toString());
            ui->lbl_show_classinfo_ci_13->setText(q_give_info_from_clasS_list.value("ci13").toString());
            ui->lbl_show_classinfo_ci_14->setText(q_give_info_from_clasS_list.value("ci14").toString());

            ui->lbl_show_classinfo_cp_0->setText(q_give_info_from_clasS_list.value("cp0").toString());
            ui->lbl_show_classinfo_cp_1->setText(q_give_info_from_clasS_list.value("cp1").toString());
            ui->lbl_show_classinfo_cp_2->setText(q_give_info_from_clasS_list.value("cp2").toString());
            ui->lbl_show_classinfo_cp_3->setText(q_give_info_from_clasS_list.value("cp3").toString());
            ui->lbl_show_classinfo_cp_4->setText(q_give_info_from_clasS_list.value("cp4").toString());
            ui->lbl_show_classinfo_cp_5->setText(q_give_info_from_clasS_list.value("cp5").toString());
            ui->lbl_show_classinfo_cp_6->setText(q_give_info_from_clasS_list.value("cp6").toString());
            ui->lbl_show_classinfo_cp_7->setText(q_give_info_from_clasS_list.value("cp7").toString());
            ui->lbl_show_classinfo_cp_8->setText(q_give_info_from_clasS_list.value("cp8").toString());
            ui->lbl_show_classinfo_cp_9->setText(q_give_info_from_clasS_list.value("cp9").toString());
            ui->lbl_show_classinfo_cp_10->setText(q_give_info_from_clasS_list.value("cp10").toString());
            ui->lbl_show_classinfo_cp_11->setText(q_give_info_from_clasS_list.value("cp11").toString());
            ui->lbl_show_classinfo_cp_12->setText(q_give_info_from_clasS_list.value("cp12").toString());
            ui->lbl_show_classinfo_cp_13->setText(q_give_info_from_clasS_list.value("cp13").toString());
            ui->lbl_show_classinfo_cp_14->setText(q_give_info_from_clasS_list.value("cp14").toString());
        }



        ui->listWidget_list_of_sutdents_for_show_to_class_info->clear();
        QSqlQuery q_give_students_from_this_class("SELECT * FROM "+class_id_is_herex+";");
        QString space_between_student_data = "\t\t";
        while(q_give_students_from_this_class.next())
        {
            QString data_student_will_here_gose_to_package = q_give_students_from_this_class.value("cp0").toString()+  space_between_student_data+
                    q_give_students_from_this_class.value("cp1").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp2").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp3").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp4").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp5").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp6").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp7").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp8").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp9").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp10").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp11").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp12").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp13").toString()+ space_between_student_data+
                    q_give_students_from_this_class.value("cp14").toString();

            ui->listWidget_list_of_sutdents_for_show_to_class_info->addItem(data_student_will_here_gose_to_package);
        }
    }
}

void MainWindow::on_btn_cancel_edit_student_from_this_class_clicked()
{
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_question_select_one_part_for_edit_class->show();
}

void MainWindow::on_btn_edit_this_student_from_this_class_clicked()
{
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->show();
    ui->scrollArea_edit_form_stu_from_class->ensureVisible(0,0,0,0);

//    QString student_meli_code = ui->listWidget_edit_student_from_this_class->currentItem()->text();
//    QStringRef ref_code_student = student_meli_code.leftRef(10);

    int row = ui->tableWidget_edit_student_from_this_class->currentRow();
    int column = ui->tableWidget_edit_student_from_this_class->currentColumn();
    QString ref_code_student = ui->tableWidget_edit_student_from_this_class->model()->index(row,column).data().toString();


    QSqlQuery q_give_data_student ("SELECT * FROM "+class_id_is_herex+" WHERE cp0='"+ref_code_student+"';");
    while(q_give_data_student.next())
    {
        ui->txt_form_edit_stu_from_class_0->setText(q_give_data_student.value("cp0").toString());
        ui->txt_form_edit_stu_from_class_1->setText(q_give_data_student.value("cp1").toString());
        ui->txt_form_edit_stu_from_class_2->setText(q_give_data_student.value("cp2").toString());
        ui->txt_form_edit_stu_from_class_3->setText(q_give_data_student.value("cp3").toString());
        ui->txt_form_edit_stu_from_class_4->setText(q_give_data_student.value("cp4").toString());
        ui->txt_form_edit_stu_from_class_5->setText(q_give_data_student.value("cp5").toString());
        ui->txt_form_edit_stu_from_class_6->setText(q_give_data_student.value("cp6").toString());
        ui->txt_form_edit_stu_from_class_7->setText(q_give_data_student.value("cp7").toString());
        ui->txt_form_edit_stu_from_class_8->setText(q_give_data_student.value("cp8").toString());
        ui->txt_form_edit_stu_from_class_9->setText(q_give_data_student.value("cp9").toString());
        ui->txt_form_edit_stu_from_class_10->setText(q_give_data_student.value("cp10").toString());
        ui->txt_form_edit_stu_from_class_11->setText(q_give_data_student.value("cp11").toString());
        ui->txt_form_edit_stu_from_class_12->setText(q_give_data_student.value("cp12").toString());
        ui->txt_form_edit_stu_from_class_13->setText(q_give_data_student.value("cp13").toString());
        ui->txt_form_edit_stu_from_class_14->setText(q_give_data_student.value("cp14").toString());
    }


    QSqlQuery q_give_titles_from_class_list ("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
    while (q_give_titles_from_class_list.next())
    {
        ui->lbl_form_edit_stu_from_class_0->setText(q_give_titles_from_class_list.value("cp0").toString());
        ui->lbl_form_edit_stu_from_class_1->setText(q_give_titles_from_class_list.value("cp1").toString());
        ui->lbl_form_edit_stu_from_class_2->setText(q_give_titles_from_class_list.value("cp2").toString());
        ui->lbl_form_edit_stu_from_class_3->setText(q_give_titles_from_class_list.value("cp3").toString());
        ui->lbl_form_edit_stu_from_class_4->setText(q_give_titles_from_class_list.value("cp4").toString());
        ui->lbl_form_edit_stu_from_class_5->setText(q_give_titles_from_class_list.value("cp5").toString());
        ui->lbl_form_edit_stu_from_class_6->setText(q_give_titles_from_class_list.value("cp6").toString());
        ui->lbl_form_edit_stu_from_class_7->setText(q_give_titles_from_class_list.value("cp7").toString());
        ui->lbl_form_edit_stu_from_class_8->setText(q_give_titles_from_class_list.value("cp8").toString());
        ui->lbl_form_edit_stu_from_class_9->setText(q_give_titles_from_class_list.value("cp9").toString());
        ui->lbl_form_edit_stu_from_class_10->setText(q_give_titles_from_class_list.value("cp10").toString());
        ui->lbl_form_edit_stu_from_class_11->setText(q_give_titles_from_class_list.value("cp11").toString());
        ui->lbl_form_edit_stu_from_class_12->setText(q_give_titles_from_class_list.value("cp12").toString());
        ui->lbl_form_edit_stu_from_class_13->setText(q_give_titles_from_class_list.value("cp13").toString());
        ui->lbl_form_edit_stu_from_class_14->setText(q_give_titles_from_class_list.value("cp14").toString());
    }

}

void MainWindow::on_btn_cancel_form_stu_from_class_clicked()
{
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_edit_student_from_this_class->show();



    ui->tableWidget_edit_student_from_this_class->clear();
    ui->listWidget_edit_student_from_this_class->hide();



    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM "+class_id_is_herex+";");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_edit_student_from_this_class->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_edit_student_from_this_class->setColumnCount(15);
    QSqlQuery q_guve("SELECT * FROM headers;");
    while(q_guve.next())
    {
       ui->tableWidget_edit_student_from_this_class->setHorizontalHeaderLabels(QString(ui->lbl_show_classinfo_cp_0->text()+";"+ui->lbl_show_classinfo_cp_1->text()+";"+ui->lbl_show_classinfo_cp_2->text()+";"+ui->lbl_show_classinfo_cp_3->text()+";"+ui->lbl_show_classinfo_cp_4->text()+";"+ui->lbl_show_classinfo_cp_5->text()+";"+ui->lbl_show_classinfo_cp_6->text()+";"+ui->lbl_show_classinfo_cp_7->text()+";"+ui->lbl_show_classinfo_cp_8->text()+";"+ui->lbl_show_classinfo_cp_9->text()+";"+ui->lbl_show_classinfo_cp_10->text()+";"+ui->lbl_show_classinfo_cp_11->text()+";"+ui->lbl_show_classinfo_cp_12->text()+";"+ui->lbl_show_classinfo_cp_13->text()+";"+ui->lbl_show_classinfo_cp_14->text()+";").split(";"));
    }


    //
    ui->tableWidget_edit_student_from_this_class->verticalHeader()->hide();

    int sss = 0;

//    QString space_between_student_data = "\t\t";
    QSqlQuery q_give_students_in_this_class("SELECT * FROM "+class_id_is_herex+";");
    while(q_give_students_in_this_class.next())
    {
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 0, new QTableWidgetItem(q_give_students_in_this_class.value("cp0").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 1, new QTableWidgetItem(q_give_students_in_this_class.value("cp1").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 2, new QTableWidgetItem(q_give_students_in_this_class.value("cp2").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 3, new QTableWidgetItem(q_give_students_in_this_class.value("cp3").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 4, new QTableWidgetItem(q_give_students_in_this_class.value("cp4").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 5, new QTableWidgetItem(q_give_students_in_this_class.value("cp5").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 6, new QTableWidgetItem(q_give_students_in_this_class.value("cp6").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 7, new QTableWidgetItem(q_give_students_in_this_class.value("cp7").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 8, new QTableWidgetItem(q_give_students_in_this_class.value("cp8").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 9, new QTableWidgetItem(q_give_students_in_this_class.value("cp9").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 10, new QTableWidgetItem(q_give_students_in_this_class.value("cp10").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 11, new QTableWidgetItem(q_give_students_in_this_class.value("cp11").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 12, new QTableWidgetItem(q_give_students_in_this_class.value("cp12").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 13, new QTableWidgetItem(q_give_students_in_this_class.value("cp13").toString()));
        ui->tableWidget_edit_student_from_this_class->setItem(sss, 14, new QTableWidgetItem(q_give_students_in_this_class.value("cp14").toString()));
        sss++;
    }
}

void MainWindow::on_btn_edit_form_stu_from_class_ok_clicked()
{
    QSqlQuery q_update("UPDATE "+class_id_is_herex+" SET cp1='"+ui->txt_form_edit_stu_from_class_1->text()+"',cp2='"+ui->txt_form_edit_stu_from_class_2->text()+"',cp3='"+ui->txt_form_edit_stu_from_class_3->text()+"',cp4='"+ui->txt_form_edit_stu_from_class_4->text()+"',cp5='"+ui->txt_form_edit_stu_from_class_5->text()+"',cp6='"+ui->txt_form_edit_stu_from_class_6->text()+"',cp7='"+ui->txt_form_edit_stu_from_class_7->text()+"',cp8='"+ui->txt_form_edit_stu_from_class_8->text()+"',cp9='"+ui->txt_form_edit_stu_from_class_9->text()+"',cp10='"+ui->txt_form_edit_stu_from_class_10->text()+"',cp11='"+ui->txt_form_edit_stu_from_class_11->text()+"',cp12='"+ui->txt_form_edit_stu_from_class_12->text()+"',cp13='"+ui->txt_form_edit_stu_from_class_13->text()+"',cp14='"+ui->txt_form_edit_stu_from_class_14->text()+"' WHERE cp0='"+ui->txt_form_edit_stu_from_class_0->text()+"';");
    QString testxx= "score_"+ui->txt_form_edit_stu_from_class_0->text();
    QSqlQuery q_update_score("UPDATE "+testxx+" SET p15='"+ui->txt_form_edit_stu_from_class_4->text()+"', p16='"+ui->txt_form_edit_stu_from_class_5->text()+"', p17='"+ui->txt_form_edit_stu_from_class_6->text()+"', p18='"+ui->txt_form_edit_stu_from_class_7->text()+"', p19='"+ui->txt_form_edit_stu_from_class_8->text()+"', p20='"+ui->txt_form_edit_stu_from_class_9->text()+"', p21='"+ui->txt_form_edit_stu_from_class_10->text()+"', p22='"+ui->txt_form_edit_stu_from_class_11->text()+"', p23='"+ui->txt_form_edit_stu_from_class_12->text()+"', p24='"+ui->txt_form_edit_stu_from_class_13->text()+"' WHERE p0='"+class_id_is_herex+"';");
    //up maybe need to this code ! ,p21='"+ui->txt_form_edit_stu_from_class_10->text()+"',p11='"+ui->txt_form_edit_stu_from_class_11->text()+"',p12='"+ui->txt_form_edit_stu_from_class_12->text()+"',p13='"+ui->txt_form_edit_stu_from_class_13->text()+"',p14='"+ui->txt_form_edit_stu_from_class_14->text()+"'

    QMessageBox::information(this," ","اطلاعات دانش اموز در این کلاس با موفیقت ویرایش شد.");
    ui->groupBox_edit_form_stu_from_class->hide();

    ui->groupBox_show_class_info->show();

    ui->scrollArea_class_detials_from_classinfoshow->ensureVisible(0,0,0,0);
    ui->scrollArea_class_info_from_classinfoshow->ensureVisible(0,0,0,0);
    QSqlQuery q_give_titles_and_info_from_t_classinfo_and_class_list("SELECT * FROM t_class_info;");
    while(q_give_titles_and_info_from_t_classinfo_and_class_list.next())
    {
        ui->lbl_show_classinfo_t_cinfo_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo0").toString());
        ui->lbl_show_classinfo_t_cinfo_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo1").toString());
        ui->lbl_show_classinfo_t_cinfo_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo2").toString());
        ui->lbl_show_classinfo_t_cinfo_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo3").toString());
        ui->lbl_show_classinfo_t_cinfo_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo4").toString());
        ui->lbl_show_classinfo_t_cinfo_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo5").toString());
        ui->lbl_show_classinfo_t_cinfo_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo6").toString());
        ui->lbl_show_classinfo_t_cinfo_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo7").toString());
        ui->lbl_show_classinfo_t_cinfo_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo8").toString());
        ui->lbl_show_classinfo_t_cinfo_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo9").toString());
        ui->lbl_show_classinfo_t_cinfo_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo10").toString());
        ui->lbl_show_classinfo_t_cinfo_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo11").toString());
        ui->lbl_show_classinfo_t_cinfo_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo12").toString());
        ui->lbl_show_classinfo_t_cinfo_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo13").toString());
        ui->lbl_show_classinfo_t_cinfo_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo14").toString());

        ui->lbl_show_classinfo_t_cpara_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara0").toString());
        ui->lbl_show_classinfo_t_cpara_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara1").toString());
        ui->lbl_show_classinfo_t_cpara_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara2").toString());
        ui->lbl_show_classinfo_t_cpara_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara3").toString());
        ui->lbl_show_classinfo_t_cpara_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara4").toString());
        ui->lbl_show_classinfo_t_cpara_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara5").toString());
        ui->lbl_show_classinfo_t_cpara_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara6").toString());
        ui->lbl_show_classinfo_t_cpara_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara7").toString());
        ui->lbl_show_classinfo_t_cpara_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara8").toString());
        ui->lbl_show_classinfo_t_cpara_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara9").toString());
        ui->lbl_show_classinfo_t_cpara_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara10").toString());
        ui->lbl_show_classinfo_t_cpara_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara11").toString());
        ui->lbl_show_classinfo_t_cpara_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara12").toString());
        ui->lbl_show_classinfo_t_cpara_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara13").toString());
        ui->lbl_show_classinfo_t_cpara_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara14").toString());
    }

    QSqlQuery q_give_info_from_clasS_list("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
    while(q_give_info_from_clasS_list.next())
    {
        ui->lbl_show_classinfo_ci_0->setText(q_give_info_from_clasS_list.value("ci0").toString());
        ui->lbl_show_classinfo_ci_1->setText(q_give_info_from_clasS_list.value("ci1").toString());
        ui->lbl_show_classinfo_ci_2->setText(q_give_info_from_clasS_list.value("ci2").toString());
        ui->lbl_show_classinfo_ci_3->setText(q_give_info_from_clasS_list.value("ci3").toString());
        ui->lbl_show_classinfo_ci_4->setText(q_give_info_from_clasS_list.value("ci4").toString());
        ui->lbl_show_classinfo_ci_5->setText(q_give_info_from_clasS_list.value("ci5").toString());
        ui->lbl_show_classinfo_ci_6->setText(q_give_info_from_clasS_list.value("ci6").toString());
        ui->lbl_show_classinfo_ci_7->setText(q_give_info_from_clasS_list.value("ci7").toString());
        ui->lbl_show_classinfo_ci_8->setText(q_give_info_from_clasS_list.value("ci8").toString());
        ui->lbl_show_classinfo_ci_9->setText(q_give_info_from_clasS_list.value("ci9").toString());
        ui->lbl_show_classinfo_ci_10->setText(q_give_info_from_clasS_list.value("ci10").toString());
        ui->lbl_show_classinfo_ci_11->setText(q_give_info_from_clasS_list.value("ci11").toString());
        ui->lbl_show_classinfo_ci_12->setText(q_give_info_from_clasS_list.value("ci12").toString());
        ui->lbl_show_classinfo_ci_13->setText(q_give_info_from_clasS_list.value("ci13").toString());
        ui->lbl_show_classinfo_ci_14->setText(q_give_info_from_clasS_list.value("ci14").toString());

        ui->lbl_show_classinfo_cp_0->setText(q_give_info_from_clasS_list.value("cp0").toString());
        ui->lbl_show_classinfo_cp_1->setText(q_give_info_from_clasS_list.value("cp1").toString());
        ui->lbl_show_classinfo_cp_2->setText(q_give_info_from_clasS_list.value("cp2").toString());
        ui->lbl_show_classinfo_cp_3->setText(q_give_info_from_clasS_list.value("cp3").toString());
        ui->lbl_show_classinfo_cp_4->setText(q_give_info_from_clasS_list.value("cp4").toString());
        ui->lbl_show_classinfo_cp_5->setText(q_give_info_from_clasS_list.value("cp5").toString());
        ui->lbl_show_classinfo_cp_6->setText(q_give_info_from_clasS_list.value("cp6").toString());
        ui->lbl_show_classinfo_cp_7->setText(q_give_info_from_clasS_list.value("cp7").toString());
        ui->lbl_show_classinfo_cp_8->setText(q_give_info_from_clasS_list.value("cp8").toString());
        ui->lbl_show_classinfo_cp_9->setText(q_give_info_from_clasS_list.value("cp9").toString());
        ui->lbl_show_classinfo_cp_10->setText(q_give_info_from_clasS_list.value("cp10").toString());
        ui->lbl_show_classinfo_cp_11->setText(q_give_info_from_clasS_list.value("cp11").toString());
        ui->lbl_show_classinfo_cp_12->setText(q_give_info_from_clasS_list.value("cp12").toString());
        ui->lbl_show_classinfo_cp_13->setText(q_give_info_from_clasS_list.value("cp13").toString());
        ui->lbl_show_classinfo_cp_14->setText(q_give_info_from_clasS_list.value("cp14").toString());
    }



//    ui->groupBox_class_list->show();
    ui->listWidget_class_list->hide();
    ui->txt_class_list_title->hide();
    ui->tableWidget_list_of_sutdents_for_show_to_class_info->clear();

    ui->tableWidget_list_of_sutdents_for_show_to_class_info->clear();
    ui->listWidget_list_of_sutdents_for_show_to_class_info->hide();

    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM "+class_id_is_herex+";");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_list_of_sutdents_for_show_to_class_info->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_list_of_sutdents_for_show_to_class_info->setColumnCount(15);

    QSqlQuery q_guve("SELECT * FROM headers;");
    while(q_guve.next())
    {
       ui->tableWidget_list_of_sutdents_for_show_to_class_info->setHorizontalHeaderLabels(QString(ui->lbl_show_classinfo_cp_0->text()+";"+ui->lbl_show_classinfo_cp_1->text()+";"+ui->lbl_show_classinfo_cp_2->text()+";"+ui->lbl_show_classinfo_cp_3->text()+";"+ui->lbl_show_classinfo_cp_4->text()+";"+ui->lbl_show_classinfo_cp_5->text()+";"+ui->lbl_show_classinfo_cp_6->text()+";"+ui->lbl_show_classinfo_cp_7->text()+";"+ui->lbl_show_classinfo_cp_8->text()+";"+ui->lbl_show_classinfo_cp_9->text()+";"+ui->lbl_show_classinfo_cp_10->text()+";"+ui->lbl_show_classinfo_cp_11->text()+";"+ui->lbl_show_classinfo_cp_12->text()+";"+ui->lbl_show_classinfo_cp_13->text()+";"+ui->lbl_show_classinfo_cp_14->text()+";").split(";"));
    }

    ui->tableWidget_list_of_sutdents_for_show_to_class_info->verticalHeader()->hide();
    int sss = 0;

    QSqlQuery q_give_students_from_this_class("SELECT * FROM "+class_id_is_herex+";");
    QString space_between_student_data = "\t\t";
    while(q_give_students_from_this_class.next())
    {

        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 0, new QTableWidgetItem(q_give_students_from_this_class.value("cp0").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 1, new QTableWidgetItem(q_give_students_from_this_class.value("cp1").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 2, new QTableWidgetItem(q_give_students_from_this_class.value("cp2").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 3, new QTableWidgetItem(q_give_students_from_this_class.value("cp3").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 4, new QTableWidgetItem(q_give_students_from_this_class.value("cp4").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 5, new QTableWidgetItem(q_give_students_from_this_class.value("cp5").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 6, new QTableWidgetItem(q_give_students_from_this_class.value("cp6").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 7, new QTableWidgetItem(q_give_students_from_this_class.value("cp7").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 8, new QTableWidgetItem(q_give_students_from_this_class.value("cp8").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 9, new QTableWidgetItem(q_give_students_from_this_class.value("cp9").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 10, new QTableWidgetItem(q_give_students_from_this_class.value("cp10").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 11, new QTableWidgetItem(q_give_students_from_this_class.value("cp11").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 12, new QTableWidgetItem(q_give_students_from_this_class.value("cp12").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 13, new QTableWidgetItem(q_give_students_from_this_class.value("cp13").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 14, new QTableWidgetItem(q_give_students_from_this_class.value("cp14").toString()));
        sss++;
    }
//    ui->listWidget_list_of_sutdents_for_show_to_class_info->clear();
//    QSqlQuery q_give_students_from_this_class("SELECT * FROM "+class_id_is_herex+";");
//    QString space_between_student_data = "\t\t";
//    while(q_give_students_from_this_class.next())
//    {
//        QString data_student_will_here_gose_to_package = q_give_students_from_this_class.value("cp0").toString()+  space_between_student_data+
//                q_give_students_from_this_class.value("cp1").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp2").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp3").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp4").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp5").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp6").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp7").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp8").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp9").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp10").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp11").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp12").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp13").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp14").toString();

//        ui->listWidget_list_of_sutdents_for_show_to_class_info->addItem(data_student_will_here_gose_to_package);
//    }
}

void MainWindow::on_btn_cancel_edit_this_class_from_this_cid_clicked()
{
    ui->listWidget_list_of_sutdents_for_show_to_class_info->clear();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->scrollArea_class_detials_from_classinfoshow->ensureVisible(0,0,0,0);
    ui->scrollArea_class_info_from_classinfoshow->ensureVisible(0,0,0,0);
    QSqlQuery q_give_titles_and_info_from_t_classinfo_and_class_list("SELECT * FROM t_class_info;");
    while(q_give_titles_and_info_from_t_classinfo_and_class_list.next())
    {
        ui->lbl_show_classinfo_t_cinfo_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo0").toString());
        ui->lbl_show_classinfo_t_cinfo_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo1").toString());
        ui->lbl_show_classinfo_t_cinfo_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo2").toString());
        ui->lbl_show_classinfo_t_cinfo_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo3").toString());
        ui->lbl_show_classinfo_t_cinfo_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo4").toString());
        ui->lbl_show_classinfo_t_cinfo_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo5").toString());
        ui->lbl_show_classinfo_t_cinfo_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo6").toString());
        ui->lbl_show_classinfo_t_cinfo_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo7").toString());
        ui->lbl_show_classinfo_t_cinfo_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo8").toString());
        ui->lbl_show_classinfo_t_cinfo_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo9").toString());
        ui->lbl_show_classinfo_t_cinfo_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo10").toString());
        ui->lbl_show_classinfo_t_cinfo_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo11").toString());
        ui->lbl_show_classinfo_t_cinfo_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo12").toString());
        ui->lbl_show_classinfo_t_cinfo_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo13").toString());
        ui->lbl_show_classinfo_t_cinfo_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo14").toString());

        ui->lbl_show_classinfo_t_cpara_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara0").toString());
        ui->lbl_show_classinfo_t_cpara_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara1").toString());
        ui->lbl_show_classinfo_t_cpara_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara2").toString());
        ui->lbl_show_classinfo_t_cpara_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara3").toString());
        ui->lbl_show_classinfo_t_cpara_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara4").toString());
        ui->lbl_show_classinfo_t_cpara_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara5").toString());
        ui->lbl_show_classinfo_t_cpara_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara6").toString());
        ui->lbl_show_classinfo_t_cpara_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara7").toString());
        ui->lbl_show_classinfo_t_cpara_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara8").toString());
        ui->lbl_show_classinfo_t_cpara_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara9").toString());
        ui->lbl_show_classinfo_t_cpara_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara10").toString());
        ui->lbl_show_classinfo_t_cpara_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara11").toString());
        ui->lbl_show_classinfo_t_cpara_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara12").toString());
        ui->lbl_show_classinfo_t_cpara_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara13").toString());
        ui->lbl_show_classinfo_t_cpara_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara14").toString());
    }

    QSqlQuery q_give_info_from_clasS_list("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
    while(q_give_info_from_clasS_list.next())
    {
        ui->lbl_show_classinfo_ci_0->setText(q_give_info_from_clasS_list.value("ci0").toString());
        ui->lbl_show_classinfo_ci_1->setText(q_give_info_from_clasS_list.value("ci1").toString());
        ui->lbl_show_classinfo_ci_2->setText(q_give_info_from_clasS_list.value("ci2").toString());
        ui->lbl_show_classinfo_ci_3->setText(q_give_info_from_clasS_list.value("ci3").toString());
        ui->lbl_show_classinfo_ci_4->setText(q_give_info_from_clasS_list.value("ci4").toString());
        ui->lbl_show_classinfo_ci_5->setText(q_give_info_from_clasS_list.value("ci5").toString());
        ui->lbl_show_classinfo_ci_6->setText(q_give_info_from_clasS_list.value("ci6").toString());
        ui->lbl_show_classinfo_ci_7->setText(q_give_info_from_clasS_list.value("ci7").toString());
        ui->lbl_show_classinfo_ci_8->setText(q_give_info_from_clasS_list.value("ci8").toString());
        ui->lbl_show_classinfo_ci_9->setText(q_give_info_from_clasS_list.value("ci9").toString());
        ui->lbl_show_classinfo_ci_10->setText(q_give_info_from_clasS_list.value("ci10").toString());
        ui->lbl_show_classinfo_ci_11->setText(q_give_info_from_clasS_list.value("ci11").toString());
        ui->lbl_show_classinfo_ci_12->setText(q_give_info_from_clasS_list.value("ci12").toString());
        ui->lbl_show_classinfo_ci_13->setText(q_give_info_from_clasS_list.value("ci13").toString());
        ui->lbl_show_classinfo_ci_14->setText(q_give_info_from_clasS_list.value("ci14").toString());

        ui->lbl_show_classinfo_cp_0->setText(q_give_info_from_clasS_list.value("cp0").toString());
        ui->lbl_show_classinfo_cp_1->setText(q_give_info_from_clasS_list.value("cp1").toString());
        ui->lbl_show_classinfo_cp_2->setText(q_give_info_from_clasS_list.value("cp2").toString());
        ui->lbl_show_classinfo_cp_3->setText(q_give_info_from_clasS_list.value("cp3").toString());
        ui->lbl_show_classinfo_cp_4->setText(q_give_info_from_clasS_list.value("cp4").toString());
        ui->lbl_show_classinfo_cp_5->setText(q_give_info_from_clasS_list.value("cp5").toString());
        ui->lbl_show_classinfo_cp_6->setText(q_give_info_from_clasS_list.value("cp6").toString());
        ui->lbl_show_classinfo_cp_7->setText(q_give_info_from_clasS_list.value("cp7").toString());
        ui->lbl_show_classinfo_cp_8->setText(q_give_info_from_clasS_list.value("cp8").toString());
        ui->lbl_show_classinfo_cp_9->setText(q_give_info_from_clasS_list.value("cp9").toString());
        ui->lbl_show_classinfo_cp_10->setText(q_give_info_from_clasS_list.value("cp10").toString());
        ui->lbl_show_classinfo_cp_11->setText(q_give_info_from_clasS_list.value("cp11").toString());
        ui->lbl_show_classinfo_cp_12->setText(q_give_info_from_clasS_list.value("cp12").toString());
        ui->lbl_show_classinfo_cp_13->setText(q_give_info_from_clasS_list.value("cp13").toString());
        ui->lbl_show_classinfo_cp_14->setText(q_give_info_from_clasS_list.value("cp14").toString());
    }





    ui->tableWidget_list_of_sutdents_for_show_to_class_info->clear();
    ui->listWidget_edit_student_from_this_class->hide();



    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM "+class_id_is_herex+";");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_list_of_sutdents_for_show_to_class_info->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_list_of_sutdents_for_show_to_class_info->setColumnCount(15);
    QSqlQuery q_guve("SELECT * FROM headers;");
    while(q_guve.next())
    {
       ui->tableWidget_list_of_sutdents_for_show_to_class_info->setHorizontalHeaderLabels(QString(ui->lbl_show_classinfo_cp_0->text()+";"+ui->lbl_show_classinfo_cp_1->text()+";"+ui->lbl_show_classinfo_cp_2->text()+";"+ui->lbl_show_classinfo_cp_3->text()+";"+ui->lbl_show_classinfo_cp_4->text()+";"+ui->lbl_show_classinfo_cp_5->text()+";"+ui->lbl_show_classinfo_cp_6->text()+";"+ui->lbl_show_classinfo_cp_7->text()+";"+ui->lbl_show_classinfo_cp_8->text()+";"+ui->lbl_show_classinfo_cp_9->text()+";"+ui->lbl_show_classinfo_cp_10->text()+";"+ui->lbl_show_classinfo_cp_11->text()+";"+ui->lbl_show_classinfo_cp_12->text()+";"+ui->lbl_show_classinfo_cp_13->text()+";"+ui->lbl_show_classinfo_cp_14->text()+";").split(";"));
    }


    //
    ui->tableWidget_list_of_sutdents_for_show_to_class_info->verticalHeader()->hide();

    int sss = 0;

//    QString space_between_student_data = "\t\t";
    QSqlQuery q_give_students_in_this_class("SELECT * FROM "+class_id_is_herex+";");
    while(q_give_students_in_this_class.next())
    {
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 0, new QTableWidgetItem(q_give_students_in_this_class.value("cp0").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 1, new QTableWidgetItem(q_give_students_in_this_class.value("cp1").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 2, new QTableWidgetItem(q_give_students_in_this_class.value("cp2").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 3, new QTableWidgetItem(q_give_students_in_this_class.value("cp3").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 4, new QTableWidgetItem(q_give_students_in_this_class.value("cp4").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 5, new QTableWidgetItem(q_give_students_in_this_class.value("cp5").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 6, new QTableWidgetItem(q_give_students_in_this_class.value("cp6").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 7, new QTableWidgetItem(q_give_students_in_this_class.value("cp7").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 8, new QTableWidgetItem(q_give_students_in_this_class.value("cp8").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 9, new QTableWidgetItem(q_give_students_in_this_class.value("cp9").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 10, new QTableWidgetItem(q_give_students_in_this_class.value("cp10").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 11, new QTableWidgetItem(q_give_students_in_this_class.value("cp11").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 12, new QTableWidgetItem(q_give_students_in_this_class.value("cp12").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 13, new QTableWidgetItem(q_give_students_in_this_class.value("cp13").toString()));
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 14, new QTableWidgetItem(q_give_students_in_this_class.value("cp14").toString()));
        sss++;
    }

//    QSqlQuery q_give_students_from_this_class("SELECT * FROM "+class_id_is_herex+";");
//    QString space_between_student_data = "\t\t";
//    while(q_give_students_from_this_class.next())
//    {
//        QString data_student_will_here_gose_to_package = q_give_students_from_this_class.value("cp0").toString()+  space_between_student_data+
//                q_give_students_from_this_class.value("cp1").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp2").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp3").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp4").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp5").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp6").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp7").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp8").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp9").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp10").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp11").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp12").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp13").toString()+ space_between_student_data+
//                q_give_students_from_this_class.value("cp14").toString();

//        ui->listWidget_list_of_sutdents_for_show_to_class_info->addItem(data_student_will_here_gose_to_package);
//    }
    ui->groupBox_show_class_info->show();
}

void MainWindow::on_student_new_triggered()
{

    ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg




    ui->groupBox_login->hide();
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();



    //txt_register_0
    ui->groupBox_hs_register->setTitle("فرم ثبت نام دانش آموز جدید");
    ui->btn_register_insert->setText("ثبت");
    ui->btn_edit_goto_delete_this_user->hide();
    ui->scrollArea_register->ensureVisible(0,0,0,0);
    ui->groupBox_hs_register->show();
    QSqlQuery q_titles_students("SELECT * FROM studentTitles;");
    while(q_titles_students.next())
    {
        ui->lbl_register_t0->setText(q_titles_students.value("st0").toString());
        ui->lbl_register_t1->setText(q_titles_students.value("st1").toString());
        ui->lbl_register_t2->setText(q_titles_students.value("st2").toString());
        ui->lbl_register_t3->setText(q_titles_students.value("st3").toString());
        ui->lbl_register_t4->setText(q_titles_students.value("st4").toString());
        ui->lbl_register_t5->setText(q_titles_students.value("st5").toString());
        ui->lbl_register_t6->setText(q_titles_students.value("st6").toString());
        ui->lbl_register_t7->setText(q_titles_students.value("st7").toString());
        ui->lbl_register_t8->setText(q_titles_students.value("st8").toString());
        ui->lbl_register_t9->setText(q_titles_students.value("st9").toString());
        ui->lbl_register_t10->setText(q_titles_students.value("st10").toString());
        ui->lbl_register_t11->setText(q_titles_students.value("st11").toString());
        ui->lbl_register_t12->setText(q_titles_students.value("st12").toString());
        ui->lbl_register_t13->setText(q_titles_students.value("st13").toString());
        ui->lbl_register_t14->setText(q_titles_students.value("st14").toString());
        ui->lbl_register_t15->setText(q_titles_students.value("st15").toString());
        ui->lbl_register_t16->setText(q_titles_students.value("st16").toString());
        ui->lbl_register_t17->setText(q_titles_students.value("st17").toString());
        ui->lbl_register_t18->setText(q_titles_students.value("st18").toString());
        ui->lbl_register_t19->setText(q_titles_students.value("st19").toString());
        ui->lbl_register_t20->setText(q_titles_students.value("st20").toString());
        ui->lbl_register_t21->setText(q_titles_students.value("st21").toString());
        ui->lbl_register_t22->setText(q_titles_students.value("st22").toString());
        ui->lbl_register_t23->setText(q_titles_students.value("st23").toString());
        ui->lbl_register_t24->setText(q_titles_students.value("st24").toString());
        ui->lbl_register_t25->setText(q_titles_students.value("st25").toString());
        ui->lbl_register_t26->setText(q_titles_students.value("st26").toString());
        ui->lbl_register_t27->setText(q_titles_students.value("st27").toString());
        ui->lbl_register_t28->setText(q_titles_students.value("st28").toString());
        ui->lbl_register_t29->setText(q_titles_students.value("st29").toString());
    }
    if(avatar_url == "")
    {
        QSqlQuery search_for_url_avatar_defualt("SELECT * FROM adminconfig;");
        while (search_for_url_avatar_defualt.next())
        {
            defualt_avatar = search_for_url_avatar_defualt.value("defualt_avatar").toString();
        }
        QPixmap pm(defualt_avatar); ui->lbl_register_avatar->setPixmap(defualt_avatar);
        ui->lbl_register_avatar->setScaledContents(true);
    }
}

void MainWindow::on_btn_student_register_avatar_clicked()
{
    //    ui->scrollArea_student_register->ensureVisible(0,0,0,0);
    //    if(ui->txt_student_register_0->text() == "" || (ui->txt_student_register_1->text() == "" && ui->txt_student_register_2->text()==""))
    //    {
    //        QMessageBox ::warning(this,"خطا" ," فیلد ها اصلی خالی است‌‌ !!");//یکی از
    //    }
    //    else if(ui->txt_student_register_0->text().size() < 10 || ui->txt_student_register_0->text().size() > 10)
    //    {
    //        QMessageBox ::warning(this,"خطا" ,"‌‌\n"
    //                                          "کدملی باید 10رقم باشد.");

    //    }

    //    else
    //    {
    //        if(QFileInfo("./avatar/"+ui->txt_student_register_0->text()+avatar_format).exists())
    //        {
    //            QMessageBox::information(this," ","عکسی با همین کدملی ثبت شده است و برای این کاربر اضافه خواهد شد!");
    //            image_for_new_student_is_exists = true;
    //        }
    //        else
    //        {
    //            QString url_and_filename_avatar = QFileDialog::getOpenFileName(this,   tr("تصویر مورد نظر را انتخاب کنید"), "/", tr("Image Files (*.jpg)"));
    //            QFile::copy(url_and_filename_avatar, address_avatar_hs_users+ui->txt_student_register_0->text()+avatar_format);
    //            avatar_url = address_avatar_hs_users+ui->txt_student_register_0->text()+avatar_format;
    //            QPixmap pm(avatar_url); ui->lbl_student_register_avatar->setPixmap(avatar_url); ui->lbl_student_register_avatar->setScaledContents(true);
    //        }
    //    }
}

void MainWindow::on_btn_cancel_student_register_clicked()
{
    //    ui->groupBox_student_register->hide();
    //    ui->groupBox_home->show();
}

void MainWindow::on_btn_submit_student_register_clicked()
{
    //    if(ui->groupBox_student_register->title() == "فرم ثبت نام دانش آموز جدید")
    //    {
    //        if(ui->txt_student_register_0->text().size() < 10 || ui->txt_student_register_0->text().size() > 10)
    //        {
    //            QMessageBox::information(this," ","کدملی باید 10 رقم باشد");
    //        }
    //        else
    //        {
    //            QSqlQuery q_save_new_student("INSERT INTO `students` (`p0`,`p1`,`p2`,`p3`,`p4`,`p5`,`p6`,`p7`,`p8`,`p9`,`p10`,`p11`,`p12`,`p13`,`p14`,`p15`,`p16`,`p17`,`p18`,`p19`,`p20`,`p21`,`p22`,`p23`,`p24`,`p25`,`p26`,`p27`,`p28`,`p29`,`p30`) VALUES ('"+ui->txt_student_register_0->text()+"','"+ui->txt_student_register_1->text()+"','"+ui->txt_student_register_2->text()+"','"+ui->txt_student_register_3->text()+"','"+ui->txt_student_register_4->text()+"','"+ui->txt_student_register_5->text()+"','"+ui->txt_student_register_6->text()+"','"+ui->txt_student_register_7->text()+"','"+ui->txt_student_register_8->text()+"','"+ui->txt_student_register_9->text()+"','"+ui->txt_student_register_10->text()+"','"+ui->txt_student_register_11->text()+"','"+ui->txt_student_register_12->text()+"','"+ui->txt_student_register_13->text()+"','"+ui->txt_student_register_14->text()+"','"+ui->txt_student_register_15->text()+"','"+ui->txt_student_register_16->text()+"','"+ui->txt_student_register_17->text()+"','"+ui->txt_student_register_18->text()+"','"+ui->txt_student_register_19->text()+"','"+ui->txt_student_register_20->text()+"','"+ui->txt_student_register_21->text()+"','"+ui->txt_student_register_22->text()+"','"+ui->txt_student_register_23->text()+"','"+ui->txt_student_register_24->text()+"','"+ui->txt_student_register_25->text()+"','"+ui->txt_student_register_26->text()+"','"+ui->txt_student_register_27->text()+"','"+ui->txt_student_register_28->text()+"','"+ui->txt_student_register_29->text()+"','"+avatar_url+"');");
    //            QSqlQuery q_create_tbl_score("CREATE TABLE score_"+ui->txt_student_register_0->text()+" (p0 TEXT);");
    //            QSqlQuery q_alter_table_score("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p1 TEXT;");
    //            QSqlQuery q_alter_table_score1("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p2 TEXT;");
    //            QSqlQuery q_alter_table_score2("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p3 TEXT;");
    //            QSqlQuery q_alter_table_score3("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p4 TEXT;");
    //            QSqlQuery q_alter_table_score4("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p5 TEXT;");
    //            QSqlQuery q_alter_table_score5("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p6 TEXT;");
    //            QSqlQuery q_alter_table_score6("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p7 TEXT;");
    //            QSqlQuery q_alter_table_score7("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p8 TEXT;");
    //            QSqlQuery q_alter_table_score8("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p9 TEXT;");
    //            QSqlQuery q_alter_table_score9("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p10 TEXT;");
    //            QSqlQuery q_alter_table_score10("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p11 TEXT;");
    //            QSqlQuery q_alter_table_score11("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p12 TEXT;");
    //            QSqlQuery q_alter_table_score12("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p13 TEXT;");
    //            QSqlQuery q_alter_table_score13("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p14 TEXT;");
    //            QSqlQuery q_alter_table_score14("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p15 TEXT;");
    //            QSqlQuery q_alter_table_score15("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p16 TEXT;");
    //            QSqlQuery q_alter_table_score16("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p17 TEXT;");
    //            QSqlQuery q_alter_table_score17("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p18 TEXT;");
    //            QSqlQuery q_alter_table_score18("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p19 TEXT;");
    //            QSqlQuery q_alter_table_score19("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p20 TEXT;");
    //            QSqlQuery q_alter_table_score20("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p21 TEXT;");
    //            QSqlQuery q_alter_table_score21("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p22 TEXT;");
    //            QSqlQuery q_alter_table_score22("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p23 TEXT;");
    //            QSqlQuery q_alter_table_score23("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p24 TEXT;");
    //            QSqlQuery q_alter_table_score24("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p25 TEXT;");
    //            QSqlQuery q_alter_table_score25("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p26 TEXT;");
    //            QSqlQuery q_alter_table_score26("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p27 TEXT;");
    //            QSqlQuery q_alter_table_score27("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p28 TEXT;");
    //            QSqlQuery q_alter_table_score28("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p29 TEXT;");
    //            QSqlQuery q_alter_table_score29("ALTER TABLE score_"+ui->txt_student_register_0->text()+" ADD p30 TEXT;");



    //            QMessageBox::information(this," ","دانش آموز با موفیقت ساخته شد");
    //            ui->groupBox_student_register->hide();
    //            ui->groupBox_home->show();
    //        }
    //    }
    //    else
    //    {
    //        QSqlQuery q_update_data_to_student("UPDATE `students` SET p0='"+ui->txt_student_register_0->text()+"',p1='"+ui->txt_student_register_1->text()+"',p2='"+ui->txt_student_register_2->text()+"',p3='"+ui->txt_student_register_3->text()+"',p4='"+ui->txt_student_register_4->text()+"',p5='"+ui->txt_student_register_5->text()+"',p6='"+ui->txt_student_register_6->text()+"',p7='"+ui->txt_student_register_7->text()+"',p8='"+ui->txt_student_register_8->text()+"',p9='"+ui->txt_student_register_9->text()+"',p10='"+ui->txt_student_register_10->text()+"',p11='"+ui->txt_student_register_11->text()+"',p12='"+ui->txt_student_register_12->text()+"',p13='"+ui->txt_student_register_13->text()+"',p14='"+ui->txt_student_register_14->text()+"',p15='"+ui->txt_student_register_15->text()+"',p16='"+ui->txt_student_register_16->text()+"',p17='"+ui->txt_student_register_17->text()+"',p18='"+ui->txt_student_register_18->text()+"',p19='"+ui->txt_student_register_19->text()+"',p20='"+ui->txt_student_register_20->text()+"',p21='"+ui->txt_student_register_21->text()+"',p22='"+ui->txt_student_register_22->text()+"',p23='"+ui->txt_student_register_23->text()+"',p24='"+ui->txt_student_register_24->text()+"',p25='"+ui->txt_student_register_25->text()+"',p26='"+ui->txt_student_register_26->text()+"',p27='"+ui->txt_student_register_27->text()+"',p28='"+ui->txt_student_register_28->text()+"',p29='"+ui->txt_student_register_29->text()+"',p30='"+avatar_url+"';");
    //        ui->groupBox_student_register->hide();
    //        ui->groupBox_home->show();
    //    }
}

void MainWindow::on_btn_cancel_from_stu_list_clicked()
{
    //    ui->groupBox_show_students_list->hide();
    //    ui->groupBox_home->show();
}

void MainWindow::on_btn_show_this_student_from_stu_list_clicked()
{
    //    ui->groupBox_show_students_list->hide();
    //    QString thisis_stu_code = ui->listWidget_show_student_list->currentItem()->text();

    //    QStringRef ref_code_student = thisis_stu_code.leftRef(10);
    //    thisis_stu_code = ref_code_student.toString();
    //    //load tab TITLES !
    //    QSqlQuery q_give_student_titles("SELECT * FROM studenTitles;");
    //    while(q_give_student_titles.next())
    //    {
    //        ui->lbl_student_info_t_0->setText(q_give_student_titles.value("st0").toString());
    //        ui->lbl_student_info_t_1->setText(q_give_student_titles.value("st1").toString());
    //        ui->lbl_student_info_t_2->setText(q_give_student_titles.value("st2").toString());
    //        ui->lbl_student_info_t_3->setText(q_give_student_titles.value("st3").toString());
    //        ui->lbl_student_info_t_4->setText(q_give_student_titles.value("st4").toString());
    //        ui->lbl_student_info_t_5->setText(q_give_student_titles.value("st5").toString());
    //        ui->lbl_student_info_t_6->setText(q_give_student_titles.value("st6").toString());
    //        ui->lbl_student_info_t_7->setText(q_give_student_titles.value("st7").toString());
    //        ui->lbl_student_info_t_8->setText(q_give_student_titles.value("st8").toString());
    //        ui->lbl_student_info_t_9->setText(q_give_student_titles.value("st9").toString());
    //        ui->lbl_student_info_t_10->setText(q_give_student_titles.value("st10").toString());
    //        ui->lbl_student_info_t_11->setText(q_give_student_titles.value("st11").toString());
    //        ui->lbl_student_info_t_12->setText(q_give_student_titles.value("st12").toString());
    //        ui->lbl_student_info_t_13->setText(q_give_student_titles.value("st13").toString());
    //        ui->lbl_student_info_t_14->setText(q_give_student_titles.value("st14").toString());
    //        ui->lbl_student_info_t_15->setText(q_give_student_titles.value("st15").toString());
    //        ui->lbl_student_info_t_16->setText(q_give_student_titles.value("st16").toString());
    //        ui->lbl_student_info_t_17->setText(q_give_student_titles.value("st17").toString());
    //        ui->lbl_student_info_t_18->setText(q_give_student_titles.value("st18").toString());
    //        ui->lbl_student_info_t_19->setText(q_give_student_titles.value("st19").toString());
    //        ui->lbl_student_info_t_20->setText(q_give_student_titles.value("st20").toString());
    //        ui->lbl_student_info_t_21->setText(q_give_student_titles.value("st21").toString());
    //        ui->lbl_student_info_t_22->setText(q_give_student_titles.value("st22").toString());
    //        ui->lbl_student_info_t_23->setText(q_give_student_titles.value("st23").toString());
    //        ui->lbl_student_info_t_24->setText(q_give_student_titles.value("st24").toString());
    //        ui->lbl_student_info_t_25->setText(q_give_student_titles.value("st25").toString());
    //        ui->lbl_student_info_t_26->setText(q_give_student_titles.value("st26").toString());
    //        ui->lbl_student_info_t_27->setText(q_give_student_titles.value("st27").toString());
    //        ui->lbl_student_info_t_28->setText(q_give_student_titles.value("st28").toString());
    //        ui->lbl_student_info_t_29->setText(q_give_student_titles.value("st29").toString());
    //    }
    //    QSqlQuery q_give_student_info("SELECT * FROM students;");
    //    while(q_give_student_info.next())
    //    {
    //        ui->lbl_student_info_p_0->setText(q_give_student_info.value("p0").toString());
    //        ui->lbl_student_info_p_1->setText(q_give_student_info.value("p1").toString());
    //        ui->lbl_student_info_p_2->setText(q_give_student_info.value("p2").toString());
    //        ui->lbl_student_info_p_3->setText(q_give_student_info.value("p3").toString());
    //        ui->lbl_student_info_p_4->setText(q_give_student_info.value("p4").toString());
    //        ui->lbl_student_info_p_5->setText(q_give_student_info.value("p5").toString());
    //        ui->lbl_student_info_p_6->setText(q_give_student_info.value("p6").toString());
    //        ui->lbl_student_info_p_7->setText(q_give_student_info.value("p7").toString());
    //        ui->lbl_student_info_p_8->setText(q_give_student_info.value("p8").toString());
    //        ui->lbl_student_info_p_9->setText(q_give_student_info.value("p9").toString());
    //        ui->lbl_student_info_p_10->setText(q_give_student_info.value("p10").toString());
    //        ui->lbl_student_info_p_11->setText(q_give_student_info.value("p11").toString());
    //        ui->lbl_student_info_p_12->setText(q_give_student_info.value("p12").toString());
    //        ui->lbl_student_info_p_13->setText(q_give_student_info.value("p13").toString());
    //        ui->lbl_student_info_p_14->setText(q_give_student_info.value("p14").toString());
    //        ui->lbl_student_info_p_15->setText(q_give_student_info.value("p15").toString());
    //        ui->lbl_student_info_p_16->setText(q_give_student_info.value("p16").toString());
    //        ui->lbl_student_info_p_17->setText(q_give_student_info.value("p17").toString());
    //        ui->lbl_student_info_p_18->setText(q_give_student_info.value("p18").toString());
    //        ui->lbl_student_info_p_19->setText(q_give_student_info.value("p19").toString());
    //        ui->lbl_student_info_p_20->setText(q_give_student_info.value("p20").toString());
    //        ui->lbl_student_info_p_21->setText(q_give_student_info.value("p21").toString());
    //        ui->lbl_student_info_p_22->setText(q_give_student_info.value("p22").toString());
    //        ui->lbl_student_info_p_23->setText(q_give_student_info.value("p23").toString());
    //        ui->lbl_student_info_p_24->setText(q_give_student_info.value("p24").toString());
    //        ui->lbl_student_info_p_25->setText(q_give_student_info.value("p25").toString());
    //        ui->lbl_student_info_p_26->setText(q_give_student_info.value("p26").toString());
    //        ui->lbl_student_info_p_27->setText(q_give_student_info.value("p27").toString());
    //        ui->lbl_student_info_p_28->setText(q_give_student_info.value("p28").toString());
    //        ui->lbl_student_info_p_29->setText(q_give_student_info.value("p29").toString());
    //        avatar_url = q_give_student_info.value("p30").toString();
    //        QPixmap avatar_from_edit(avatar_url); ui->lbl_student_info_avatar->setPixmap(avatar_url); ui->lbl_student_info_avatar->setScaledContents(true);
    //    }
    //    //set ScrollArea score -> 0,0,0,0;
    //    //SELECt score from score_codestu and insert to a HL > label > setText Label..
}

void MainWindow::on_student_list_triggered()
{
    //titleX set Text
    ui->groupBox_show_users_hs->show();
    ui->groupBox_show_users_hs->setTitle("لیست دانش آموزان");
    ui->listWidget_show_users_hs->clear();




    ui->scrollArea_register->ensureVisible(0,0,0,0);

    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();




    //remove all values from userinformation
    ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
    ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
    ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
    ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
    ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
    ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
    ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
    ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
    ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
    ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
    ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
    ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
    ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
    ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
    ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
    ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
    ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
    ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
    ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
    ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
    ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
    ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
    ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
    ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
    ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
    ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
    ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
    ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
    ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
    ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
    ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();

    ui->listWidget_show_users_hs->hide();
    ui->titleX->hide();
    ui->tableWidget_show_users_hs->clear();
    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM students;");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_show_users_hs->setColumnCount(4);
    QSqlQuery q_give_titles("SELECT * FROM studentTitles;");
    QString t0,t1,t2,t3;
    while(q_give_titles.next())
    {
        t0 = q_give_titles.value("st0").toString();
        t1 = q_give_titles.value("st1").toString();
        t2 = q_give_titles.value("st2").toString();
        t3 = q_give_titles.value("st3").toString();
    }
    ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
    ui->tableWidget_show_users_hs->verticalHeader()->hide();
    QSqlQuery search("SELECT * FROM students;");
    QString p0,p1,p2,p3;
    int sss = 0;
    while (search.next())
    {
        p0 = search.value("p0").toString();
        p1 = search.value("p1").toString();
        p2 = search.value("p2").toString();
        p3 = search.value("p3").toString();
        ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
        ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
        ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
        ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
        sss++;
    }
    ui->groupBox_show_users_hs->show();
}

void MainWindow::on_btn_student_info_edit_stu_clicked()
{
    //    ui->groupBox_student_information->hide();
    //    QString stu_id = ui->lbl_student_info_p_0->text();
    //    ui->groupBox_student_register->show();
    //    ui->groupBox_student_register->setTitle("فرم ویرایش دانش اموز");
    //    ui->btn_submit_student_register->setText("ویرایش");

    //    ui->btn_edit_goto_delete_this_student->show();
    //    ui->scrollArea_student_register->ensureVisible(0,0,0,0);
    //    QSqlQuery q_titles_students("SELECT * FROM studentTitles;");
    //    while(q_titles_students.next())
    //    {
    //        ui->txt_student_register_0->setText(q_titles_students.value("p0").toString());
    //        ui->txt_student_register_1->setText(q_titles_students.value("p1").toString());
    //        ui->txt_student_register_2->setText(q_titles_students.value("p2").toString());
    //        ui->txt_student_register_3->setText(q_titles_students.value("p3").toString());
    //        ui->txt_student_register_4->setText(q_titles_students.value("p4").toString());
    //        ui->txt_student_register_5->setText(q_titles_students.value("p5").toString());
    //        ui->txt_student_register_6->setText(q_titles_students.value("p6").toString());
    //        ui->txt_student_register_7->setText(q_titles_students.value("p7").toString());
    //        ui->txt_student_register_8->setText(q_titles_students.value("p8").toString());
    //        ui->txt_student_register_9->setText(q_titles_students.value("p9").toString());
    //        ui->txt_student_register_10->setText(q_titles_students.value("p10").toString());
    //        ui->txt_student_register_11->setText(q_titles_students.value("p11").toString());
    //        ui->txt_student_register_12->setText(q_titles_students.value("p12").toString());
    //        ui->txt_student_register_13->setText(q_titles_students.value("p13").toString());
    //        ui->txt_student_register_14->setText(q_titles_students.value("p14").toString());
    //        ui->txt_student_register_15->setText(q_titles_students.value("p15").toString());
    //        ui->txt_student_register_16->setText(q_titles_students.value("p16").toString());
    //        ui->txt_student_register_17->setText(q_titles_students.value("p17").toString());
    //        ui->txt_student_register_18->setText(q_titles_students.value("p18").toString());
    //        ui->txt_student_register_19->setText(q_titles_students.value("p19").toString());
    //        ui->txt_student_register_20->setText(q_titles_students.value("p20").toString());
    //        ui->txt_student_register_21->setText(q_titles_students.value("p21").toString());
    //        ui->txt_student_register_22->setText(q_titles_students.value("p22").toString());
    //        ui->txt_student_register_23->setText(q_titles_students.value("p23").toString());
    //        ui->txt_student_register_24->setText(q_titles_students.value("p24").toString());
    //        ui->txt_student_register_25->setText(q_titles_students.value("p25").toString());
    //        ui->txt_student_register_26->setText(q_titles_students.value("p26").toString());
    //        ui->txt_student_register_27->setText(q_titles_students.value("p27").toString());
    //        ui->txt_student_register_28->setText(q_titles_students.value("p28").toString());
    //        ui->txt_student_register_29->setText(q_titles_students.value("p29").toString());

    //        avatar_url = q_titles_students.value("p30").toString();
    //        QPixmap avatar_from_edit(avatar_url);   ui->lbl_student_register_avatar->setPixmap(avatar_url); ui->lbl_student_register_avatar->setScaledContents(true);
    //        if(avatar_url == "")
    //        {
    //            QSqlQuery search_for_url_avatar_defualt("SELECT * FROM adminconfig;");
    //            while (search_for_url_avatar_defualt.next())
    //            {
    //                defualt_avatar = search_for_url_avatar_defualt.value("defualt_avatar").toString();
    //            }
    //            QPixmap pm(defualt_avatar); ui->lbl_student_register_avatar->setPixmap(defualt_avatar);
    //            ui->lbl_student_register_avatar->setScaledContents(true);
    //        }

    //    }



    //    QSqlQuery q_info_student("SELECT * FROM studentTitles;");
    //    while(q_info_student.next())
    //    {
    //        ui->lbl_student_register_t_0->setText(q_info_student.value("st0").toString());
    //        ui->lbl_student_register_t_1->setText(q_info_student.value("st1").toString());
    //        ui->lbl_student_register_t_2->setText(q_info_student.value("st2").toString());
    //        ui->lbl_student_register_t_3->setText(q_info_student.value("st3").toString());
    //        ui->lbl_student_register_t_4->setText(q_info_student.value("st4").toString());
    //        ui->lbl_student_register_t_5->setText(q_info_student.value("st5").toString());
    //        ui->lbl_student_register_t_6->setText(q_info_student.value("st6").toString());
    //        ui->lbl_student_register_t_7->setText(q_info_student.value("st7").toString());
    //        ui->lbl_student_register_t_8->setText(q_info_student.value("st8").toString());
    //        ui->lbl_student_register_t_9->setText(q_info_student.value("st9").toString());
    //        ui->lbl_student_register_t_10->setText(q_info_student.value("st10").toString());
    //        ui->lbl_student_register_t_11->setText(q_info_student.value("st11").toString());
    //        ui->lbl_student_register_t_12->setText(q_info_student.value("st12").toString());
    //        ui->lbl_student_register_t_13->setText(q_info_student.value("st13").toString());
    //        ui->lbl_student_register_t_14->setText(q_info_student.value("st14").toString());
    //        ui->lbl_student_register_t_15->setText(q_info_student.value("st15").toString());
    //        ui->lbl_student_register_t_16->setText(q_info_student.value("st16").toString());
    //        ui->lbl_student_register_t_17->setText(q_info_student.value("st17").toString());
    //        ui->lbl_student_register_t_18->setText(q_info_student.value("st18").toString());
    //        ui->lbl_student_register_t_19->setText(q_info_student.value("st19").toString());
    //        ui->lbl_student_register_t_20->setText(q_info_student.value("st20").toString());
    //        ui->lbl_student_register_t_21->setText(q_info_student.value("st21").toString());
    //        ui->lbl_student_register_t_22->setText(q_info_student.value("st22").toString());
    //        ui->lbl_student_register_t_23->setText(q_info_student.value("st23").toString());
    //        ui->lbl_student_register_t_24->setText(q_info_student.value("st24").toString());
    //        ui->lbl_student_register_t_25->setText(q_info_student.value("st25").toString());
    //        ui->lbl_student_register_t_26->setText(q_info_student.value("st26").toString());
    //        ui->lbl_student_register_t_27->setText(q_info_student.value("st27").toString());
    //        ui->lbl_student_register_t_28->setText(q_info_student.value("st28").toString());
    //        ui->lbl_student_register_t_29->setText(q_info_student.value("st29").toString());
    //    }
}

void MainWindow::on_btn_return_2_student_list_from_stu_info_clicked()
{
    //    //hide *
    //    ui->groupBox_show_students_list->show();
    //    //load title
    //    ui->listWidget_show_student_list->clear();
    //    QString space_between = "\t\t";
    //    QSqlQuery q_give_students("SELECT * FROM students;");
    //    while(q_give_students.next())
    //    {
    //        QString g_package  = q_give_students.value("p0").toString() +space_between +
    //                q_give_students.value("p1").toString() +space_between +
    //                q_give_students.value("p2").toString() +space_between +
    //                q_give_students.value("p3").toString() +space_between +
    //                q_give_students.value("p4").toString() +space_between +
    //                q_give_students.value("p5").toString();
    //        //                q_give_students.value("p6").toString() +space_between +
    //        //                q_give_students.value("p7").toString() +space_between +
    //        //                q_give_students.value("p8").toString() +space_between +
    //        //                q_give_students.value("p9").toString() +space_between +
    //        //                q_give_students.value("p10").toString() +space_between +
    //        //                q_give_students.value("p11").toString() +space_between +
    //        //                q_give_students.value("p12").toString() +space_between +
    //        //                q_give_students.value("p13").toString() +space_between +
    //        //                q_give_students.value("p14").toString() +space_between;//or can add more..
    //        ui->listWidget_show_student_list->addItem(g_package);
    //    }
}

void MainWindow::on_btn_edit_goto_delete_this_student_clicked()
{

}

void MainWindow::on_btn_cancel_and_return_to_home_clicked()
{
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_btn_add_student_to_class_by_student_list_clicked()
{
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->btn_show_users_hs->setText("افزودن");
    want_to_select_student_from_list_for_add_to_a_class = true;


    //titleX set Text
    ui->groupBox_show_users_hs->show();
    ui->groupBox_show_users_hs->setTitle("لیست دانش آموزان");
    ui->listWidget_show_users_hs->clear();




    ui->scrollArea_register->ensureVisible(0,0,0,0);

    ui->groupBox_login->hide(); //show this
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    /*ui->groupBox_show_users_hs->hide();*/ ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    //other
    ui->groupBox_change_window_title->hide();
    ui->groupBox_change_userpass_admin->hide(); ui->groupBox_maxtry_change->hide();
    ui->groupBox_avatar_path_change->hide(); ui->groupBox_currenttry_change->hide();
    ui->groupBox_send_cmd_to_db->hide(); ui->groupBox_history_of_admin_logins_log->hide();
    ui->groupBox_db_backup_config->hide();
    ui->groupBox_resetfactory_tables->hide();





    //remove all values from userinformation
    ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
    ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
    ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
    ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
    ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
    ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
    ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
    ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
    ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
    ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
    ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
    ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
    ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
    ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
    ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
    ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
    ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
    ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
    ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
    ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
    ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
    ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
    ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
    ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
    ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
    ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
    ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
    ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
    ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
    ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
    ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();


    ui->listWidget_show_users_hs->hide();
    ui->titleX->hide();
    ui->tableWidget_show_users_hs->clear();
    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM students;");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_show_users_hs->setColumnCount(4);
    QSqlQuery q_give_titles("SELECT * FROM studentTitles;");
    QString t0,t1,t2,t3;
    while(q_give_titles.next())
    {
        t0 = q_give_titles.value("st0").toString();
        t1 = q_give_titles.value("st1").toString();
        t2 = q_give_titles.value("st2").toString();
        t3 = q_give_titles.value("st3").toString();
    }
    ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
    ui->tableWidget_show_users_hs->verticalHeader()->hide();
    ui->tableWidget_show_users_hs->setStyleSheet("color:black;");
    QSqlQuery search("SELECT * FROM students;");
    QString p0,p1,p2,p3;
    int sss = 0;
    while (search.next())
    {
        p0 = search.value("p0").toString();
        p1 = search.value("p1").toString();
        p2 = search.value("p2").toString();
        p3 = search.value("p3").toString();
        ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
        ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
        ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
        ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
        sss++;
    }
    ui->groupBox_show_users_hs->show();
}

void MainWindow::on_btn_save_data_to_this_student_on_this_class_clicked()
{
    if(ui->groupBox_insert_more_data_to_student_for_this_class->title() == "ثبت اطلاعات دانش آموز در کلاس ")
    {
        ui->groupBox_insert_more_data_to_student_for_this_class->hide();
        QSqlQuery q_update_student_data_to_this_class("UPDATE "+class_id_is_herex+" SET cp0='"+ui->txt_stu_data_to_this_class_0->text()+"',cp1='"+ui->txt_stu_data_to_this_class_1->text()+"',cp2='"+ui->txt_stu_data_to_this_class_2->text()+"',cp3='"+ui->txt_stu_data_to_this_class_3->text()+"',cp4='"+ui->txt_stu_data_to_this_class_4->text()+"',cp5='"+ui->txt_stu_data_to_this_class_5->text()+"',cp6='"+ui->txt_stu_data_to_this_class_6->text()+"',cp7='"+ui->txt_stu_data_to_this_class_7->text()+"',cp8='"+ui->txt_stu_data_to_this_class_8->text()+"',cp9='"+ui->txt_stu_data_to_this_class_9->text()+"',cp10='"+ui->txt_stu_data_to_this_class_10->text()+"',cp11='"+ui->txt_stu_data_to_this_class_11->text()+"',cp12='"+ui->txt_stu_data_to_this_class_12->text()+"',cp13='"+ui->txt_stu_data_to_this_class_13->text()+"',cp14='"+ui->txt_stu_data_to_this_class_14->text()+"' WHERE cp0='"+ui->txt_stu_data_to_this_class_0->text()+"';");
        QSqlQuery q_add_class_info_to_score_student("INSERT INTO score_"+ui->txt_stu_data_to_this_class_0->text()+" (p0) VALUES ('"+class_id_is_herex+"');");


        QSqlQuery q_search_class_information("SELECT * FROM class_list WHERE cid='"+class_id_is_herex+"';");
        QString tempe0,tempe1,tempe2,tempe3,tempe4,tempe5,tempe6,tempe7,tempe8,tempe9;
        while(q_search_class_information.next())
        {
            tempe0 = q_search_class_information.value("ci0").toString();
            tempe1 = q_search_class_information.value("ci1").toString();
            tempe2 = q_search_class_information.value("ci2").toString();
            tempe3 = q_search_class_information.value("ci3").toString();
            tempe4 = q_search_class_information.value("ci4").toString();
            tempe5 = q_search_class_information.value("ci5").toString();
            tempe6 = q_search_class_information.value("ci6").toString();
            tempe7 = q_search_class_information.value("ci7").toString();
            tempe8 = q_search_class_information.value("ci8").toString();
            tempe9 = q_search_class_information.value("ci9").toString();
        }
        //        QMessageBox::information(this,"tempe0-9", ""+tempe0+"\n"+tempe1+"\n"+tempe2+"\n"+tempe3+"\n"+tempe4+"\n"+tempe5+"\n"+tempe6+"\n"+tempe7+"\n"+tempe8+"\n"+tempe9);
        QString temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9;
        QSqlQuery q_give_student_score("SELECT * FROM "+class_id_is_herex+" WHERE cp0='"+ui->txt_stu_data_to_this_class_0->text()+"';");
        while(q_give_student_score.next())
        {
            temp0 = q_give_student_score.value("cp0").toString();
            temp1 = q_give_student_score.value("cp1").toString();
            temp2 = q_give_student_score.value("cp2").toString();
            temp3 = q_give_student_score.value("cp3").toString();
            temp4 = q_give_student_score.value("cp4").toString();
            temp5 = q_give_student_score.value("cp5").toString();
            temp6 = q_give_student_score.value("cp6").toString();
            temp7 = q_give_student_score.value("cp7").toString();
            temp8 = q_give_student_score.value("cp8").toString();
            temp9 = q_give_student_score.value("cp9").toString();
        }
        //        QSqlQuery q_add_class_info_to_score_student("INSERT INTO score_"+ui->txt_stu_data_to_this_class_0->text()+" (p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,17,p18,p19) VALUES ('cid_"+class_id_is_herex+"','"+tempe1+"','"+tempe2+"','"+tempe3+"','"+tempe4+"','"+tempe5+"','"+tempe6+"','"+tempe7+"','"+tempe8+"','"+tempe9+"','"+temp0+"','"+temp1+"','"+temp2+"','"+temp3+"','"+temp4+"','"+temp5+"','"+temp6+"','"+temp7+"','"+temp8+"','"+temp9+"');");
        //QSqlQuery q_update_sutdent("UPDATE score_"+ui->txt_stu_data_to_this_class_0->text()+" SET p1='"+tempe1+"', p2='"+tempe2+"', p3='"+tempe3+"', p4='"+tempe4+"', p5='"+tempe5+"', p6='"+tempe6+"', p7='"+tempe7+"', p8='"+tempe8+"', p9='"+tempe9+"', p10='"+temp0+"', p11='"+temp1+"', p12='"+temp2+"', p13='"+temp3+"', p14='"+temp4+"', p15='"+temp5+"', p16='"+temp6+"', p17='"+temp7+"', p18='"+temp8+"', p19='"+temp9+"', WHERE p0='cid_"+class_id_is_herex+"';");
        QString testx = "score_"+ui->txt_stu_data_to_this_class_0->text();
        QSqlQuery q_update_data_student_to_score("UPDATE "+testx+" SET p1='"+tempe0+"', p2='"+tempe1+"', p3='"+tempe2+"', p4='"+tempe3+"', p5='"+tempe4+"', p6='"+tempe5+"', p7='"+tempe6+"', p8='"+tempe7+"', p9='"+tempe8+"', p10='"+tempe9+"', p11='"+temp0+"', p12='"+temp1+"', p13='"+temp2+"', p14='"+temp3+"', p15='"+temp4+"', p16='"+temp5+"', p17='"+temp6+"', p18='"+temp7+"', p19='"+temp8+"', p20='"+temp9+"' WHERE p0='"+class_id_is_herex+"';");
        QMessageBox::information(this," ","دانش آموز با موارد داده شده در کلاس ثبت شد");
        ui->groupBox_insert_more_data_to_student_for_this_class->hide();
        ui->groupBox_home->show();
        class_id_is_herex = "";
    }

}

void MainWindow::on_btn_cancel_and_return_to_home_2_clicked()
{
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_class_search_triggered()
{
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_result_search_class->hide();

    ui->groupBox_search_on_class->show();
    QSqlQuery q_give_ci_texts_for_insert_to_check_boxs("SELECT * FROM t_class_info;");
    while(q_give_ci_texts_for_insert_to_check_boxs.next())
    {
        ui->cbox_search_class_ci_0->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cid").toString());
        ui->cbox_search_class_ci_1->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo0").toString());
        ui->cbox_search_class_ci_2->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo1").toString());
        ui->cbox_search_class_ci_3->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo2").toString());
        ui->cbox_search_class_ci_4->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo3").toString());
        ui->cbox_search_class_ci_5->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo4").toString());
        ui->cbox_search_class_ci_6->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo5").toString());
        ui->cbox_search_class_ci_7->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo6").toString());
        ui->cbox_search_class_ci_8->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo7").toString());
        ui->cbox_search_class_ci_9->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo8").toString());
        ui->cbox_search_class_ci_10->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo9").toString());
        ui->cbox_search_class_ci_11->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo10").toString());
        ui->cbox_search_class_ci_12->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo11").toString());
        ui->cbox_search_class_ci_13->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo12").toString());
        ui->cbox_search_class_ci_14->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo13").toString());
        //ui->cbox_search_class_ci_15->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo14").toString());

    }
    ui->cbox_search_class_select_all->setText("همه فعال");
    bool status_of_search_rbtn_select_all = true;
    ui->cbox_search_class_select_all->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_0->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_1->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_2->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_3->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_4->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_5->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_6->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_7->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_8->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_9->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_10->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_11->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_12->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_13->setDisabled(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_14->setChecked(status_of_search_rbtn_select_all);
//    ui->cbox_search_class_ci_15->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_15->hide();
}

void MainWindow::on_student_search_triggered()
{
    im_from_students_list = true;
    ui->groupBox_search_hs_users->setTitle("جستجو دانش آموزان");
    bool the_status_for_set_check_all=false;
    ui->cbox_select_all->setText("همه فعال");
    ui->rbutton_search_likes_from_hs_users_yes->setChecked(the_status_for_set_check_all);
    ui->rbutton_search_likes_from_hs_users_no->setChecked(the_status_for_set_check_all);
    ui->cbox_select_all->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t1->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t0->setChecked(the_status_for_set_check_all);   ui->cbox_select_t16->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t2->setChecked(the_status_for_set_check_all);   ui->cbox_select_t17->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t3->setChecked(the_status_for_set_check_all);   ui->cbox_select_t18->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t4->setChecked(the_status_for_set_check_all);   ui->cbox_select_t19->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t5->setChecked(the_status_for_set_check_all);   ui->cbox_select_t20->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t6->setChecked(the_status_for_set_check_all);   ui->cbox_select_t21->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t7->setChecked(the_status_for_set_check_all);   ui->cbox_select_t22->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t8->setChecked(the_status_for_set_check_all);   ui->cbox_select_t23->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t9->setChecked(the_status_for_set_check_all);   ui->cbox_select_t24->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t10->setChecked(the_status_for_set_check_all);   ui->cbox_select_t25->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t11->setChecked(the_status_for_set_check_all);   ui->cbox_select_t26->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t12->setChecked(the_status_for_set_check_all);   ui->cbox_select_t27->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t13->setChecked(the_status_for_set_check_all);   ui->cbox_select_t28->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t14->setChecked(the_status_for_set_check_all);   ui->cbox_select_t29->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t15->setChecked(the_status_for_set_check_all);


    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();


    ui->txt_text_search_for_hs_users->clear();



    ui->scrollArea_checkboxs_select_part_search_from_hs_users->ensureVisible(0,0,0,0);
    ui->groupBox_search_hs_users->show();
    QSqlQuery q_give_titles_from_hs_titles("SELECT * FROM studentTitles;");
    while(q_give_titles_from_hs_titles.next())
    {
        ui->cbox_select_t0->setText(q_give_titles_from_hs_titles.value("st0").toString());
        ui->cbox_select_t1->setText(q_give_titles_from_hs_titles.value("st1").toString());
        ui->cbox_select_t2->setText(q_give_titles_from_hs_titles.value("st2").toString());
        ui->cbox_select_t3->setText(q_give_titles_from_hs_titles.value("st3").toString());
        ui->cbox_select_t4->setText(q_give_titles_from_hs_titles.value("st4").toString());
        ui->cbox_select_t5->setText(q_give_titles_from_hs_titles.value("st5").toString());
        ui->cbox_select_t6->setText(q_give_titles_from_hs_titles.value("st6").toString());
        ui->cbox_select_t7->setText(q_give_titles_from_hs_titles.value("st7").toString());
        ui->cbox_select_t8->setText(q_give_titles_from_hs_titles.value("st8").toString());
        ui->cbox_select_t9->setText(q_give_titles_from_hs_titles.value("st9").toString());
        ui->cbox_select_t10->setText(q_give_titles_from_hs_titles.value("st10").toString());
        ui->cbox_select_t11->setText(q_give_titles_from_hs_titles.value("st11").toString());
        ui->cbox_select_t12->setText(q_give_titles_from_hs_titles.value("st12").toString());
        ui->cbox_select_t13->setText(q_give_titles_from_hs_titles.value("st13").toString());
        ui->cbox_select_t14->setText(q_give_titles_from_hs_titles.value("st14").toString());
        ui->cbox_select_t15->setText(q_give_titles_from_hs_titles.value("st15").toString());
        ui->cbox_select_t16->setText(q_give_titles_from_hs_titles.value("st16").toString());
        ui->cbox_select_t17->setText(q_give_titles_from_hs_titles.value("st17").toString());
        ui->cbox_select_t18->setText(q_give_titles_from_hs_titles.value("st18").toString());
        ui->cbox_select_t19->setText(q_give_titles_from_hs_titles.value("st19").toString());
        ui->cbox_select_t20->setText(q_give_titles_from_hs_titles.value("st20").toString());
        ui->cbox_select_t21->setText(q_give_titles_from_hs_titles.value("st21").toString());
        ui->cbox_select_t22->setText(q_give_titles_from_hs_titles.value("st22").toString());
        ui->cbox_select_t23->setText(q_give_titles_from_hs_titles.value("st23").toString());
        ui->cbox_select_t24->setText(q_give_titles_from_hs_titles.value("st24").toString());
        ui->cbox_select_t25->setText(q_give_titles_from_hs_titles.value("st25").toString());
        ui->cbox_select_t26->setText(q_give_titles_from_hs_titles.value("st26").toString());
        ui->cbox_select_t27->setText(q_give_titles_from_hs_titles.value("st27").toString());
        ui->cbox_select_t28->setText(q_give_titles_from_hs_titles.value("st28").toString());
        ui->cbox_select_t29->setText(q_give_titles_from_hs_titles.value("st29").toString());
    }
}

void MainWindow::on_btn_add_more_students_to_this_classs_clicked()
{
    ui->groupBox_show_class_info->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->show();
    want_to_select_student_from_list_for_add_to_a_class = true;
}

void MainWindow::on_btn_add_student_to_class_by_searching_clicked()
{
    ui->groupBox_show_class_info->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();

    ui->btn_goto_this_user_from_search_result->setText("افزودن");
    im_want_to_select_student_from_list_students_for_add_to_class=true;

    im_from_students_list = true;
    ui->groupBox_search_hs_users->setTitle("جستجو دانش آموزان");
    bool the_status_for_set_check_all=false;
    ui->cbox_select_all->setText("همه فعال");
    ui->rbutton_search_likes_from_hs_users_yes->setChecked(the_status_for_set_check_all);
    ui->rbutton_search_likes_from_hs_users_no->setChecked(the_status_for_set_check_all);
    ui->cbox_select_all->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t1->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t0->setChecked(the_status_for_set_check_all);   ui->cbox_select_t16->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t2->setChecked(the_status_for_set_check_all);   ui->cbox_select_t17->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t3->setChecked(the_status_for_set_check_all);   ui->cbox_select_t18->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t4->setChecked(the_status_for_set_check_all);   ui->cbox_select_t19->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t5->setChecked(the_status_for_set_check_all);   ui->cbox_select_t20->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t6->setChecked(the_status_for_set_check_all);   ui->cbox_select_t21->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t7->setChecked(the_status_for_set_check_all);   ui->cbox_select_t22->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t8->setChecked(the_status_for_set_check_all);   ui->cbox_select_t23->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t9->setChecked(the_status_for_set_check_all);   ui->cbox_select_t24->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t10->setChecked(the_status_for_set_check_all);   ui->cbox_select_t25->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t11->setChecked(the_status_for_set_check_all);   ui->cbox_select_t26->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t12->setChecked(the_status_for_set_check_all);   ui->cbox_select_t27->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t13->setChecked(the_status_for_set_check_all);   ui->cbox_select_t28->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t14->setChecked(the_status_for_set_check_all);   ui->cbox_select_t29->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t15->setChecked(the_status_for_set_check_all);



    ui->txt_text_search_for_hs_users->clear();



    ui->scrollArea_checkboxs_select_part_search_from_hs_users->ensureVisible(0,0,0,0);
    ui->groupBox_search_hs_users->show();
    QSqlQuery q_give_titles_from_hs_titles("SELECT * FROM studentTitles;");
    while(q_give_titles_from_hs_titles.next())
    {
        ui->cbox_select_t0->setText(q_give_titles_from_hs_titles.value("st0").toString());
        ui->cbox_select_t1->setText(q_give_titles_from_hs_titles.value("st1").toString());
        ui->cbox_select_t2->setText(q_give_titles_from_hs_titles.value("st2").toString());
        ui->cbox_select_t3->setText(q_give_titles_from_hs_titles.value("st3").toString());
        ui->cbox_select_t4->setText(q_give_titles_from_hs_titles.value("st4").toString());
        ui->cbox_select_t5->setText(q_give_titles_from_hs_titles.value("st5").toString());
        ui->cbox_select_t6->setText(q_give_titles_from_hs_titles.value("st6").toString());
        ui->cbox_select_t7->setText(q_give_titles_from_hs_titles.value("st7").toString());
        ui->cbox_select_t8->setText(q_give_titles_from_hs_titles.value("st8").toString());
        ui->cbox_select_t9->setText(q_give_titles_from_hs_titles.value("st9").toString());
        ui->cbox_select_t10->setText(q_give_titles_from_hs_titles.value("st10").toString());
        ui->cbox_select_t11->setText(q_give_titles_from_hs_titles.value("st11").toString());
        ui->cbox_select_t12->setText(q_give_titles_from_hs_titles.value("st12").toString());
        ui->cbox_select_t13->setText(q_give_titles_from_hs_titles.value("st13").toString());
        ui->cbox_select_t14->setText(q_give_titles_from_hs_titles.value("st14").toString());
        ui->cbox_select_t15->setText(q_give_titles_from_hs_titles.value("st15").toString());
        ui->cbox_select_t16->setText(q_give_titles_from_hs_titles.value("st16").toString());
        ui->cbox_select_t17->setText(q_give_titles_from_hs_titles.value("st17").toString());
        ui->cbox_select_t18->setText(q_give_titles_from_hs_titles.value("st18").toString());
        ui->cbox_select_t19->setText(q_give_titles_from_hs_titles.value("st19").toString());
        ui->cbox_select_t20->setText(q_give_titles_from_hs_titles.value("st20").toString());
        ui->cbox_select_t21->setText(q_give_titles_from_hs_titles.value("st21").toString());
        ui->cbox_select_t22->setText(q_give_titles_from_hs_titles.value("st22").toString());
        ui->cbox_select_t23->setText(q_give_titles_from_hs_titles.value("st23").toString());
        ui->cbox_select_t24->setText(q_give_titles_from_hs_titles.value("st24").toString());
        ui->cbox_select_t25->setText(q_give_titles_from_hs_titles.value("st25").toString());
        ui->cbox_select_t26->setText(q_give_titles_from_hs_titles.value("st26").toString());
        ui->cbox_select_t27->setText(q_give_titles_from_hs_titles.value("st27").toString());
        ui->cbox_select_t28->setText(q_give_titles_from_hs_titles.value("st28").toString());
        ui->cbox_select_t29->setText(q_give_titles_from_hs_titles.value("st29").toString());
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->groupBox_show_class_info->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->show();
}

void MainWindow::on_btn_change_text_headers_clicked()
{
    ui->groupBox_side_left_forms->hide();
    ui->btn_return_to_home_from_settings_form->hide();
    ui->groupBox_side_right_forms->hide();
    ui->groupBox_change_headers->show();
}

void MainWindow::on_btn_return_to_main_forms_sides_from_change_headers_clicked()
{
    ui->groupBox_change_headers->hide();
    ui->btn_return_to_home_from_settings_form->show();
    ui->groupBox_side_left_forms->show();
    ui->groupBox_side_right_forms->show();
}

void MainWindow::on_btn_change_header_stu_hs_clicked()
{
//    QSqlQuery q_update_header_stu_hs("UPDATE headers SET stu_hs='"+ui->txt_change_header_stu_hs->text()+"';");
//    ui->titleX->setText(ui->txt_change_header_stu_hs->text());
//    QMessageBox::information(this," ","سرصفحه لیست  حسینیه/دانش آموزان با موفیقت ویرایش شد.");
}

void MainWindow::on_btn_change_header_search_result_stu_hs_clicked()
{
//    QSqlQuery q_update_header_search_result_stu_hs("UPDATE headers SET search_result_stu_hs='"+ui->txt_change_header_search_result_stu_hs->text()+"';");
//    ui->lbl_title_from_search_result->setText(ui->txt_change_header_search_result_stu_hs->text());
//    QMessageBox::information(this," ","سرصفحه نتیجه جستجو با موفقیت ویرایش شد.");
}

void MainWindow::on_btn_list_of_class_from_home_clicked()
{
    //    QSqlQuery q_give_title_class_list("SELECt * FROM adminconfig;");
    //    while(q_give_title_class_list.next())
    //        ui->txt_class_list_title->setText(q_give_title_class_list.value("t_class_list").toString());


        ui->groupBox_login->hide();
        ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
        ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
        ui->groupBox_home->hide();    ui->groupBox_settings->hide();
        ui->groupBox_search_hs_users->hide();
        ui->groupBox_search_result->hide();
        ui->groupBox_create_class->hide();
        ui->groupBox_show_class_info->hide();
        ui->groupBox_question_select_one_part_for_edit_class->hide();
        ui->groupBox_edit_this_class->hide();
        ui->groupBox_edit_student_from_this_class->hide();
        ui->groupBox_edit_form_stu_from_class->hide();
        ui->groupBox_student_register->hide();
        ui->groupBox_show_students_list->hide();
        ui->groupBox_student_information->hide();
        ui->groupBox_qustion_add_student_to_this_class_by->hide();
        ui->groupBox_insert_more_data_to_student_for_this_class->hide();
        ui->groupBox_search_on_class->hide();
        ui->groupBox_result_search_class->hide();







        ui->groupBox_class_list->show();
        ui->listWidget_class_list->hide();
        ui->txt_class_list_title->hide();
        ui->tableWidget_class_list->clear();



        QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM class_list;");
        QString count_show_users_hs;
        while(q_count_show_users_hs.next())
            count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

        ui->tableWidget_class_list->setRowCount(count_show_users_hs.toInt());
        ui->tableWidget_class_list->setColumnCount(16);
        QSqlQuery q_guve("SELECT * FROM headers;");
        while(q_guve.next())
        {
            ui->tableWidget_class_list->setHorizontalHeaderLabels(QString(q_guve.value("cl0").toString()+";"+q_guve.value("cl1").toString()+";"+q_guve.value("cl2").toString()+";"+q_guve.value("cl3").toString()+";"+q_guve.value("cl4").toString()+";"+q_guve.value("cl5").toString()+";"+q_guve.value("cl6").toString()+";"+q_guve.value("cl7").toString()+";"+q_guve.value("cl8").toString()+";"+q_guve.value("cl9").toString()+";"+q_guve.value("cl10").toString()+";"+q_guve.value("cl11").toString()+";"+q_guve.value("cl12").toString()+";"+q_guve.value("cl13").toString()+";"+q_guve.value("cl14").toString()+";"+q_guve.value("cl15").toString()+";").split(";"));
        }
        ui->tableWidget_class_list->verticalHeader()->hide();
        ui->tableWidget_class_list->setStyleSheet("color:black;");
        QSqlQuery search("SELECT * FROM class_list;");
        QString pid,p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14;
        int sss = 0;
        while (search.next())
        {
            pid = search.value("cid").toString();
            p0 = search.value("ci0").toString();
            p1 = search.value("ci1").toString();
            p2 = search.value("ci2").toString();
            p3 = search.value("ci3").toString();
            p4 = search.value("ci4").toString();
            p5 = search.value("ci5").toString();
            p6 = search.value("ci6").toString();
            p7 = search.value("ci7").toString();
            p8 = search.value("ci8").toString();
            p9 = search.value("ci9").toString();
            p10 = search.value("ci10").toString();
            p11 = search.value("ci11").toString();
            p12 = search.value("ci12").toString();
            p13 = search.value("ci13").toString();
            p14 = search.value("ci14").toString();
            ui->tableWidget_class_list->setItem(sss, 0, new QTableWidgetItem(pid));
            ui->tableWidget_class_list->setItem(sss, 1, new QTableWidgetItem(p0));
            ui->tableWidget_class_list->setItem(sss, 2, new QTableWidgetItem(p1));
            ui->tableWidget_class_list->setItem(sss, 3, new QTableWidgetItem(p2));
            ui->tableWidget_class_list->setItem(sss, 4, new QTableWidgetItem(p3));
            ui->tableWidget_class_list->setItem(sss, 5, new QTableWidgetItem(p4));
            ui->tableWidget_class_list->setItem(sss, 6, new QTableWidgetItem(p5));
            ui->tableWidget_class_list->setItem(sss, 7, new QTableWidgetItem(p6));
            ui->tableWidget_class_list->setItem(sss, 8, new QTableWidgetItem(p7));
            ui->tableWidget_class_list->setItem(sss, 9, new QTableWidgetItem(p8));
            ui->tableWidget_class_list->setItem(sss, 10, new QTableWidgetItem(p9));
            ui->tableWidget_class_list->setItem(sss, 11, new QTableWidgetItem(p10));
            ui->tableWidget_class_list->setItem(sss, 12, new QTableWidgetItem(p11));
            ui->tableWidget_class_list->setItem(sss, 13, new QTableWidgetItem(p12));
            ui->tableWidget_class_list->setItem(sss, 14, new QTableWidgetItem(p13));
            ui->tableWidget_class_list->setItem(sss, 15, new QTableWidgetItem(p14));
            sss++;
        }


    //    QString space_betwen_here = "\t";
    //    QSqlQuery q_give_class_list("SELECT * FROM class_list;");
    //    while (q_give_class_list.next())
    //    {
    //        ui->listWidget_class_list->addItem(q_give_class_list.value("cid").toString()+"`"
    //                                           +space_betwen_here
    //                                           +q_give_class_list.value("ci0").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci1").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci2").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci3").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci4").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci5").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci6").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci7").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci8").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci9").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci10").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci11").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci12").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci13").toString()+
    //                                           space_betwen_here
    //                                           +q_give_class_list.value("ci14").toString());
    //  }
}

void MainWindow::on_btn_creatE_class_from_home_clicked()
{
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();




    //clear time
    //ui->txt_class_info_0->clear(); its auto filled!
    ui->txt_class_info_0->clear();
    ui->txt_class_info_1->clear();
    ui->txt_class_info_2->clear();
    ui->txt_class_info_3->clear();
    ui->txt_class_info_4->clear();
    ui->txt_class_info_5->clear();
    ui->txt_class_info_6->clear();
    ui->txt_class_info_7->clear();
    ui->txt_class_info_8->clear();
    ui->txt_class_info_9->clear();
    ui->txt_class_info_10->clear();
    ui->txt_class_info_11->clear();
    ui->txt_class_info_12->clear();
    ui->txt_class_info_13->clear();
    ui->txt_class_info_14->clear();
    ui->txt_class_parameter_0->clear();
    ui->txt_class_parameter_1->clear();
    ui->txt_class_parameter_2->clear();
    ui->txt_class_parameter_3->clear();
    ui->txt_class_parameter_4->clear();
    ui->txt_class_parameter_5->clear();
    ui->txt_class_parameter_6->clear();
    ui->txt_class_parameter_7->clear();
    ui->txt_class_parameter_8->clear();
    ui->txt_class_parameter_9->clear();
    ui->txt_class_parameter_10->clear();
    ui->txt_class_parameter_11->clear();
    ui->txt_class_parameter_12->clear();
    ui->txt_class_parameter_13->clear();
    ui->txt_class_parameter_14->clear();


    ui->btn_save_class->setText("ثبت");
    ui->groupBox_create_class->setTitle("ایجاد کلاس");
    //everything hide!

    //give LAST CLASS ID
    QSqlQuery q_give_last_cid("SELECT * FROM adminconfig;");
    while(q_give_last_cid.next())
    {
        last_class_id_integer = q_give_last_cid.value("last_cid").toInt();
    }
    ui->txt_class_id->setText("cid_"+QString::number(last_class_id_integer));
    //set titls !
    QSqlQuery q_give_titles_class_and_insert("SELECT * FROM t_class_info;");
    while(q_give_titles_class_and_insert.next())
    {
        ui->lbl_class_id->setText(q_give_titles_class_and_insert.value("t_cid").toString());
        ui->lbl_class_info_0->setText(q_give_titles_class_and_insert.value("t_cinfo0").toString());
        ui->lbl_class_info_1->setText(q_give_titles_class_and_insert.value("t_cinfo1").toString());
        ui->lbl_class_info_2->setText(q_give_titles_class_and_insert.value("t_cinfo2").toString());
        ui->lbl_class_info_3->setText(q_give_titles_class_and_insert.value("t_cinfo3").toString());
        ui->lbl_class_info_4->setText(q_give_titles_class_and_insert.value("t_cinfo4").toString());
        ui->lbl_class_info_5->setText(q_give_titles_class_and_insert.value("t_cinfo5").toString());
        ui->lbl_class_info_6->setText(q_give_titles_class_and_insert.value("t_cinfo6").toString());
        ui->lbl_class_info_7->setText(q_give_titles_class_and_insert.value("t_cinfo7").toString());
        ui->lbl_class_info_8->setText(q_give_titles_class_and_insert.value("t_cinfo8").toString());
        ui->lbl_class_info_9->setText(q_give_titles_class_and_insert.value("t_cinfo9").toString());
        ui->lbl_class_info_10->setText(q_give_titles_class_and_insert.value("t_cinfo10").toString());
        ui->lbl_class_info_11->setText(q_give_titles_class_and_insert.value("t_cinfo11").toString());
        ui->lbl_class_info_12->setText(q_give_titles_class_and_insert.value("t_cinfo12").toString());
        ui->lbl_class_info_13->setText(q_give_titles_class_and_insert.value("t_cinfo13").toString());
        ui->lbl_class_info_14->setText(q_give_titles_class_and_insert.value("t_cinfo14").toString());

        ui->lbl_class_parameter_0->setText(q_give_titles_class_and_insert.value("t_cpara0").toString());
        ui->lbl_class_parameter_1->setText(q_give_titles_class_and_insert.value("t_cpara1").toString());
        ui->lbl_class_parameter_2->setText(q_give_titles_class_and_insert.value("t_cpara2").toString());
        ui->lbl_class_parameter_3->setText(q_give_titles_class_and_insert.value("t_cpara3").toString());
        ui->lbl_class_parameter_4->setText(q_give_titles_class_and_insert.value("t_cpara4").toString());
        ui->lbl_class_parameter_5->setText(q_give_titles_class_and_insert.value("t_cpara5").toString());
        ui->lbl_class_parameter_6->setText(q_give_titles_class_and_insert.value("t_cpara6").toString());
        ui->lbl_class_parameter_7->setText(q_give_titles_class_and_insert.value("t_cpara7").toString());
        ui->lbl_class_parameter_8->setText(q_give_titles_class_and_insert.value("t_cpara8").toString());
        ui->lbl_class_parameter_9->setText(q_give_titles_class_and_insert.value("t_cpara9").toString());
        ui->lbl_class_parameter_10->setText(q_give_titles_class_and_insert.value("t_cpara10").toString());
        ui->lbl_class_parameter_11->setText(q_give_titles_class_and_insert.value("t_cpara11").toString());
        ui->lbl_class_parameter_12->setText(q_give_titles_class_and_insert.value("t_cpara12").toString());
        ui->lbl_class_parameter_13->setText(q_give_titles_class_and_insert.value("t_cpara13").toString());
        ui->lbl_class_parameter_14->setText(q_give_titles_class_and_insert.value("t_cpara14").toString());
    }
    ui->groupBox_create_class->show();
    ui->scrollArea_class_modify_create->ensureVisible(0,0,0,0);
}

void MainWindow::on_btn_students_list_from_home_clicked()
{
    //titleX set Text
    ui->groupBox_show_users_hs->show();
    ui->groupBox_show_users_hs->setTitle("لیست دانش آموزان");
    ui->listWidget_show_users_hs->clear();




    ui->scrollArea_register->ensureVisible(0,0,0,0);

    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();




    //remove all values from userinformation
    ui->lbl_hs_userinfo_t0->clear();    ui->lbl_hs_userinfo_p0->clear();
    ui->lbl_hs_userinfo_t1->clear();    ui->lbl_hs_userinfo_p1->clear();
    ui->lbl_hs_userinfo_t2->clear();    ui->lbl_hs_userinfo_p2->clear();
    ui->lbl_hs_userinfo_t3->clear();    ui->lbl_hs_userinfo_p3->clear();
    ui->lbl_hs_userinfo_t4->clear();    ui->lbl_hs_userinfo_p4->clear();
    ui->lbl_hs_userinfo_t5->clear();    ui->lbl_hs_userinfo_p5->clear();
    ui->lbl_hs_userinfo_t6->clear();    ui->lbl_hs_userinfo_p6->clear();
    ui->lbl_hs_userinfo_t7->clear();    ui->lbl_hs_userinfo_p7->clear();
    ui->lbl_hs_userinfo_t8->clear();    ui->lbl_hs_userinfo_p8->clear();
    ui->lbl_hs_userinfo_t9->clear();    ui->lbl_hs_userinfo_p9->clear();
    ui->lbl_hs_userinfo_t10->clear();    ui->lbl_hs_userinfo_p10->clear();
    ui->lbl_hs_userinfo_t11->clear();    ui->lbl_hs_userinfo_p11->clear();
    ui->lbl_hs_userinfo_t12->clear();    ui->lbl_hs_userinfo_p12->clear();
    ui->lbl_hs_userinfo_t13->clear();    ui->lbl_hs_userinfo_p13->clear();
    ui->lbl_hs_userinfo_t14->clear();    ui->lbl_hs_userinfo_p14->clear();
    ui->lbl_hs_userinfo_t15->clear();    ui->lbl_hs_userinfo_p15->clear();
    ui->lbl_hs_userinfo_t16->clear();    ui->lbl_hs_userinfo_p16->clear();
    ui->lbl_hs_userinfo_t17->clear();    ui->lbl_hs_userinfo_p17->clear();
    ui->lbl_hs_userinfo_t18->clear();    ui->lbl_hs_userinfo_p18->clear();
    ui->lbl_hs_userinfo_t19->clear();    ui->lbl_hs_userinfo_p19->clear();
    ui->lbl_hs_userinfo_t20->clear();    ui->lbl_hs_userinfo_p20->clear();
    ui->lbl_hs_userinfo_t21->clear();    ui->lbl_hs_userinfo_p21->clear();
    ui->lbl_hs_userinfo_t22->clear();    ui->lbl_hs_userinfo_p22->clear();
    ui->lbl_hs_userinfo_t23->clear();    ui->lbl_hs_userinfo_p23->clear();
    ui->lbl_hs_userinfo_t24->clear();    ui->lbl_hs_userinfo_p24->clear();
    ui->lbl_hs_userinfo_t25->clear();    ui->lbl_hs_userinfo_p25->clear();
    ui->lbl_hs_userinfo_t26->clear();    ui->lbl_hs_userinfo_p26->clear();
    ui->lbl_hs_userinfo_t27->clear();    ui->lbl_hs_userinfo_p27->clear();
    ui->lbl_hs_userinfo_t28->clear();    ui->lbl_hs_userinfo_p28->clear();
    ui->lbl_hs_userinfo_t29->clear();    ui->lbl_hs_userinfo_p29->clear();
    ui->lbl_hs_userinfo_avatar->clear();    ui->lbl_hs_userinfo_avatar->clear();

    ui->listWidget_show_users_hs->hide();
    ui->titleX->hide();
    ui->tableWidget_show_users_hs->clear();
    QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM students;");
    QString count_show_users_hs;
    while(q_count_show_users_hs.next())
        count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

    ui->tableWidget_show_users_hs->setRowCount(count_show_users_hs.toInt());
    ui->tableWidget_show_users_hs->setColumnCount(4);
    QSqlQuery q_give_titles("SELECT * FROM studentTitles;");
    QString t0,t1,t2,t3;
    while(q_give_titles.next())
    {
        t0 = q_give_titles.value("st0").toString();
        t1 = q_give_titles.value("st1").toString();
        t2 = q_give_titles.value("st2").toString();
        t3 = q_give_titles.value("st3").toString();
    }
    ui->tableWidget_show_users_hs->setHorizontalHeaderLabels(QString(t0+";"+t1+";"+t2+";"+t3+";").split(";"));
    ui->tableWidget_show_users_hs->verticalHeader()->hide();
    QSqlQuery search("SELECT * FROM students;");
    QString p0,p1,p2,p3;
    int sss = 0;
    while (search.next())
    {
        p0 = search.value("p0").toString();
        p1 = search.value("p1").toString();
        p2 = search.value("p2").toString();
        p3 = search.value("p3").toString();
        ui->tableWidget_show_users_hs->setItem(sss, 0, new QTableWidgetItem(p0));
        ui->tableWidget_show_users_hs->setItem(sss, 1, new QTableWidgetItem(p1));
        ui->tableWidget_show_users_hs->setItem(sss, 2, new QTableWidgetItem(p2));
        ui->tableWidget_show_users_hs->setItem(sss, 3, new QTableWidgetItem(p3));
        sss++;
    }
    ui->groupBox_show_users_hs->show();
}

void MainWindow::on_btn_create_new_student_from_home_clicked()
{

    ui->txt_register_0->clear();  ui->txt_register_1->clear();  ui->txt_register_2->clear();  ui->txt_register_3->clear();  ui->txt_register_4->clear(); ui->txt_register_5->clear();  ui->txt_register_6->clear();   ui->txt_register_7->clear();  ui->txt_register_8->clear();  ui->txt_register_9->clear();  ui->txt_register_10->clear();  ui->txt_register_11->clear();  ui->txt_register_12->clear();   ui->txt_register_13->clear();   ui->txt_register_14->clear();  ui->txt_register_15->clear();  ui->txt_register_16->clear();  ui->txt_register_17->clear();  ui->txt_register_18->clear();  ui->txt_register_19->clear();  ui->txt_register_20->clear();  ui->txt_register_21->clear();  ui->txt_register_22->clear();   ui->txt_register_23->clear();   ui->txt_register_24->clear();   ui->txt_register_25->clear();  ui->txt_register_26->clear();  ui->txt_register_27->clear();  ui->txt_register_28->clear();  ui->txt_register_29->clear();   avatar_url = "";  ui->lbl_register_avatar->setPixmap(avatar_url);    ui->lbl_register_avatar->setScaledContents(true); ///root/Downloads/photo3983657131855423630.jpg




    ui->groupBox_login->hide();
    ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();



    //txt_register_0
    ui->groupBox_hs_register->setTitle("فرم ثبت نام دانش آموز جدید");
    ui->btn_register_insert->setText("ثبت");
    ui->btn_edit_goto_delete_this_user->hide();
    ui->scrollArea_register->ensureVisible(0,0,0,0);
    ui->groupBox_hs_register->show();
    QSqlQuery q_titles_students("SELECT * FROM studentTitles;");
    while(q_titles_students.next())
    {
        ui->lbl_register_t0->setText(q_titles_students.value("st0").toString());
        ui->lbl_register_t1->setText(q_titles_students.value("st1").toString());
        ui->lbl_register_t2->setText(q_titles_students.value("st2").toString());
        ui->lbl_register_t3->setText(q_titles_students.value("st3").toString());
        ui->lbl_register_t4->setText(q_titles_students.value("st4").toString());
        ui->lbl_register_t5->setText(q_titles_students.value("st5").toString());
        ui->lbl_register_t6->setText(q_titles_students.value("st6").toString());
        ui->lbl_register_t7->setText(q_titles_students.value("st7").toString());
        ui->lbl_register_t8->setText(q_titles_students.value("st8").toString());
        ui->lbl_register_t9->setText(q_titles_students.value("st9").toString());
        ui->lbl_register_t10->setText(q_titles_students.value("st10").toString());
        ui->lbl_register_t11->setText(q_titles_students.value("st11").toString());
        ui->lbl_register_t12->setText(q_titles_students.value("st12").toString());
        ui->lbl_register_t13->setText(q_titles_students.value("st13").toString());
        ui->lbl_register_t14->setText(q_titles_students.value("st14").toString());
        ui->lbl_register_t15->setText(q_titles_students.value("st15").toString());
        ui->lbl_register_t16->setText(q_titles_students.value("st16").toString());
        ui->lbl_register_t17->setText(q_titles_students.value("st17").toString());
        ui->lbl_register_t18->setText(q_titles_students.value("st18").toString());
        ui->lbl_register_t19->setText(q_titles_students.value("st19").toString());
        ui->lbl_register_t20->setText(q_titles_students.value("st20").toString());
        ui->lbl_register_t21->setText(q_titles_students.value("st21").toString());
        ui->lbl_register_t22->setText(q_titles_students.value("st22").toString());
        ui->lbl_register_t23->setText(q_titles_students.value("st23").toString());
        ui->lbl_register_t24->setText(q_titles_students.value("st24").toString());
        ui->lbl_register_t25->setText(q_titles_students.value("st25").toString());
        ui->lbl_register_t26->setText(q_titles_students.value("st26").toString());
        ui->lbl_register_t27->setText(q_titles_students.value("st27").toString());
        ui->lbl_register_t28->setText(q_titles_students.value("st28").toString());
        ui->lbl_register_t29->setText(q_titles_students.value("st29").toString());
    }
    if(avatar_url == "")
    {
        QSqlQuery search_for_url_avatar_defualt("SELECT * FROM adminconfig;");
        while (search_for_url_avatar_defualt.next())
        {
            defualt_avatar = search_for_url_avatar_defualt.value("defualt_avatar").toString();
        }
        QPixmap pm(defualt_avatar); ui->lbl_register_avatar->setPixmap(defualt_avatar);
        ui->lbl_register_avatar->setScaledContents(true);
    }
}

void MainWindow::on_btn_search_students_from_home_clicked()
{
    im_from_students_list = true;
    ui->groupBox_search_hs_users->setTitle("جستجو دانش آموزان");
    bool the_status_for_set_check_all=false;
    ui->cbox_select_all->setText("همه فعال");
    ui->rbutton_search_likes_from_hs_users_yes->setChecked(the_status_for_set_check_all);
    ui->rbutton_search_likes_from_hs_users_no->setChecked(the_status_for_set_check_all);
    ui->cbox_select_all->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t1->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t0->setChecked(the_status_for_set_check_all);   ui->cbox_select_t16->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t2->setChecked(the_status_for_set_check_all);   ui->cbox_select_t17->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t3->setChecked(the_status_for_set_check_all);   ui->cbox_select_t18->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t4->setChecked(the_status_for_set_check_all);   ui->cbox_select_t19->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t5->setChecked(the_status_for_set_check_all);   ui->cbox_select_t20->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t6->setChecked(the_status_for_set_check_all);   ui->cbox_select_t21->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t7->setChecked(the_status_for_set_check_all);   ui->cbox_select_t22->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t8->setChecked(the_status_for_set_check_all);   ui->cbox_select_t23->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t9->setChecked(the_status_for_set_check_all);   ui->cbox_select_t24->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t10->setChecked(the_status_for_set_check_all);   ui->cbox_select_t25->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t11->setChecked(the_status_for_set_check_all);   ui->cbox_select_t26->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t12->setChecked(the_status_for_set_check_all);   ui->cbox_select_t27->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t13->setChecked(the_status_for_set_check_all);   ui->cbox_select_t28->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t14->setChecked(the_status_for_set_check_all);   ui->cbox_select_t29->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t15->setChecked(the_status_for_set_check_all);


    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();


    ui->txt_text_search_for_hs_users->clear();



    ui->scrollArea_checkboxs_select_part_search_from_hs_users->ensureVisible(0,0,0,0);
    ui->groupBox_search_hs_users->show();
    QSqlQuery q_give_titles_from_hs_titles("SELECT * FROM studentTitles;");
    while(q_give_titles_from_hs_titles.next())
    {
        ui->cbox_select_t0->setText(q_give_titles_from_hs_titles.value("st0").toString());
        ui->cbox_select_t1->setText(q_give_titles_from_hs_titles.value("st1").toString());
        ui->cbox_select_t2->setText(q_give_titles_from_hs_titles.value("st2").toString());
        ui->cbox_select_t3->setText(q_give_titles_from_hs_titles.value("st3").toString());
        ui->cbox_select_t4->setText(q_give_titles_from_hs_titles.value("st4").toString());
        ui->cbox_select_t5->setText(q_give_titles_from_hs_titles.value("st5").toString());
        ui->cbox_select_t6->setText(q_give_titles_from_hs_titles.value("st6").toString());
        ui->cbox_select_t7->setText(q_give_titles_from_hs_titles.value("st7").toString());
        ui->cbox_select_t8->setText(q_give_titles_from_hs_titles.value("st8").toString());
        ui->cbox_select_t9->setText(q_give_titles_from_hs_titles.value("st9").toString());
        ui->cbox_select_t10->setText(q_give_titles_from_hs_titles.value("st10").toString());
        ui->cbox_select_t11->setText(q_give_titles_from_hs_titles.value("st11").toString());
        ui->cbox_select_t12->setText(q_give_titles_from_hs_titles.value("st12").toString());
        ui->cbox_select_t13->setText(q_give_titles_from_hs_titles.value("st13").toString());
        ui->cbox_select_t14->setText(q_give_titles_from_hs_titles.value("st14").toString());
        ui->cbox_select_t15->setText(q_give_titles_from_hs_titles.value("st15").toString());
        ui->cbox_select_t16->setText(q_give_titles_from_hs_titles.value("st16").toString());
        ui->cbox_select_t17->setText(q_give_titles_from_hs_titles.value("st17").toString());
        ui->cbox_select_t18->setText(q_give_titles_from_hs_titles.value("st18").toString());
        ui->cbox_select_t19->setText(q_give_titles_from_hs_titles.value("st19").toString());
        ui->cbox_select_t20->setText(q_give_titles_from_hs_titles.value("st20").toString());
        ui->cbox_select_t21->setText(q_give_titles_from_hs_titles.value("st21").toString());
        ui->cbox_select_t22->setText(q_give_titles_from_hs_titles.value("st22").toString());
        ui->cbox_select_t23->setText(q_give_titles_from_hs_titles.value("st23").toString());
        ui->cbox_select_t24->setText(q_give_titles_from_hs_titles.value("st24").toString());
        ui->cbox_select_t25->setText(q_give_titles_from_hs_titles.value("st25").toString());
        ui->cbox_select_t26->setText(q_give_titles_from_hs_titles.value("st26").toString());
        ui->cbox_select_t27->setText(q_give_titles_from_hs_titles.value("st27").toString());
        ui->cbox_select_t28->setText(q_give_titles_from_hs_titles.value("st28").toString());
        ui->cbox_select_t29->setText(q_give_titles_from_hs_titles.value("st29").toString());
    }
}

void MainWindow::on_btn_search_user_hs_from_home_clicked()
{
    im_from_hs_list = true;
    ui->groupBox_search_hs_users->setTitle("جستجو اعضای حسینیه");
    bool the_status_for_set_check_all=false;
    ui->cbox_select_all->setText("همه فعال");
    ui->rbutton_search_likes_from_hs_users_yes->setChecked(the_status_for_set_check_all);
    ui->rbutton_search_likes_from_hs_users_no->setChecked(the_status_for_set_check_all);
    ui->cbox_select_all->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t1->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t0->setChecked(the_status_for_set_check_all);   ui->cbox_select_t16->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t2->setChecked(the_status_for_set_check_all);   ui->cbox_select_t17->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t3->setChecked(the_status_for_set_check_all);   ui->cbox_select_t18->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t4->setChecked(the_status_for_set_check_all);   ui->cbox_select_t19->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t5->setChecked(the_status_for_set_check_all);   ui->cbox_select_t20->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t6->setChecked(the_status_for_set_check_all);   ui->cbox_select_t21->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t7->setChecked(the_status_for_set_check_all);   ui->cbox_select_t22->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t8->setChecked(the_status_for_set_check_all);   ui->cbox_select_t23->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t9->setChecked(the_status_for_set_check_all);   ui->cbox_select_t24->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t10->setChecked(the_status_for_set_check_all);   ui->cbox_select_t25->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t11->setChecked(the_status_for_set_check_all);   ui->cbox_select_t26->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t12->setChecked(the_status_for_set_check_all);   ui->cbox_select_t27->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t13->setChecked(the_status_for_set_check_all);   ui->cbox_select_t28->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t14->setChecked(the_status_for_set_check_all);   ui->cbox_select_t29->setChecked(the_status_for_set_check_all);
    ui->cbox_select_t15->setChecked(the_status_for_set_check_all);


    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_search_on_class->hide();
    ui->groupBox_result_search_class->hide();



    ui->txt_text_search_for_hs_users->clear();



    ui->scrollArea_checkboxs_select_part_search_from_hs_users->ensureVisible(0,0,0,0);
    ui->groupBox_search_hs_users->show();
    QSqlQuery q_give_titles_from_hs_titles("SELECT * FROM registrationTitles");
    while(q_give_titles_from_hs_titles.next())
    {
        ui->cbox_select_t0->setText(q_give_titles_from_hs_titles.value("t0").toString());
        ui->cbox_select_t1->setText(q_give_titles_from_hs_titles.value("t1").toString());
        ui->cbox_select_t2->setText(q_give_titles_from_hs_titles.value("t2").toString());
        ui->cbox_select_t3->setText(q_give_titles_from_hs_titles.value("t3").toString());
        ui->cbox_select_t4->setText(q_give_titles_from_hs_titles.value("t4").toString());
        ui->cbox_select_t5->setText(q_give_titles_from_hs_titles.value("t5").toString());
        ui->cbox_select_t6->setText(q_give_titles_from_hs_titles.value("t6").toString());
        ui->cbox_select_t7->setText(q_give_titles_from_hs_titles.value("t7").toString());
        ui->cbox_select_t8->setText(q_give_titles_from_hs_titles.value("t8").toString());
        ui->cbox_select_t9->setText(q_give_titles_from_hs_titles.value("t9").toString());
        ui->cbox_select_t10->setText(q_give_titles_from_hs_titles.value("t10").toString());
        ui->cbox_select_t11->setText(q_give_titles_from_hs_titles.value("t11").toString());
        ui->cbox_select_t12->setText(q_give_titles_from_hs_titles.value("t12").toString());
        ui->cbox_select_t13->setText(q_give_titles_from_hs_titles.value("t13").toString());
        ui->cbox_select_t14->setText(q_give_titles_from_hs_titles.value("t14").toString());
        ui->cbox_select_t15->setText(q_give_titles_from_hs_titles.value("t15").toString());
        ui->cbox_select_t16->setText(q_give_titles_from_hs_titles.value("t16").toString());
        ui->cbox_select_t17->setText(q_give_titles_from_hs_titles.value("t17").toString());
        ui->cbox_select_t18->setText(q_give_titles_from_hs_titles.value("t18").toString());
        ui->cbox_select_t19->setText(q_give_titles_from_hs_titles.value("t19").toString());
        ui->cbox_select_t20->setText(q_give_titles_from_hs_titles.value("t20").toString());
        ui->cbox_select_t21->setText(q_give_titles_from_hs_titles.value("t21").toString());
        ui->cbox_select_t22->setText(q_give_titles_from_hs_titles.value("t22").toString());
        ui->cbox_select_t23->setText(q_give_titles_from_hs_titles.value("t23").toString());
        ui->cbox_select_t24->setText(q_give_titles_from_hs_titles.value("t24").toString());
        ui->cbox_select_t25->setText(q_give_titles_from_hs_titles.value("t25").toString());
        ui->cbox_select_t26->setText(q_give_titles_from_hs_titles.value("t26").toString());
        ui->cbox_select_t27->setText(q_give_titles_from_hs_titles.value("t27").toString());
        ui->cbox_select_t28->setText(q_give_titles_from_hs_titles.value("t28").toString());
        ui->cbox_select_t29->setText(q_give_titles_from_hs_titles.value("t29").toString());
    }
}

void MainWindow::on_cbox_search_class_select_all_stateChanged(int)
{

    bool status_of_search_rbtn_select_all;
    if(ui->cbox_search_class_select_all->text() == "همه فعال")
    {
        status_of_search_rbtn_select_all = true;
        ui->cbox_search_class_select_all->setText("همه غیرفعال");
    }
    else
    {
        status_of_search_rbtn_select_all = false;
        ui->cbox_search_class_select_all->setText("همه فعال");

    }
    ui->cbox_search_class_select_all->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_0->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_1->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_2->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_3->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_4->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_5->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_6->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_7->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_8->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_9->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_10->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_11->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_12->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_13->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_14->setChecked(status_of_search_rbtn_select_all);
//    ui->cbox_search_class_ci_15->setChecked(status_of_search_rbtn_select_all);




}

void MainWindow::on_btn_go_search_on_class_clicked()
{

    //load title
    ui->tableWidget_search_class_result->clear();


    ui->tableWidget_search_class_result->verticalHeader()->hide();
    ui->listWidget_search_class_result->hide();
    ui->lbl_search_class_result_header->hide();

    int ssss=0;
    int rowcount = 0;
    ui->tableWidget_search_class_result->setRowCount(rowcount);
    ui->tableWidget_search_class_result->setColumnCount(4);
    QSqlQuery q_guve("SELECT * FROM headers;");
    while(q_guve.next())
    {
       ui->tableWidget_search_class_result->setHorizontalHeaderLabels(QString(q_guve.value("src0").toString()+";"+q_guve.value("src1").toString()+";"+q_guve.value("src2").toString()+";"+q_guve.value("src3").toString()+";").split(";"));
    }
    QString para0,para1,para2,para3;
    if(ui->rbtn_want_seach_on_class_with_like_yes->isChecked() == true)
    {
        ui->groupBox_search_on_class->hide();
        ui->groupBox_result_search_class->show();
        QString table_name_is_here = "class_list";
        QString space_betweens_packages = "\t";
        QString big_space_betweens_packages = "\t ";
        if(ui->cbox_search_class_ci_0->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci0 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci0").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci0").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_1->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci1 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci1").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_2->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci2 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci2").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_3->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci3 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci3").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci3").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_4->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci4 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci4").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci4").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_5->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci5 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci5").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci5").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_6->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci6 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci6").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci6").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_7->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci7 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci7").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci7").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_8->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci8 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci8").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci8").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_9->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci9 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci9").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci9").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_10->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci10 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci0").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci10").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_11->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci11 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci11").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci11").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_12->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci12 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci12").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci12").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_13->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci13 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci13").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci13").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_14->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci14 LIKE '%"+ui->txt_text_for_search_on_class->text()+"%';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci14").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci14").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
    }
    else if(ui->rbtn_want_seach_on_class_with_like_no->isChecked() == true)
    {
        ui->groupBox_search_on_class->hide();
        ui->groupBox_result_search_class->show();
//        ui->listWidget_search_class_result->clear();

        QString table_name_is_here = "class_list";
        QString space_betweens_packages = "\t";
        QString big_space_betweens_packages = "\t ";
        if(ui->cbox_search_class_ci_0->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci0='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci0").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci0").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_1->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci1='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci1").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_2->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci2='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci2").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_3->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci3='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci3").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci3").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_4->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci4='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci4").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci4").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_5->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci5='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci5").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci5").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_6->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci6='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci6").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci6").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_7->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci7='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci7").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci7").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_8->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci8='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
           {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci8").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci8").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_9->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci9='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci9").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci9").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_10->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci10='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci10").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci10").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_11->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci11='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci11").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci11").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_12->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci12='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci12").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci12").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_13->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci13='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci13").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci13").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
        if(ui->cbox_search_class_ci_14->isChecked() == true)
        {
            QSqlQuery q_give_for_cbox_t0("SELECT * FROM "+table_name_is_here+" WHERE ci14='"+ui->txt_text_for_search_on_class->text()+"';");
            while(q_give_for_cbox_t0.next())
            {
                ++rowcount;
                ui->tableWidget_search_class_result->setRowCount(rowcount);
                para0 = q_give_for_cbox_t0.value("cid").toString();
                para1 = q_give_for_cbox_t0.value("ci1").toString();
                para2 = q_give_for_cbox_t0.value("ci2").toString();
                para3 = q_give_for_cbox_t0.value("ci14").toString();
                ui->tableWidget_search_class_result->setItem(ssss, 0, new QTableWidgetItem(para0));
                ui->tableWidget_search_class_result->setItem(ssss, 1, new QTableWidgetItem(para1));
                ui->tableWidget_search_class_result->setItem(ssss, 2, new QTableWidgetItem(para2));
                ui->tableWidget_search_class_result->setItem(ssss, 3, new QTableWidgetItem(para3));
                ssss++;
//                QString data_package = q_give_for_cbox_t0.value("cid").toString()+"`"+ space_betweens_packages + q_give_for_cbox_t0.value("ci1").toString() +space_betweens_packages + q_give_for_cbox_t0.value("ci2").toString() +  big_space_betweens_packages + q_give_for_cbox_t0.value("ci14").toString();
//                ui->listWidget_search_class_result->addItem(data_package);
            }
        }
    }
    else
    {
        //error message
        QMessageBox::information(this," ","لطفا یک مورد در بخش  آیا نمونه های مشابه هم نمایش داده شوند ؟ را انتخاب کنید");
    }
}

void MainWindow::on_btn_change_and_save_header_search_class_clicked()
{
//    QSqlQuery q_update_header_stu_hs("UPDATE headers SET search_class_result='"+ui->lbl_search_class_result_header->text()+"';");
//    ui->lbl_search_class_result_header->setText(ui->lbl_search_class_result_header->text());
//    QMessageBox::information(this," ","سر صفحه ی نتیجه جستجو با موفیقت ویرایش شد");
}

void MainWindow::on_btn_return_to_home_from_search_result_class_clicked()
{
    ui->groupBox_result_search_class->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_btn_show_this_class_from_search_result_class_clicked()
{
//    if(ui->listWidget_search_class_result->selectedItems().size() > 0)
//    {
//        QString class_id_is_here_men = ui->listWidget_search_class_result->currentItem()->text();
//        int j = 0;
//        int number_for_cut = 0;
//        while ((j = class_id_is_here_men.indexOf("`", j)) != -1)
//        {
//            number_for_cut = j;
//            break;
//        }


//        QStringRef ref_class_charecters = class_id_is_here_men.leftRef(number_for_cut);
//        QString remove_cid_charecters = ref_class_charecters.toString();
//        remove_cid_charecters.remove(QString("cid_"), Qt::CaseInsensitive);
//        remove_cid_charecters.replace(QString(" "), QString(""));
//        remove_cid_charecters.remove(QString("`"), Qt::CaseInsensitive);


    int row = ui->tableWidget_search_class_result->currentRow();
    int column = ui->tableWidget_search_class_result->currentColumn();
    QString roro = ui->tableWidget_search_class_result->model()->index(row,column).data().toString();
    QString remove_cid_charecters = roro;


        class_id_is_herex = roro;




        ui->groupBox_result_search_class->hide();
        ui->scrollArea_class_detials_from_classinfoshow->ensureVisible(0,0,0,0);
        ui->scrollArea_class_info_from_classinfoshow->ensureVisible(0,0,0,0);
        QSqlQuery q_give_titles_and_info_from_t_classinfo_and_class_list("SELECT * FROM t_class_info;");
        while(q_give_titles_and_info_from_t_classinfo_and_class_list.next())
        {
            ui->lbl_show_classinfo_t_cinfo_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo0").toString());
            ui->lbl_show_classinfo_t_cinfo_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo1").toString());
            ui->lbl_show_classinfo_t_cinfo_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo2").toString());
            ui->lbl_show_classinfo_t_cinfo_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo3").toString());
            ui->lbl_show_classinfo_t_cinfo_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo4").toString());
            ui->lbl_show_classinfo_t_cinfo_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo5").toString());
            ui->lbl_show_classinfo_t_cinfo_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo6").toString());
            ui->lbl_show_classinfo_t_cinfo_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo7").toString());
            ui->lbl_show_classinfo_t_cinfo_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo8").toString());
            ui->lbl_show_classinfo_t_cinfo_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo9").toString());
            ui->lbl_show_classinfo_t_cinfo_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo10").toString());
            ui->lbl_show_classinfo_t_cinfo_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo11").toString());
            ui->lbl_show_classinfo_t_cinfo_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo12").toString());
            ui->lbl_show_classinfo_t_cinfo_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo13").toString());
            ui->lbl_show_classinfo_t_cinfo_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cinfo14").toString());

            ui->lbl_show_classinfo_t_cpara_0->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara0").toString());
            ui->lbl_show_classinfo_t_cpara_1->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara1").toString());
            ui->lbl_show_classinfo_t_cpara_2->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara2").toString());
            ui->lbl_show_classinfo_t_cpara_3->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara3").toString());
            ui->lbl_show_classinfo_t_cpara_4->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara4").toString());
            ui->lbl_show_classinfo_t_cpara_5->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara5").toString());
            ui->lbl_show_classinfo_t_cpara_6->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara6").toString());
            ui->lbl_show_classinfo_t_cpara_7->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara7").toString());
            ui->lbl_show_classinfo_t_cpara_8->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara8").toString());
            ui->lbl_show_classinfo_t_cpara_9->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara9").toString());
            ui->lbl_show_classinfo_t_cpara_10->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara10").toString());
            ui->lbl_show_classinfo_t_cpara_11->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara11").toString());
            ui->lbl_show_classinfo_t_cpara_12->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara12").toString());
            ui->lbl_show_classinfo_t_cpara_13->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara13").toString());
            ui->lbl_show_classinfo_t_cpara_14->setText(q_give_titles_and_info_from_t_classinfo_and_class_list.value("t_cpara14").toString());
        }

        QSqlQuery q_give_info_from_clasS_list("SELECT * FROM class_list WHERE cid='"+remove_cid_charecters+"';");
        while(q_give_info_from_clasS_list.next())
        {
            ui->lbl_show_classinfo_ci_0->setText(q_give_info_from_clasS_list.value("ci0").toString());
            ui->lbl_show_classinfo_ci_1->setText(q_give_info_from_clasS_list.value("ci1").toString());
            ui->lbl_show_classinfo_ci_2->setText(q_give_info_from_clasS_list.value("ci2").toString());
            ui->lbl_show_classinfo_ci_3->setText(q_give_info_from_clasS_list.value("ci3").toString());
            ui->lbl_show_classinfo_ci_4->setText(q_give_info_from_clasS_list.value("ci4").toString());
            ui->lbl_show_classinfo_ci_5->setText(q_give_info_from_clasS_list.value("ci5").toString());
            ui->lbl_show_classinfo_ci_6->setText(q_give_info_from_clasS_list.value("ci6").toString());
            ui->lbl_show_classinfo_ci_7->setText(q_give_info_from_clasS_list.value("ci7").toString());
            ui->lbl_show_classinfo_ci_8->setText(q_give_info_from_clasS_list.value("ci8").toString());
            ui->lbl_show_classinfo_ci_9->setText(q_give_info_from_clasS_list.value("ci9").toString());
            ui->lbl_show_classinfo_ci_10->setText(q_give_info_from_clasS_list.value("ci10").toString());
            ui->lbl_show_classinfo_ci_11->setText(q_give_info_from_clasS_list.value("ci11").toString());
            ui->lbl_show_classinfo_ci_12->setText(q_give_info_from_clasS_list.value("ci12").toString());
            ui->lbl_show_classinfo_ci_13->setText(q_give_info_from_clasS_list.value("ci13").toString());
            ui->lbl_show_classinfo_ci_14->setText(q_give_info_from_clasS_list.value("ci14").toString());

            ui->lbl_show_classinfo_cp_0->setText(q_give_info_from_clasS_list.value("cp0").toString());
            ui->lbl_show_classinfo_cp_1->setText(q_give_info_from_clasS_list.value("cp1").toString());
            ui->lbl_show_classinfo_cp_2->setText(q_give_info_from_clasS_list.value("cp2").toString());
            ui->lbl_show_classinfo_cp_3->setText(q_give_info_from_clasS_list.value("cp3").toString());
            ui->lbl_show_classinfo_cp_4->setText(q_give_info_from_clasS_list.value("cp4").toString());
            ui->lbl_show_classinfo_cp_5->setText(q_give_info_from_clasS_list.value("cp5").toString());
            ui->lbl_show_classinfo_cp_6->setText(q_give_info_from_clasS_list.value("cp6").toString());
            ui->lbl_show_classinfo_cp_7->setText(q_give_info_from_clasS_list.value("cp7").toString());
            ui->lbl_show_classinfo_cp_8->setText(q_give_info_from_clasS_list.value("cp8").toString());
            ui->lbl_show_classinfo_cp_9->setText(q_give_info_from_clasS_list.value("cp9").toString());
            ui->lbl_show_classinfo_cp_10->setText(q_give_info_from_clasS_list.value("cp10").toString());
            ui->lbl_show_classinfo_cp_11->setText(q_give_info_from_clasS_list.value("cp11").toString());
            ui->lbl_show_classinfo_cp_12->setText(q_give_info_from_clasS_list.value("cp12").toString());
            ui->lbl_show_classinfo_cp_13->setText(q_give_info_from_clasS_list.value("cp13").toString());
            ui->lbl_show_classinfo_cp_14->setText(q_give_info_from_clasS_list.value("cp14").toString());
        }


        ui->tableWidget_list_of_sutdents_for_show_to_class_info->clear();
        ui->listWidget_list_of_sutdents_for_show_to_class_info->hide();

        QSqlQuery q_count_show_users_hs("SELECT COUNT(*) AS ccca FROM "+remove_cid_charecters+";");
        QString count_show_users_hs;
        while(q_count_show_users_hs.next())
            count_show_users_hs = q_count_show_users_hs.value("ccca").toString();

        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setRowCount(count_show_users_hs.toInt());
        ui->tableWidget_list_of_sutdents_for_show_to_class_info->setColumnCount(15);

        ui->tableWidget_list_of_sutdents_for_show_to_class_info->verticalHeader()->hide();
        int sss = 0;


        QSqlQuery q_give_students_from_this_class("SELECT * FROM "+remove_cid_charecters+";");
        QString space_between_student_data = "\t\t";
        while(q_give_students_from_this_class.next())
        {

            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 0, new QTableWidgetItem(q_give_students_from_this_class.value("cp0").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 1, new QTableWidgetItem(q_give_students_from_this_class.value("cp1").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 2, new QTableWidgetItem(q_give_students_from_this_class.value("cp2").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 3, new QTableWidgetItem(q_give_students_from_this_class.value("cp3").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 4, new QTableWidgetItem(q_give_students_from_this_class.value("cp4").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 5, new QTableWidgetItem(q_give_students_from_this_class.value("cp5").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 6, new QTableWidgetItem(q_give_students_from_this_class.value("cp6").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 7, new QTableWidgetItem(q_give_students_from_this_class.value("cp7").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 8, new QTableWidgetItem(q_give_students_from_this_class.value("cp8").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 9, new QTableWidgetItem(q_give_students_from_this_class.value("cp9").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 10, new QTableWidgetItem(q_give_students_from_this_class.value("cp10").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 11, new QTableWidgetItem(q_give_students_from_this_class.value("cp11").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 12, new QTableWidgetItem(q_give_students_from_this_class.value("cp12").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 13, new QTableWidgetItem(q_give_students_from_this_class.value("cp13").toString()));
            ui->tableWidget_list_of_sutdents_for_show_to_class_info->setItem(sss, 14, new QTableWidgetItem(q_give_students_from_this_class.value("cp14").toString()));
            sss++;
        }
        ui->groupBox_show_class_info->show();
//    }
//    else
//    {
//        QMessageBox::critical(this," ","هیچ کلاسی انتخاب نشده است.");
//    }
}

void MainWindow::on_btn_search_class_from_home_clicked()
{
    ui->groupBox_login->hide();
    ui->groupBox_hs_register->hide();   ui->groupBox_hs_search_for_edit->hide();
    ui->groupBox_show_users_hs->hide(); ui->groupBox_hs_user_information->hide();
    ui->groupBox_home->hide();    ui->groupBox_settings->hide();
    ui->groupBox_search_hs_users->hide();
    ui->groupBox_search_result->hide();
    ui->groupBox_create_class->hide();
    ui->groupBox_show_class_info->hide();
    ui->groupBox_class_list->hide();
    ui->groupBox_question_select_one_part_for_edit_class->hide();
    ui->groupBox_edit_this_class->hide();
    ui->groupBox_edit_student_from_this_class->hide();
    ui->groupBox_edit_form_stu_from_class->hide();
    ui->groupBox_student_register->hide();
    ui->groupBox_show_students_list->hide();
    ui->groupBox_student_information->hide();
    ui->groupBox_qustion_add_student_to_this_class_by->hide();
    ui->groupBox_insert_more_data_to_student_for_this_class->hide();
    ui->groupBox_result_search_class->hide();

    ui->groupBox_search_on_class->show();
    QSqlQuery q_give_ci_texts_for_insert_to_check_boxs("SELECT * FROM t_class_info;");
    while(q_give_ci_texts_for_insert_to_check_boxs.next())
    {
        ui->cbox_search_class_ci_0->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cid").toString());
        ui->cbox_search_class_ci_1->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo0").toString());
        ui->cbox_search_class_ci_2->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo1").toString());
        ui->cbox_search_class_ci_3->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo2").toString());
        ui->cbox_search_class_ci_4->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo3").toString());
        ui->cbox_search_class_ci_5->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo4").toString());
        ui->cbox_search_class_ci_6->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo5").toString());
        ui->cbox_search_class_ci_7->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo6").toString());
        ui->cbox_search_class_ci_8->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo7").toString());
        ui->cbox_search_class_ci_9->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo8").toString());
        ui->cbox_search_class_ci_10->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo9").toString());
        ui->cbox_search_class_ci_11->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo10").toString());
        ui->cbox_search_class_ci_12->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo11").toString());
        ui->cbox_search_class_ci_13->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo12").toString());
        ui->cbox_search_class_ci_14->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo13").toString());
        //ui->cbox_search_class_ci_15->setText(q_give_ci_texts_for_insert_to_check_boxs.value("t_cinfo14").toString());

    }
    ui->cbox_search_class_select_all->setText("همه فعال");
    bool status_of_search_rbtn_select_all = true;
    ui->cbox_search_class_select_all->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_0->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_1->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_2->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_3->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_4->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_5->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_6->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_7->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_8->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_9->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_10->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_11->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_12->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_13->setDisabled(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_14->setChecked(status_of_search_rbtn_select_all);
//    ui->cbox_search_class_ci_15->setChecked(status_of_search_rbtn_select_all);
    ui->cbox_search_class_ci_15->hide();
}

void MainWindow::on_class_edit_triggered()
{

}

void MainWindow::on_btn_set_student_title_clicked()
{
    ui->groupBox_side_left_forms->hide();
    ui->groupBox_side_right_forms->hide();
    ui->btn_return_to_home_from_settings_form->hide();
    ui->groupBox_change_student_titles->show();
    ui->scrollArea_change_student_titles->ensureVisible(0,0,0,0);
    QSqlQuery q_give_student_titles("SELECT * FROM studentTitles;");
    while(q_give_student_titles.next())
    {
        ui->txt_student_title_0->setText(q_give_student_titles.value("st0").toString());
        ui->txt_student_title_1->setText(q_give_student_titles.value("st1").toString());
        ui->txt_student_title_2->setText(q_give_student_titles.value("st0").toString());
        ui->txt_student_title_3->setText(q_give_student_titles.value("st3").toString());
        ui->txt_student_title_4->setText(q_give_student_titles.value("st4").toString());
        ui->txt_student_title_5->setText(q_give_student_titles.value("st5").toString());
        ui->txt_student_title_6->setText(q_give_student_titles.value("st6").toString());
        ui->txt_student_title_7->setText(q_give_student_titles.value("st7").toString());
        ui->txt_student_title_8->setText(q_give_student_titles.value("st8").toString());
        ui->txt_student_title_9->setText(q_give_student_titles.value("st9").toString());
        ui->txt_student_title_10->setText(q_give_student_titles.value("st10").toString());
        ui->txt_student_title_11->setText(q_give_student_titles.value("st11").toString());
        ui->txt_student_title_12->setText(q_give_student_titles.value("st12").toString());
        ui->txt_student_title_13->setText(q_give_student_titles.value("st13").toString());
        ui->txt_student_title_14->setText(q_give_student_titles.value("st14").toString());
        ui->txt_student_title_15->setText(q_give_student_titles.value("st15").toString());
        ui->txt_student_title_16->setText(q_give_student_titles.value("st16").toString());
        ui->txt_student_title_17->setText(q_give_student_titles.value("st17").toString());
        ui->txt_student_title_18->setText(q_give_student_titles.value("st18").toString());
        ui->txt_student_title_19->setText(q_give_student_titles.value("st19").toString());
        ui->txt_student_title_20->setText(q_give_student_titles.value("st20").toString());
        ui->txt_student_title_21->setText(q_give_student_titles.value("st21").toString());
        ui->txt_student_title_22->setText(q_give_student_titles.value("st22").toString());
        ui->txt_student_title_23->setText(q_give_student_titles.value("st23").toString());
        ui->txt_student_title_24->setText(q_give_student_titles.value("st24").toString());
        ui->txt_student_title_25->setText(q_give_student_titles.value("st25").toString());
        ui->txt_student_title_26->setText(q_give_student_titles.value("st26").toString());
        ui->txt_student_title_27->setText(q_give_student_titles.value("st27").toString());
        ui->txt_student_title_28->setText(q_give_student_titles.value("st28").toString());
        ui->txt_student_title_29->setText(q_give_student_titles.value("st29").toString());

    }
}

void MainWindow::on_btn_cancel_return_to_sides_from_change_student_title_clicked()
{
    ui->groupBox_change_student_titles->hide();
    ui->groupBox_side_left_forms->show();
    ui->groupBox_side_right_forms->show();
    ui->btn_return_to_home_from_settings_form->show();
}

void MainWindow::on_btn_save_and_edit_student_titles_clicked()
{
    QSqlQuery q_update_student_titles("UPDATE studentTitles SET st0='"+ui->txt_student_title_0->text()+"', st1='"+ui->txt_student_title_1->text()+"', st2='"+ui->txt_student_title_2->text()+"', st3='"+ui->txt_student_title_3->text()+"', st4='"+ui->txt_student_title_4->text()+"', st5='"+ui->txt_student_title_5->text()+"', st6='"+ui->txt_student_title_6->text()+"', st7='"+ui->txt_student_title_7->text()+"', st8='"+ui->txt_student_title_8->text()+"', st9='"+ui->txt_student_title_9->text()+"', st10='"+ui->txt_student_title_10->text()+"', st11='"+ui->txt_student_title_11->text()+"', st12='"+ui->txt_student_title_12->text()+"', st13='"+ui->txt_student_title_13->text()+"', st14='"+ui->txt_student_title_14->text()+"', st15='"+ui->txt_student_title_15->text()+"', st16='"+ui->txt_student_title_16->text()+"', st17='"+ui->txt_student_title_17->text()+"', st18='"+ui->txt_student_title_18->text()+"', st19='"+ui->txt_student_title_19->text()+"', st20='"+ui->txt_student_title_20->text()+"', st21='"+ui->txt_student_title_21->text()+"', st22='"+ui->txt_student_title_22->text()+"', st23='"+ui->txt_student_title_23->text()+"', st24='"+ui->txt_student_title_24->text()+"', st25='"+ui->txt_student_title_25->text()+"', st26='"+ui->txt_student_title_26->text()+"', st27='"+ui->txt_student_title_27->text()+"', st28='"+ui->txt_student_title_28->text()+"', st29='"+ui->txt_student_title_29->text()+"';");
    QMessageBox::information(this," ","عنوان های فرم دانش آموز با موفیقت ویرایش شد");
    ui->groupBox_change_student_titles->hide();
    ui->groupBox_side_left_forms->show();
    ui->groupBox_side_right_forms->show();
    ui->btn_return_to_home_from_settings_form->show();
}

void MainWindow::on_btn_retrun_to_home_from_search_class_clicked()
{
    ui->groupBox_search_on_class->hide();
    ui->groupBox_home->show();
}

void MainWindow::on_btn_change_table_title_search_result_clicked()
{
    ui->groupBox_change_tbl_title->setTitle("جدول نتیجه جستجو حسینیه/دانش آموز");
    ui->groupBox_change_headers->hide();
    ui->scrollArea_change_tlb_titles->ensureVisible(0,0,0,0);
    ui->groupBox_change_tbl_title->show();
    ui->txt_tbl_t_0->show(); ui->txt_tbl_t_10->hide(); ui->txt_tbl_t_20->hide();
    ui->txt_tbl_t_1->show(); ui->txt_tbl_t_11->hide(); ui->txt_tbl_t_21->hide();
    ui->txt_tbl_t_2->show(); ui->txt_tbl_t_12->hide(); ui->txt_tbl_t_22->hide();
    ui->txt_tbl_t_3->show(); ui->txt_tbl_t_13->hide(); ui->txt_tbl_t_23->hide();
    ui->txt_tbl_t_4->hide(); ui->txt_tbl_t_14->hide(); ui->txt_tbl_t_24->hide();
    ui->txt_tbl_t_5->hide(); ui->txt_tbl_t_15->hide(); ui->txt_tbl_t_25->hide();
    ui->txt_tbl_t_6->hide(); ui->txt_tbl_t_16->hide(); ui->txt_tbl_t_26->hide();
    ui->txt_tbl_t_7->hide(); ui->txt_tbl_t_17->hide(); ui->txt_tbl_t_27->hide();
    ui->txt_tbl_t_8->hide(); ui->txt_tbl_t_18->hide(); ui->txt_tbl_t_28->hide();
    ui->txt_tbl_t_9->hide(); ui->txt_tbl_t_19->hide(); ui->txt_tbl_t_29->hide();

    QSqlQuery q_give_headers_for_load_to_edit("SELECT * FROM headers;");
    while(q_give_headers_for_load_to_edit.next())
    {
        ui->txt_tbl_t_0->setText(q_give_headers_for_load_to_edit.value("sr0").toString());
        ui->txt_tbl_t_1->setText(q_give_headers_for_load_to_edit.value("sr1").toString());
        ui->txt_tbl_t_2->setText(q_give_headers_for_load_to_edit.value("sr2").toString());
        ui->txt_tbl_t_3->setText(q_give_headers_for_load_to_edit.value("sr3").toString());
    }
}

void MainWindow::on_btn_change_tbl_title_stu_score_clicked()
{
    ui->groupBox_change_tbl_title->setTitle("جدول نمرات");
    ui->groupBox_change_headers->hide();
    ui->scrollArea_change_tlb_titles->ensureVisible(0,0,0,0);
    ui->groupBox_change_tbl_title->show();
    ui->txt_tbl_t_0->show(); ui->txt_tbl_t_10->show(); ui->txt_tbl_t_20->show();
    ui->txt_tbl_t_1->show(); ui->txt_tbl_t_11->show(); ui->txt_tbl_t_21->show();
    ui->txt_tbl_t_2->show(); ui->txt_tbl_t_12->show(); ui->txt_tbl_t_22->show();
    ui->txt_tbl_t_3->show(); ui->txt_tbl_t_13->show(); ui->txt_tbl_t_23->show();
    ui->txt_tbl_t_4->show(); ui->txt_tbl_t_14->show(); ui->txt_tbl_t_24->show();
    ui->txt_tbl_t_5->show(); ui->txt_tbl_t_15->show(); ui->txt_tbl_t_25->show();
    ui->txt_tbl_t_6->show(); ui->txt_tbl_t_16->show(); ui->txt_tbl_t_26->show();
    ui->txt_tbl_t_7->show(); ui->txt_tbl_t_17->show(); ui->txt_tbl_t_27->show();
    ui->txt_tbl_t_8->show(); ui->txt_tbl_t_18->show(); ui->txt_tbl_t_28->show();
    ui->txt_tbl_t_9->show(); ui->txt_tbl_t_19->show(); ui->txt_tbl_t_29->show();

    QSqlQuery q_give_headers_for_load_to_edit("SELECT * FROM headers;");
    while(q_give_headers_for_load_to_edit.next())
    {
        ui->txt_tbl_t_0->setText(q_give_headers_for_load_to_edit.value("s0").toString());
        ui->txt_tbl_t_1->setText(q_give_headers_for_load_to_edit.value("s1").toString());
        ui->txt_tbl_t_2->setText(q_give_headers_for_load_to_edit.value("s2").toString());
        ui->txt_tbl_t_3->setText(q_give_headers_for_load_to_edit.value("s3").toString());
        ui->txt_tbl_t_4->setText(q_give_headers_for_load_to_edit.value("s4").toString());
        ui->txt_tbl_t_5->setText(q_give_headers_for_load_to_edit.value("s5").toString());
        ui->txt_tbl_t_6->setText(q_give_headers_for_load_to_edit.value("s6").toString());
        ui->txt_tbl_t_7->setText(q_give_headers_for_load_to_edit.value("s7").toString());
        ui->txt_tbl_t_8->setText(q_give_headers_for_load_to_edit.value("s8").toString());
        ui->txt_tbl_t_9->setText(q_give_headers_for_load_to_edit.value("s9").toString());
        ui->txt_tbl_t_10->setText(q_give_headers_for_load_to_edit.value("s10").toString());
        ui->txt_tbl_t_11->setText(q_give_headers_for_load_to_edit.value("s11").toString());
        ui->txt_tbl_t_12->setText(q_give_headers_for_load_to_edit.value("s12").toString());
        ui->txt_tbl_t_13->setText(q_give_headers_for_load_to_edit.value("s13").toString());
        ui->txt_tbl_t_14->setText(q_give_headers_for_load_to_edit.value("s14").toString());
        ui->txt_tbl_t_15->setText(q_give_headers_for_load_to_edit.value("s15").toString());
        ui->txt_tbl_t_16->setText(q_give_headers_for_load_to_edit.value("s16").toString());
        ui->txt_tbl_t_17->setText(q_give_headers_for_load_to_edit.value("s17").toString());
        ui->txt_tbl_t_18->setText(q_give_headers_for_load_to_edit.value("s18").toString());
        ui->txt_tbl_t_19->setText(q_give_headers_for_load_to_edit.value("s19").toString());
        ui->txt_tbl_t_20->setText(q_give_headers_for_load_to_edit.value("s20").toString());
        ui->txt_tbl_t_21->setText(q_give_headers_for_load_to_edit.value("s21").toString());
        ui->txt_tbl_t_22->setText(q_give_headers_for_load_to_edit.value("s22").toString());
        ui->txt_tbl_t_23->setText(q_give_headers_for_load_to_edit.value("s23").toString());
        ui->txt_tbl_t_24->setText(q_give_headers_for_load_to_edit.value("s24").toString());
        ui->txt_tbl_t_25->setText(q_give_headers_for_load_to_edit.value("s25").toString());
        ui->txt_tbl_t_26->setText(q_give_headers_for_load_to_edit.value("s26").toString());
        ui->txt_tbl_t_27->setText(q_give_headers_for_load_to_edit.value("s27").toString());
        ui->txt_tbl_t_28->setText(q_give_headers_for_load_to_edit.value("s28").toString());
        ui->txt_tbl_t_29->setText(q_give_headers_for_load_to_edit.value("s29").toString());
    }
}

void MainWindow::on_btn_change_tbl_title_class_list_clicked()
{
    ui->groupBox_change_tbl_title->setTitle("جدول لیست کلاس");
    ui->groupBox_change_headers->hide();
    ui->scrollArea_change_tlb_titles->ensureVisible(0,0,0,0);
    ui->groupBox_change_tbl_title->show();
    ui->txt_tbl_t_0->show(); ui->txt_tbl_t_10->show(); ui->txt_tbl_t_20->hide();
    ui->txt_tbl_t_1->show(); ui->txt_tbl_t_11->show(); ui->txt_tbl_t_21->hide();
    ui->txt_tbl_t_2->show(); ui->txt_tbl_t_12->show(); ui->txt_tbl_t_22->hide();
    ui->txt_tbl_t_3->show(); ui->txt_tbl_t_13->show(); ui->txt_tbl_t_23->hide();
    ui->txt_tbl_t_4->show(); ui->txt_tbl_t_14->show(); ui->txt_tbl_t_24->hide();
    ui->txt_tbl_t_5->show(); ui->txt_tbl_t_15->show(); ui->txt_tbl_t_25->hide();
    ui->txt_tbl_t_6->show(); ui->txt_tbl_t_16->hide(); ui->txt_tbl_t_26->hide();
    ui->txt_tbl_t_7->show(); ui->txt_tbl_t_17->hide(); ui->txt_tbl_t_27->hide();
    ui->txt_tbl_t_8->show(); ui->txt_tbl_t_18->hide(); ui->txt_tbl_t_28->hide();
    ui->txt_tbl_t_9->show(); ui->txt_tbl_t_19->hide(); ui->txt_tbl_t_29->hide();

    QSqlQuery q_give_headers_for_load_to_edit("SELECT * FROM headers;");
    while(q_give_headers_for_load_to_edit.next())
    {
        ui->txt_tbl_t_0->setText(q_give_headers_for_load_to_edit.value("cl0").toString());
        ui->txt_tbl_t_1->setText(q_give_headers_for_load_to_edit.value("cl1").toString());
        ui->txt_tbl_t_2->setText(q_give_headers_for_load_to_edit.value("cl2").toString());
        ui->txt_tbl_t_3->setText(q_give_headers_for_load_to_edit.value("cl3").toString());
        ui->txt_tbl_t_4->setText(q_give_headers_for_load_to_edit.value("cl4").toString());
        ui->txt_tbl_t_5->setText(q_give_headers_for_load_to_edit.value("cl5").toString());
        ui->txt_tbl_t_6->setText(q_give_headers_for_load_to_edit.value("cl6").toString());
        ui->txt_tbl_t_7->setText(q_give_headers_for_load_to_edit.value("cl7").toString());
        ui->txt_tbl_t_8->setText(q_give_headers_for_load_to_edit.value("cl8").toString());
        ui->txt_tbl_t_9->setText(q_give_headers_for_load_to_edit.value("cl9").toString());
        ui->txt_tbl_t_10->setText(q_give_headers_for_load_to_edit.value("cl10").toString());
        ui->txt_tbl_t_11->setText(q_give_headers_for_load_to_edit.value("cl11").toString());
        ui->txt_tbl_t_12->setText(q_give_headers_for_load_to_edit.value("cl12").toString());
        ui->txt_tbl_t_13->setText(q_give_headers_for_load_to_edit.value("cl13").toString());
        ui->txt_tbl_t_14->setText(q_give_headers_for_load_to_edit.value("cl14").toString());
        ui->txt_tbl_t_15->setText(q_give_headers_for_load_to_edit.value("cl15").toString());
    }
}

void MainWindow::on_btn_change_tbl_title_search_result_class_clicked()
{
    ui->groupBox_change_tbl_title->setTitle("جدول نتیجه جستجو کلاس");
    ui->groupBox_change_headers->hide();
    ui->scrollArea_change_tlb_titles->ensureVisible(0,0,0,0);
    ui->groupBox_change_tbl_title->show();
    ui->txt_tbl_t_0->show(); ui->txt_tbl_t_10->hide(); ui->txt_tbl_t_20->hide();
    ui->txt_tbl_t_1->show(); ui->txt_tbl_t_11->hide(); ui->txt_tbl_t_21->hide();
    ui->txt_tbl_t_2->show(); ui->txt_tbl_t_12->hide(); ui->txt_tbl_t_22->hide();
    ui->txt_tbl_t_3->show(); ui->txt_tbl_t_13->hide(); ui->txt_tbl_t_23->hide();
    ui->txt_tbl_t_4->hide(); ui->txt_tbl_t_14->hide(); ui->txt_tbl_t_24->hide();
    ui->txt_tbl_t_5->hide(); ui->txt_tbl_t_15->hide(); ui->txt_tbl_t_25->hide();
    ui->txt_tbl_t_6->hide(); ui->txt_tbl_t_16->hide(); ui->txt_tbl_t_26->hide();
    ui->txt_tbl_t_7->hide(); ui->txt_tbl_t_17->hide(); ui->txt_tbl_t_27->hide();
    ui->txt_tbl_t_8->hide(); ui->txt_tbl_t_18->hide(); ui->txt_tbl_t_28->hide();
    ui->txt_tbl_t_9->hide(); ui->txt_tbl_t_19->hide(); ui->txt_tbl_t_29->hide();

    QSqlQuery q_give_headers_for_load_to_edit("SELECT * FROM headers;");
    while(q_give_headers_for_load_to_edit.next())
    {
        ui->txt_tbl_t_0->setText(q_give_headers_for_load_to_edit.value("src0").toString());
        ui->txt_tbl_t_1->setText(q_give_headers_for_load_to_edit.value("src1").toString());
        ui->txt_tbl_t_2->setText(q_give_headers_for_load_to_edit.value("src2").toString());
        ui->txt_tbl_t_3->setText(q_give_headers_for_load_to_edit.value("src3").toString());
    }
}

void MainWindow::on_btn_tbl_title_change_clicked()
{
    if(ui->groupBox_change_tbl_title->title() == "جدول نتیجه جستجو کلاس")
    {
       QSqlQuery update("UPDATE headers SET src0='"+ui->txt_tbl_t_0->text()+"',src1='"+ui->txt_tbl_t_1->text()+"',src2='"+ui->txt_tbl_t_2->text()+"',src3='"+ui->txt_tbl_t_3->text()+"';");
       QMessageBox::information(this," ","جدول نتیجه جستجو کلاس با موفقیت ویرایش شد.");
       ui->groupBox_change_tbl_title->hide();
       ui->groupBox_side_left_forms->show();
       ui->groupBox_side_right_forms->show();
    }
    else if(ui->groupBox_change_tbl_title->title() == "جدول لیست کلاس")
    {
        QSqlQuery update("UPDATE headers SET cl0='"+ui->txt_tbl_t_0->text()+"',cl1='"+ui->txt_tbl_t_1->text()+"',cl2='"+ui->txt_tbl_t_2->text()+"',cl3='"+ui->txt_tbl_t_3->text()+"',cl4='"+ui->txt_tbl_t_4->text()+"',cl5='"+ui->txt_tbl_t_5->text()+"',cl6='"+ui->txt_tbl_t_6->text()+"',cl7='"+ui->txt_tbl_t_7->text()+"',cl8='"+ui->txt_tbl_t_8->text()+"',cl9='"+ui->txt_tbl_t_9->text()+"',cl10='"+ui->txt_tbl_t_10->text()+"',cl11='"+ui->txt_tbl_t_11->text()+"',cl12='"+ui->txt_tbl_t_12->text()+"',cl13='"+ui->txt_tbl_t_13->text()+"',cl14='"+ui->txt_tbl_t_14->text()+"',cl15='"+ui->txt_tbl_t_15->text()+"';");
        QMessageBox::information(this," ","جدول لیست کلاس با موفقیت ویرایش شد.");
        ui->groupBox_change_tbl_title->hide();
        ui->groupBox_side_left_forms->show();
        ui->groupBox_side_right_forms->show();
    }
    else if(ui->groupBox_change_tbl_title->title() == "جدول نمرات")
    {
        QSqlQuery update("UPDATE headers SET s0='"+ui->txt_tbl_t_0->text()+"',s1='"+ui->txt_tbl_t_1->text()+"',s2='"+ui->txt_tbl_t_2->text()+"',s3='"+ui->txt_tbl_t_3->text()+"',s4='"+ui->txt_tbl_t_4->text()+"',s5='"+ui->txt_tbl_t_5->text()+"',s6='"+ui->txt_tbl_t_6->text()+"',s7='"+ui->txt_tbl_t_7->text()+"',s8='"+ui->txt_tbl_t_8->text()+"',s9='"+ui->txt_tbl_t_9->text()+"',s10='"+ui->txt_tbl_t_10->text()+"',s11='"+ui->txt_tbl_t_11->text()+"',s12='"+ui->txt_tbl_t_12->text()+"',s13='"+ui->txt_tbl_t_13->text()+"',s14='"+ui->txt_tbl_t_14->text()+"',s15='"+ui->txt_tbl_t_15->text()+"',s16='"+ui->txt_tbl_t_16->text()+"',s17='"+ui->txt_tbl_t_17->text()+"',s18='"+ui->txt_tbl_t_18->text()+"',s19='"+ui->txt_tbl_t_19->text()+"',s20='"+ui->txt_tbl_t_20->text()+"',s21='"+ui->txt_tbl_t_21->text()+"',s22='"+ui->txt_tbl_t_22->text()+"',s23='"+ui->txt_tbl_t_23->text()+"',s24='"+ui->txt_tbl_t_24->text()+"',s25='"+ui->txt_tbl_t_25->text()+"',s26='"+ui->txt_tbl_t_26->text()+"',s27='"+ui->txt_tbl_t_27->text()+"',s28='"+ui->txt_tbl_t_28->text()+"',s29='"+ui->txt_tbl_t_29->text()+"';");
        QMessageBox::information(this," ","جدول نمرات با موفقیت ویرایش شد.");
        ui->groupBox_change_tbl_title->hide();
        ui->groupBox_side_left_forms->show();
        ui->groupBox_side_right_forms->show();
    }
    else if(ui->groupBox_change_tbl_title->title() == "جدول نتیجه جستجو حسینیه/دانش آموز")
    {
        QSqlQuery update("UPDATE headers SET sr0='"+ui->txt_tbl_t_0->text()+"',sr1='"+ui->txt_tbl_t_1->text()+"',sr2='"+ui->txt_tbl_t_2->text()+"',sr3='"+ui->txt_tbl_t_3->text()+"';");
        QMessageBox::information(this," ","جدول نتیجه جستجو حسینیه/دانش آموز با موفقیت ویرایش شد.");
        ui->groupBox_change_tbl_title->hide();
        ui->groupBox_side_left_forms->show();
        ui->groupBox_side_right_forms->show();
    }
    QSqlQuery q_guve("SELECT * FROM headers;");
    while(q_guve.next())
    {
       ui->tableWidget_search_result->setHorizontalHeaderLabels(QString(q_guve.value("sr0").toString()+";"+q_guve.value("sr1").toString()+";"+q_guve.value("sr2").toString()+";"+q_guve.value("sr3").toString()+";").split(";"));
       ui->tableWidget_class_list->setHorizontalHeaderLabels(QString(q_guve.value("cl0").toString()+";"+q_guve.value("cl1").toString()+";"+q_guve.value("cl2").toString()+";"+q_guve.value("cl3").toString()+";"+q_guve.value("cl4").toString()+";"+q_guve.value("cl5").toString()+";"+q_guve.value("cl6").toString()+";"+q_guve.value("cl7").toString()+";"+q_guve.value("cl8").toString()+";"+q_guve.value("cl9").toString()+";"+q_guve.value("cl10").toString()+";"+q_guve.value("cl11").toString()+";"+q_guve.value("cl12").toString()+";"+q_guve.value("cl13").toString()+";"+q_guve.value("cl14").toString()+";"+q_guve.value("cl15").toString()+";").split(";"));
       ui->tableWidget_search_class_result->setHorizontalHeaderLabels(QString(q_guve.value("src0").toString()+";"+q_guve.value("src1").toString()+";"+q_guve.value("src2").toString()+";"+q_guve.value("src3").toString()+";").split(";"));
       ui->tableWidget_show_student_scores->setHorizontalHeaderLabels(QString(q_guve.value("s0").toString()+";"+q_guve.value("s1").toString()+";"+q_guve.value("s2").toString()+";"+q_guve.value("s3").toString()+";"+q_guve.value("s4").toString()+";"+q_guve.value("s5").toString()+";"+q_guve.value("s6").toString()+";"+q_guve.value("s7").toString()+";"+q_guve.value("s8").toString()+";"+q_guve.value("s9").toString()+";"+q_guve.value("s10").toString()+";"+q_guve.value("s11").toString()+";"+q_guve.value("s12").toString()+";"+q_guve.value("s13").toString()+";"+q_guve.value("s14").toString()+";"+q_guve.value("s15").toString()+";"+q_guve.value("s16").toString()+";"+q_guve.value("s17").toString()+";"+q_guve.value("s18").toString()+";"+q_guve.value("s19").toString()+";"+q_guve.value("s20").toString()+";"+q_guve.value("s21").toString()+";"+q_guve.value("s22").toString()+";"+q_guve.value("s23").toString()+";"+q_guve.value("s24").toString()+";"+q_guve.value("s25").toString()+";"+q_guve.value("s26").toString()+";"+q_guve.value("s27").toString()+";"+q_guve.value("s28").toString()+";"+q_guve.value("s29").toString()+";").split(";"));
    }
}
