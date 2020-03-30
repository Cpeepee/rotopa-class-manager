# management-app
Manage students/classs/members (unlimited).

This application created for manage students/classs/members of a unit.

Features of verion 1.0.0:
0 - can add unlimit members/students/class 
1 - change/insert your titles of forms parts 
          (students/classs/members/settings/tabs/window title/etc)
          
2 - search your members/student/class via select parameters
3 - create class with 15 class info (bio) & 15 class parameter unique
4 - edit student/class(class info-class parameters-class students)/members 
          (minus class id/student code/member code) 
          
5 - show classs student joined on student info (score or ... [parameters])
6 - backup your database/avatars to selected path 
          (ex name of directory: 'backup-thu-mar-02-2020')
          
7 - send sql command to database
8 - change username-password admin account
9 - show admin logins log (history with date)
10 - change max try to login / current try to login 
11 - Contains entry ceiling attempt admin account!
12 - Listing members/students/classes
13 - delete student/member
14 - Tried: Can be used for low systems
15 - select a defualt image for student/member defualt image 3x4 (format .jpg)
16 - change application window title [(dynamic (Whatever you want)] 
17 - change application icon with replace icon with name 'icon' (format .ico)
18 - change table (text header) titles.


More details:
Create user/student with 
             one 3x4 image (format .jpg)
             30 parameter (minus [National Code] & [Name & Family] & [Father name])
             
Create class with
             15 parameter for class info (bio class)
             15 parameter for (value of student titles in this class)

All members data saved at table (registration) and titles-member at table (registrationTitles)
All students data saved at table (students) and titles-student at table (studentTitles)
All classs listing at table (class_list)
when class create , create a table with name (cid_[number-last-class-from-adminconfig])
When student create , create a table with name (score_[student-code])
When student added to a class , insert class info + student parameters on that class to (score_[student-code])
When added image to student/member , copied selected file to ./avatar/[student-code].jpg 
    revers when delete member/student image deleted from ./avatar/
    
Don't forget the licenses, thanks.
