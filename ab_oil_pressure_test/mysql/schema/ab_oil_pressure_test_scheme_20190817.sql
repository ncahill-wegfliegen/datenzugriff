CREATE DATABASE  IF NOT EXISTS `ab_oil_pressure_test` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `ab_oil_pressure_test`;
-- MySQL dump 10.13  Distrib 8.0.17, for Win64 (x86_64)
--
-- Host: localhost    Database: ab_oil_pressure_test
-- ------------------------------------------------------
-- Server version	8.0.17

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `field_pool`
--

DROP TABLE IF EXISTS `field_pool`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `field_pool` (
  `location_exception` char(2) NOT NULL,
  `legal_subdivision` int(2) NOT NULL,
  `section` int(2) NOT NULL,
  `township` int(3) NOT NULL,
  `range` int(2) NOT NULL,
  `meridian` int(1) NOT NULL,
  `event_sequence` char(1) NOT NULL,
  `consol_interval_num` int(2) NOT NULL,
  `field_name` varchar(20) DEFAULT NULL,
  `pool_name` varchar(21) DEFAULT NULL,
  PRIMARY KEY (`location_exception`,`legal_subdivision`,`section`,`township`,`range`,`meridian`,`event_sequence`,`consol_interval_num`),
  CONSTRAINT `fk_field_pool_well_id_consol_interval_num` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`),
  CONSTRAINT `fk_field_pool_well_id_event_sequence` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`),
  CONSTRAINT `fk_field_pool_well_id_legal_subdivision` FOREIGN KEY (`location_exception`, `legal_subdivision`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`),
  CONSTRAINT `fk_field_pool_well_id_location_exception` FOREIGN KEY (`location_exception`) REFERENCES `well_id` (`location_exception`),
  CONSTRAINT `fk_field_pool_well_id_meridian` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`),
  CONSTRAINT `fk_field_pool_well_id_range` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`),
  CONSTRAINT `fk_field_pool_well_id_section` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`),
  CONSTRAINT `fk_field_pool_well_id_township` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `field_pool`
--

LOCK TABLES `field_pool` WRITE;
/*!40000 ALTER TABLE `field_pool` DISABLE KEYS */;
/*!40000 ALTER TABLE `field_pool` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `licensee`
--

DROP TABLE IF EXISTS `licensee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `licensee` (
  `location_exception` char(2) NOT NULL,
  `legal_subdivision` int(2) NOT NULL,
  `section` int(2) NOT NULL,
  `township` int(3) NOT NULL,
  `range` int(2) NOT NULL,
  `meridian` int(1) NOT NULL,
  `event_sequence` char(1) NOT NULL,
  `consol_interval_num` int(2) NOT NULL,
  `licensee_code` varchar(5) DEFAULT NULL,
  `licensee_abbrev` varchar(14) DEFAULT NULL,
  `survey_coord_oper_code` varchar(4) DEFAULT NULL,
  `survey_coord_abbrev` varchar(14) DEFAULT NULL,
  `well_status_date` date DEFAULT NULL,
  `well_status_code` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`location_exception`,`legal_subdivision`,`section`,`township`,`range`,`meridian`,`event_sequence`,`consol_interval_num`),
  CONSTRAINT `fk_licensee_well_id_consol_interval_num` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`),
  CONSTRAINT `fk_licensee_well_id_event_sequence` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`),
  CONSTRAINT `fk_licensee_well_id_legal_subdivision` FOREIGN KEY (`location_exception`, `legal_subdivision`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`),
  CONSTRAINT `fk_licensee_well_id_location_exception` FOREIGN KEY (`location_exception`) REFERENCES `well_id` (`location_exception`),
  CONSTRAINT `fk_licensee_well_id_merdian` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`),
  CONSTRAINT `fk_licensee_well_id_range` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`),
  CONSTRAINT `fk_licensee_well_id_section` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`),
  CONSTRAINT `fk_licensee_well_id_township` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Licensee and Well Status';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `licensee`
--

LOCK TABLES `licensee` WRITE;
/*!40000 ALTER TABLE `licensee` DISABLE KEYS */;
/*!40000 ALTER TABLE `licensee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `r_test_type`
--

DROP TABLE IF EXISTS `r_test_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `r_test_type` (
  `code` int(2) NOT NULL,
  `description` varchar(64) NOT NULL,
  PRIMARY KEY (`code`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Test type codes.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `r_test_type`
--

LOCK TABLES `r_test_type` WRITE;
/*!40000 ALTER TABLE `r_test_type` DISABLE KEYS */;
INSERT INTO `r_test_type` VALUES (1,'Top Hoel Undefined'),(2,'Top Hole Buildup'),(3,'Bottom Hole Static Gradient'),(4,'Bottom Hole Buildup'),(5,'Bottom Hole Undefined'),(6,'Bottom Hole Falloff'),(7,'Drill Stem Test'),(8,'Pressure Sentry'),(10,'Acoustic Well Sounder-Single Shot'),(11,'Acoustic Well Sounder-Buildup'),(12,'Acoustic Well Sounder-Falloff'),(99,'Rejected Misrun Test');
/*!40000 ALTER TABLE `r_test_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `remark`
--

DROP TABLE IF EXISTS `remark`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `remark` (
  `location_exception` char(2) NOT NULL,
  `legal_subdivision` int(2) NOT NULL,
  `section` int(2) NOT NULL,
  `township` int(3) NOT NULL,
  `range` int(2) NOT NULL,
  `meridian` int(1) NOT NULL,
  `event_sequence` char(1) NOT NULL,
  `consol_interval_num` int(2) NOT NULL,
  `remark_indicator` int(2) NOT NULL,
  `remark` varchar(50) NOT NULL,
  PRIMARY KEY (`location_exception`,`legal_subdivision`,`section`,`township`,`range`,`meridian`,`event_sequence`,`consol_interval_num`,`remark_indicator`),
  CONSTRAINT `fk_remark_well_id_consol_interval_num` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`),
  CONSTRAINT `fk_remark_well_id_event_sequence` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`),
  CONSTRAINT `fk_remark_well_id_legal_subdivision` FOREIGN KEY (`location_exception`, `legal_subdivision`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`),
  CONSTRAINT `fk_remark_well_id_location_exception` FOREIGN KEY (`location_exception`) REFERENCES `well_id` (`location_exception`),
  CONSTRAINT `fk_remark_well_id_meridian` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`),
  CONSTRAINT `fk_remark_well_id_range` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`),
  CONSTRAINT `fk_remark_well_id_section` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`),
  CONSTRAINT `fk_remark_well_id_township` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Remarks associated with the Test Data.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `remark`
--

LOCK TABLES `remark` WRITE;
/*!40000 ALTER TABLE `remark` DISABLE KEYS */;
/*!40000 ALTER TABLE `remark` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `test_data`
--

DROP TABLE IF EXISTS `test_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `test_data` (
  `location_exception` char(2) NOT NULL,
  `legal_subdivision` int(2) NOT NULL,
  `section` int(2) NOT NULL,
  `township` int(3) NOT NULL,
  `range` int(2) NOT NULL,
  `meridian` int(1) NOT NULL,
  `event_sequence` char(1) NOT NULL,
  `consol_interval_num` int(2) NOT NULL,
  `test_date` date NOT NULL,
  `test_type` int(2) NOT NULL,
  `historical_well_status_date` date DEFAULT NULL,
  `historical_well_status_code` varchar(10) DEFAULT NULL,
  `casing_pressure` decimal(6,0) DEFAULT NULL,
  `mpp_depth` decimal(6,2) DEFAULT NULL,
  `gauge_run_depth` decimal(6,2) DEFAULT NULL,
  `run_depth_gradient` decimal(5,3) DEFAULT NULL,
  `run_depth_pressure` decimal(6,2) DEFAULT NULL,
  `reservoir_temperature` decimal(3,0) DEFAULT NULL,
  `initial_liquid_level` decimal(6,2) DEFAULT NULL,
  `final_liquid_level` decimal(6,2) DEFAULT NULL,
  `gas_gradient` decimal(5,3) DEFAULT NULL,
  `oil_gradient` decimal(5,3) DEFAULT NULL,
  `water_gradient` decimal(5,3) DEFAULT NULL,
  `mpp_pressure` decimal(6,0) DEFAULT NULL,
  `datum_depth_pressure` decimal(6,0) DEFAULT NULL,
  `extrapolated_pressure_indicator` char(1) DEFAULT NULL,
  `extrapolated_mpp_pressure` decimal(6,0) DEFAULT NULL,
  `exptrapolated_datum_depth_pressure` decimal(6,0) DEFAULT NULL,
  `shut_in_period` decimal(5,0) DEFAULT NULL,
  `footnote_number` int(2) DEFAULT NULL,
  PRIMARY KEY (`location_exception`,`legal_subdivision`,`section`,`township`,`range`,`meridian`,`event_sequence`,`consol_interval_num`,`test_date`,`test_type`),
  KEY `fk_test_data_remark_remark_indicator_idx` (`location_exception`,`legal_subdivision`,`section`,`township`,`range`,`meridian`,`event_sequence`,`consol_interval_num`,`footnote_number`),
  KEY `fk_test_data_r_test_type_code_idx` (`test_type`),
  CONSTRAINT `fk_test_data_r_test_type_code` FOREIGN KEY (`test_type`) REFERENCES `r_test_type` (`code`),
  CONSTRAINT `fk_test_data_remark_remark_indicator` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`, `footnote_number`) REFERENCES `remark` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`, `remark_indicator`),
  CONSTRAINT `fk_test_data_well_id_consol_interval_num` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`),
  CONSTRAINT `fk_test_data_well_id_event_sequence` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`),
  CONSTRAINT `fk_test_data_well_id_legal_subdivision` FOREIGN KEY (`location_exception`, `legal_subdivision`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`),
  CONSTRAINT `fk_test_data_well_id_location_exception` FOREIGN KEY (`location_exception`) REFERENCES `well_id` (`location_exception`),
  CONSTRAINT `fk_test_data_well_id_meridian` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`),
  CONSTRAINT `fk_test_data_well_id_range` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`),
  CONSTRAINT `fk_test_data_well_id_section` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`),
  CONSTRAINT `fk_test_data_well_id_township` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Test Data';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `test_data`
--

LOCK TABLES `test_data` WRITE;
/*!40000 ALTER TABLE `test_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `test_data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `well_data`
--

DROP TABLE IF EXISTS `well_data`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `well_data` (
  `location_exception` char(2) NOT NULL,
  `legal_subdivision` int(2) NOT NULL,
  `section` int(2) NOT NULL,
  `township` int(3) NOT NULL,
  `range` int(2) NOT NULL,
  `meridian` int(1) NOT NULL,
  `event_sequence` char(1) NOT NULL,
  `consol_interval_num` int(2) NOT NULL,
  `field_code` varchar(4) DEFAULT NULL,
  `pool_code` varchar(7) DEFAULT NULL,
  `consol_interval_top` decimal(6,2) DEFAULT NULL,
  `consol_interval_bottom` decimal(6,2) DEFAULT NULL,
  `kb_elevation` decimal(6,2) DEFAULT NULL,
  `pool_datum_depth` decimal(6,2) DEFAULT NULL,
  `ground_elevation` decimal(6,2) DEFAULT NULL,
  `well_datum_depth` decimal(6,2) DEFAULT NULL,
  `initial_pool_pressure` decimal(5,0) DEFAULT NULL,
  `reservoir_gradient` decimal(5,3) DEFAULT NULL,
  PRIMARY KEY (`location_exception`,`legal_subdivision`,`section`,`township`,`range`,`meridian`,`event_sequence`,`consol_interval_num`),
  CONSTRAINT `fk_well_data_well_id_consol_interval_num` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`, `consol_interval_num`),
  CONSTRAINT `fk_well_data_well_id_event_sequence` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`, `event_sequence`),
  CONSTRAINT `fk_well_data_well_id_legal_subdivision` FOREIGN KEY (`location_exception`, `legal_subdivision`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`),
  CONSTRAINT `fk_well_data_well_id_location_exception` FOREIGN KEY (`location_exception`) REFERENCES `well_id` (`location_exception`),
  CONSTRAINT `fk_well_data_well_id_meridian` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`, `meridian`),
  CONSTRAINT `fk_well_data_well_id_range` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`, `range`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`, `range`),
  CONSTRAINT `fk_well_data_well_id_section` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`),
  CONSTRAINT `fk_well_data_well_id_township` FOREIGN KEY (`location_exception`, `legal_subdivision`, `section`, `township`) REFERENCES `well_id` (`location_exception`, `legal_subdivision`, `section`, `township`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Well Data';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `well_data`
--

LOCK TABLES `well_data` WRITE;
/*!40000 ALTER TABLE `well_data` DISABLE KEYS */;
/*!40000 ALTER TABLE `well_data` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `well_id`
--

DROP TABLE IF EXISTS `well_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `well_id` (
  `location_exception` char(2) NOT NULL,
  `legal_subdivision` int(2) NOT NULL,
  `section` int(2) NOT NULL,
  `township` int(3) NOT NULL,
  `range` int(2) NOT NULL,
  `meridian` int(1) NOT NULL,
  `event_sequence` char(1) NOT NULL,
  `consol_interval_num` int(2) NOT NULL,
  `well_name` varchar(36) DEFAULT NULL,
  `on_production_date` date DEFAULT NULL,
  PRIMARY KEY (`location_exception`,`legal_subdivision`,`section`,`township`,`range`,`meridian`,`event_sequence`,`consol_interval_num`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Well ID and On Production Date';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `well_id`
--

LOCK TABLES `well_id` WRITE;
/*!40000 ALTER TABLE `well_id` DISABLE KEYS */;
/*!40000 ALTER TABLE `well_id` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-08-17  8:21:59
