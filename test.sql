-- MySQL dump 10.13  Distrib 5.1.62, for mandriva-linux-gnu (i586)
--
-- Host: localhost    Database: test
-- ------------------------------------------------------
-- Server version	5.1.62

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `mlsn87_users`
--

USE test;

DROP TABLE IF EXISTS `mlsn87_users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mlsn87_users` (
  `customer_id` mediumint(8) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `first` varchar(255) DEFAULT NULL,
  `last` varchar(255) DEFAULT NULL,
  `address` varchar(255) DEFAULT NULL,
  `zip` varchar(10) DEFAULT NULL,
  `phone` varchar(100) DEFAULT NULL,
  `cc` varchar(17) DEFAULT NULL,
  `cc_type` varchar(8) DEFAULT NULL,
  PRIMARY KEY (`customer_id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mlsn87_users`
--

LOCK TABLES `mlsn87_users` WRITE;
/*!40000 ALTER TABLE `mlsn87_users` DISABLE KEYS */;
INSERT INTO `mlsn87_users` VALUES (1,'mlsn87','Junk123','Mike','Stotts','9555 Jones Creek','63023','636-285-4122','99999-000-0000','Visa'),(2,'jorgeg','A111111','jorge','Garcia','','','','','');
/*!40000 ALTER TABLE `mlsn87_users` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mlsn87_orders`
--

DROP TABLE IF EXISTS `mlsn87_orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mlsn87_orders` (
  `order_id` mediumint(8) unsigned NOT NULL AUTO_INCREMENT,
  `date` date DEFAULT NULL,
  `customer_id` mediumint(8) DEFAULT NULL,
  `french` decimal(10,0) DEFAULT NULL,
  `hazlenut` decimal(10,0) DEFAULT NULL,
  `colombian` decimal(10,0) DEFAULT NULL,
  PRIMARY KEY (`order_id`)
) ENGINE=MyISAM AUTO_INCREMENT=28 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mlsn87_orders`
--

LOCK TABLES `mlsn87_orders` WRITE;
/*!40000 ALTER TABLE `mlsn87_orders` DISABLE KEYS */;
INSERT INTO `mlsn87_orders` VALUES (22,'2012-05-11',1,'1','1','1'),(23,'2012-05-11',1,'9','2','3'),(24,'2012-05-11',2,'133','12','0'),(25,'2012-05-11',1,'1','0','0'),(26,'2012-05-11',1,'0','1','0'),(27,'2012-05-11',1,'0','0','1');
/*!40000 ALTER TABLE `mlsn87_orders` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-05-11 21:17:20
