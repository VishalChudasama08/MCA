INSERT INTO `employee` (`id`, `name`, `job_title`, `salary`, `status`, `created_at`, `updated_at`) VALUES
(1, 'John Doe', 'Software Engineer', 60000, '1', '2026-02-02 09:17:06', '2026-02-02 09:17:06'),
(2, 'Jane Smith', 'Project Manager', 75000, '1', '2026-02-02 09:17:06', '2026-02-02 09:17:06'),
(3, 'Michael Brown', 'UI/UX Designer', 55000, '2', '2026-02-02 09:17:06', '2026-02-02 09:17:06'),
(4, 'Emily Davis', 'HR Executive', 45000, '1', '2026-02-02 09:17:06', '2026-02-02 09:17:06'),
(5, 'Pratik', 'aaa', 100000, '2', '2026-02-02 04:59:46', '2026-02-02 04:59:46'),
(6, 'Vishal', 'devops', 800000, '1', '2026-02-02 05:00:07', '2026-02-02 05:00:07');

INSERT INTO products (p_name, p_price, p_qty, created_at, updated_at) VALUES
('Product 1', 10.99, 100, NOW(), NOW()),
('Product 2', 15.50, 80, NOW(), NOW()),
('Product 3', 7.25, 200, NOW(), NOW()),
('Product 4', 22.00, 60, NOW(), NOW()),
('Product 5', 18.75, 90, NOW(), NOW()),
('Product 6', 12.40, 150, NOW(), NOW()),
('Product 7', 30.00, 40, NOW(), NOW()),
('Product 8', 9.99, 300, NOW(), NOW()),
('Product 9', 45.00, 25, NOW(), NOW()),
('Product 10', 27.50, 70, NOW(), NOW()),
('Product 11', 5.99, 500, NOW(), NOW()),
('Product 12', 19.99, 110, NOW(), NOW());


INSERT INTO staff
(name, position, office, age, start_date, salary, image, created_at, updated_at)
VALUES
('Tiger Nixon','System Architect','Edinburgh',61,'2011-04-25',320800,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Garrett Winters','Accountant','Tokyo',63,'2011-07-25',170750,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Ashton Cox','Junior Technical Author','San Francisco',66,'2009-01-12',86000,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Cedric Kelly','Senior Javascript Developer','Edinburgh',22,'2012-03-29',433060,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Airi Satou','Accountant','Tokyo',33,'2008-11-28',162700,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Brielle Williamson','Integration Specialist','New York',61,'2012-12-02',372000,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Herrod Chandler','Sales Assistant','San Francisco',59,'2012-08-06',137500,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Rhona Davidson','Integration Specialist','Tokyo',55,'2010-10-14',327900,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Colleen Hurst','Javascript Developer','San Francisco',39,'2009-09-15',205500,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Sonya Frost','Software Engineer','Edinburgh',23,'2008-12-13',103600,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Jena Gaines','Office Manager','London',30,'2008-12-19',90560,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Quinn Flynn','Support Lead','Edinburgh',22,'2013-03-03',342000,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Charde Marshall','Regional Director','San Francisco',36,'2008-10-16',470600,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Haley Kennedy','Senior Marketing Designer','London',43,'2012-12-18',313500,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Tatyana Fitzpatrick','Regional Director','London',19,'2010-03-17',385750,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Michael Silva','Marketing Designer','London',66,'2012-11-27',198500,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Paul Byrd','Chief Financial Officer (CFO)','New York',64,'2010-06-09',725000,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Gloria Little','Systems Administrator','New York',59,'2009-04-10',237500,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Bradley Greer','Software Engineer','London',41,'2012-10-13',132000,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Dai Rios','Personnel Lead','Edinburgh',35,'2012-09-26',217500,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Jenette Caldwell','Development Lead','New York',30,'2011-09-03',345000,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Yuri Berry','Chief Marketing Officer (CMO)','New York',40,'2009-06-25',675000,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Caesar Vance','Pre-Sales Support','New York',21,'2011-12-12',106450,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Doris Wilder','Sales Assistant','Sidney',23,'2010-09-20',85600,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Angelica Ramos','Chief Executive Officer (CEO)','London',47,'2009-10-09',1200000,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Gavin Joyce','Developer','Edinburgh',42,'2010-12-22',92575,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Jennifer Chang','Regional Director','Singapore',28,'2010-11-14',357650,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Brenden Wagner','Software Engineer','San Francisco',28,'2011-06-07',206850,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Fiona Green','Chief Operating Officer (COO)','San Francisco',48,'2010-03-11',850000,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Shou Itou','Regional Marketing','Tokyo',20,'2011-08-14',163000,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Michelle House','Integration Specialist','Sidney',37,'2011-06-02',95400,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Suki Burks','Developer','London',53,'2009-10-22',114500,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Prescott Bartlett','Technical Author','London',27,'2011-05-07',145000,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Gavin Cortez','Team Leader','San Francisco',22,'2008-10-26',235500,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Martena Mccray','Post-Sales support','Edinburgh',46,'2011-03-09',324050,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Unity Butler','Marketing Designer','San Francisco',47,'2009-12-09',85675,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Howard Hatfield','Office Manager','San Francisco',51,'2008-12-16',164500,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Hope Fuentes','Secretary','San Francisco',41,'2010-02-12',109850,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Vivian Harrell','Financial Controller','San Francisco',62,'2009-02-14',452500,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Timothy Mooney','Office Manager','London',37,'2008-12-11',136200,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Jackson Bradshaw','Director','New York',65,'2008-09-26',645750,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Olivia Liang','Support Engineer','Singapore',64,'2011-02-03',234500,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Bruno Nash','Software Engineer','London',38,'2011-05-03',163500,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Sakura Yamamoto','Support Engineer','Tokyo',37,'2009-08-19',139575,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Thor Walton','Developer','New York',61,'2013-08-11',98540,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Finn Camacho','Support Engineer','San Francisco',47,'2009-07-07',87500,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Serge Baldwin','Data Coordinator','Singapore',64,'2012-04-09',138575,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Zenaida Frank','Software Engineer','New York',63,'2010-01-04',125250,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Zorita Serrano','Software Engineer','San Francisco',56,'2012-06-01',115000,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Jennifer Acosta','Junior Javascript Developer','Edinburgh',43,'2013-02-01',75650,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Cara Stevens','Sales Assistant','New York',46,'2011-12-06',145600,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Hermione Butler','Regional Director','London',47,'2011-03-21',356250,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Lael Greer','Systems Administrator','London',21,'2009-02-27',103500,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Jonas Alexander','Developer','San Francisco',30,'2010-07-14',86500,'../assets/images/users/d3.jpg',NOW(),NOW()),

('Shad Decker','Regional Director','Edinburgh',51,'2008-11-13',183000,'../assets/images/users/d1.jpg',NOW(),NOW()),
('Michael Bruce','Javascript Developer','Singapore',29,'2011-06-27',183000,'../assets/images/users/d2.jpg',NOW(),NOW()),
('Donna Snider','Customer Support','New York',27,'2011-01-25',112000,'../assets/images/users/d3.jpg',NOW(),NOW());
