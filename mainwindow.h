#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_register_clear_clicked();

    void on_btn_register_insert_clicked();

    void on_hs_register_triggered();

    void on_hs_edit_triggered();

    void on_btn_hs_search_for_edit_clicked();

    void on_btn_register_avatar_clicked();

    void on_btn_login_clicked();

    void on_btn_show_users_hs_clicked();

    void on_hs_list_users_triggered();

    void on_btn_hs_userinfo_return_to_users_list_clicked();

    void on_btn_hs_userinfo_edit_user_clicked();

    void on_btn_edit_goto_delete_this_user_clicked();

    void on_btn_change_user_pass_admin_clicked();

    void on_btn_next_to_changeuserpass_clicked();

    void on_btn_cancel_to_changeuserpass_clicked();

    void on_btn_change_maxtry_login_clicked();

    void on_btn_edit_and_save_maxtry_clicked();

    void on_btn_cancel_maxtry_clicked();

    void on_btn_change_currenttry_login_clicked();

    void on_btn_edit_and_save_currenttry_clicked();

    void on_btn_cancel_currenttry_clicked();

    void on_btn_change_path_defualt_avatar_of_user_clicked();

    void on_btn_edit_and_save_avatar_path_change_clicked();

    void on_btn_cancel_avatar_path_change_clicked();

    void on_btn_show_adminloginslog_from_config_clicked();

    void on_btn_exit_from_hisotry_adminloginslog_clicked();

    void on_btn_return_home_from_config_clicked();

    void on_action_settings_and_configuration_triggered();

    void on_btn_restore_all_tbls_clicked();

    void on_btn_info_database_clicked();

    void on_btn_cmd_to_database_clicked();

    void on_btn_send_cmd_to_db_clicked();

    void on_btn_cancel_send_cmd_to_db_clicked();

    void on_btn_settings_of_backup_database_clicked();

    void on_btn_cancel_db_edit_backup_settings_clicked();

    void on_btn_add_new_path_for_backup_database_clicked();

    void on_btn_open_path_of_db_clicked();

    void on_btn_edit_db_edit_backup_settings_clicked();

    void on_btn_give_backup_now_clicked();

    void on_btn_return_to_home_clicked();

    void on_btn_return_to_home_from_settings_form_clicked();

    void on_btn_hs_set_title_clicked();

    void on_btn_cancel_edit_titles_hs_clicked();

    void on_btn_submit_edit_titles_hs_clicked();

    void on_cbox_stats_disable_all_stateChanged(int);

    void on_cbox_stats_disable_0_stateChanged(int arg1);

    void on_cbox_stats_disable_1_stateChanged(int arg1);

    void on_cbox_stats_disable_2_stateChanged(int arg1);

    void on_cbox_stats_disable_3_stateChanged(int arg1);

    void on_cbox_stats_disable_4_stateChanged(int arg1);

    void on_cbox_stats_disable_5_stateChanged(int arg1);

    void on_cbox_stats_disable_6_stateChanged(int arg1);

    void on_cbox_stats_disable_7_stateChanged(int arg1);

    void on_cbox_stats_disable_8_stateChanged(int arg1);

    void on_cbox_stats_disable_9_stateChanged(int arg1);

    void on_cbox_stats_disable_10_stateChanged(int arg1);

    void on_cbox_stats_disable_11_stateChanged(int arg1);

    void on_cbox_stats_disable_12_stateChanged(int arg1);

    void on_cbox_stats_disable_13_stateChanged(int arg1);

    void on_cbox_stats_disable_14_stateChanged(int arg1);

    void on_cbox_stats_disable_15_stateChanged(int arg1);

    void on_cbox_stats_disable_16_stateChanged(int arg1);

    void on_cbox_stats_disable_17_stateChanged(int arg1);

    void on_cbox_stats_disable_18_stateChanged(int arg1);

    void on_cbox_stats_disable_19_stateChanged(int arg1);

    void on_cbox_stats_disable_20_stateChanged(int arg1);

    void on_cbox_stats_disable_21_stateChanged(int arg1);

    void on_cbox_stats_disable_22_stateChanged(int arg1);

    void on_cbox_stats_disable_23_stateChanged(int arg1);

    void on_cbox_stats_disable_24_stateChanged(int arg1);

    void on_cbox_stats_disable_25_stateChanged(int arg1);

    void on_cbox_stats_disable_26_stateChanged(int arg1);

    void on_cbox_stats_disable_27_stateChanged(int arg1);

    void on_cbox_stats_disable_28_stateChanged(int arg1);

    void on_cbox_stats_disable_29_stateChanged(int arg1);

    void on_btn_hs_return_to_home_clicked();

    void on_action_about_application_triggered();

    void on_btn_goto_settings_from_home_clicked();

    void on_btn_list_of_hs_from_home_clicked();

    void on_btn_register_user_hs_from_home_clicked();

    void on_btb_change_window_title_clicked();

    void on_btn_window_title_text_to_edit_clicked();

    void on_btn_window_title_to_cancel_clicked();

    void on_btn_change_tabTitle_settings_clicked();

    void on_btn_cancel_changes_tabTitles_clicked();

    void on_btn_save_changes_tabTitles_clicked();

    void on_btn_reset_adminconfig_clicked();

    void on_btn_reset_adminloginslog_clicked();

    void on_btn_reset_hs_users_clicked();

    void on_btn_reset_hs_titles_clicked();

    void on_btn_reset_tabTitles_clicked();

    void on_btn_cancel_from_resetfactory_clicked();

    void on_hs_search_triggered();
    
    void on_btn_cancel_search_from_hs_users_clicked();
    
    void on_btn_go_search_from_hs_users_clicked();
    
    void on_cbox_select_all_stateChanged(int arg1);

    void on_btn_goto_this_user_from_search_result_clicked();

    void on_btn_cancel_from_search_result_clicked();

    void on_class_create_triggered();

    void on_btn_cancel_class_clicked();

    void on_btn_save_class_clicked();

    void on_btn_set_class_titles_clicked();

    void on_btn_save_change_titles_class_clicked();

    void on_btn_cancel_change_titles_class_clicked();

    void on_class_list_triggered();

    void on_btn_cancel_from_class_list_clicked();

    void on_btn_change_title_class_list_clicked();

    void on_btn_show_this_class_clicked();

//    void on_btn_change_score_this_student_in_this_class_clicked();

//    void on_btn_save_score_for_this_student_clicked();

//    void on_btn_cancel_score_for_this_student_clicked();

    void on_btn_goto_edit_this_class_clicked();

//    void on_class_edit_triggered();

    void on_btn_return_to_class_list_clicked();

    void on_btn_cancel_score_for_this_student_clicked();

    void on_btn_edit_the_info_this_class_clicked();

    void on_btn_edit_the_parameters_this_class_clicked();

    void on_btn_edit_the_students_this_class_clicked();

    void on_btn_cancel_this_class_edit_clicked();

    void on_btn_save_this_class_edit_clicked();

    void on_btn_cancel_edit_student_from_this_class_clicked();

    void on_btn_edit_this_student_from_this_class_clicked();

    void on_btn_cancel_form_stu_from_class_clicked();

    void on_btn_edit_form_stu_from_class_ok_clicked();

    void on_btn_cancel_edit_this_class_from_this_cid_clicked();

    void on_student_new_triggered();

    void on_btn_student_register_avatar_clicked();

    void on_btn_cancel_student_register_clicked();

    void on_btn_submit_student_register_clicked();

    void on_btn_cancel_from_stu_list_clicked();

    void on_btn_show_this_student_from_stu_list_clicked();

    void on_student_list_triggered();

    void on_btn_student_info_edit_stu_clicked();

    void on_btn_return_2_student_list_from_stu_info_clicked();

    void on_btn_edit_goto_delete_this_student_clicked();

    void on_btn_cancel_and_return_to_home_clicked();

    void on_btn_add_student_to_class_by_student_list_clicked();

    void on_btn_save_data_to_this_student_on_this_class_clicked();

    void on_btn_cancel_and_return_to_home_2_clicked();

    void on_class_search_triggered();

    void on_student_search_triggered();

    void on_btn_add_more_students_to_this_classs_clicked();

    void on_btn_add_student_to_class_by_searching_clicked();

    void on_pushButton_clicked();

    void on_btn_change_text_headers_clicked();

    void on_btn_return_to_main_forms_sides_from_change_headers_clicked();

    void on_btn_change_header_stu_hs_clicked();

    void on_btn_change_header_search_result_stu_hs_clicked();

    void on_btn_list_of_class_from_home_clicked();

    void on_btn_creatE_class_from_home_clicked();

    void on_btn_students_list_from_home_clicked();

    void on_btn_create_new_student_from_home_clicked();

    void on_btn_search_students_from_home_clicked();

    void on_btn_search_user_hs_from_home_clicked();

    void on_cbox_search_class_select_all_stateChanged(int arg1);

    void on_btn_go_search_on_class_clicked();

    void on_btn_change_and_save_header_search_class_clicked();

    void on_btn_return_to_home_from_search_result_class_clicked();

    void on_btn_show_this_class_from_search_result_class_clicked();

    void on_btn_search_class_from_home_clicked();

    void on_class_edit_triggered();

    void on_btn_set_student_title_clicked();

    void on_btn_cancel_return_to_sides_from_change_student_title_clicked();

    void on_btn_save_and_edit_student_titles_clicked();

    void on_btn_retrun_to_home_from_search_class_clicked();

    void on_btn_change_table_title_search_result_clicked();

    void on_btn_change_tbl_title_stu_score_clicked();

    void on_btn_change_tbl_title_class_list_clicked();

    void on_btn_change_tbl_title_search_result_class_clicked();

    void on_btn_tbl_title_change_clicked();

private:
    Ui::MainWindow *ui;

protected:
    void keyPressEvent(QKeyEvent *keyLogin);
};
#endif // MAINWINDOW_H
