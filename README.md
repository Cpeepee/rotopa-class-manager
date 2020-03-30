# management-app
Manage students/classs/members (unlimited).

This application created for manage students/classs/members of a unit.

Technical Specifications:
- Version 1.0.0 [Stable]
- Database used sqlite (can use 'DB Browser for SQLite' this is open-source sqlite database editor).
- Compiled via minGW-32bit, C++11.
- Licenses: LGPL version 3, GPL version 2 and GPL version 3.
- Made by Qt Creator 4.11.1 [Based on Qt 5.14.1 (MSVC 2017,32bit)



Features of verion 1.0.0:

 - can add unlimit members/students/classs
 - change/insert your titles of forms parts 
          (students/classs/members/settings/tabs/window title/etc)
          
 - search your members/student/class via select parameters
 - create class with 15 class info (bio) & 15 class parameter unique
 
 - edit student/class(class info-class parameters-class students)/members 
          (minus class id/student code/member code) 
          
 - show classs student joined on student info (score or ... [parameters])
 
 - backup your database/avatars to selected path 
          (ex name of directory: 'backup-thu-mar-02-2020')
          
 - send sql command to database
 
 - change username-password admin account
 
 - show admin logins log (history with date)
 
 - change max try to login / current try to login 
 
 - Contains entry ceiling attempt admin account!
 
 - Listing members/students/classes
 
 - delete student/member

 - Tried: Can be used for low systems
 
 - select a defualt image for student/member defualt image 3x4 (format .jpg)
 
 - change application window title [(dynamic (Whatever you want)] 
 
 - change application icon with replace icon with name 'icon' (format .ico)
 
 - change table (text header) titles.



More details:
- Create user/student with 
             one 3x4 image (format .jpg)
             30 parameter (minus [National Code] & [Name & Family] & [Father name])
             
- Create class with
             15 parameter for class info (bio class)
             15 parameter for (value of student titles in this class)

- All members data saved at table (registration) and titles-member at table (registrationTitles)
- All students data saved at table (students) and titles-student at table (studentTitles)
- All classs listing at table (class_list)
- when class create , create a table with name (cid_ [number-last-class-from-adminconfig])
- When student create , create a table with name (score_ [student-code])
- When student added to a class , insert class info + student parameters on that class to (score_ student-code])
- When added image to student/member , copied selected file to ./avatar/[student-code].jpg 
   revers when delete member/student image deleted from ./avatar/
- All history admin logins saving at table (adminloginslog)
- All admin configs username - password - maxtry etc saving at table (adminconfig)
- All tab Titles saved at table (tabTitles)
- All table headers saved at table (headers)

 
 
Don't forget the licenses, thanks.
