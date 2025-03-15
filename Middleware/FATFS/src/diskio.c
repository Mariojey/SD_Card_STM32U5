/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2023        */
/*                                                                       */
/*   Portions COPYRIGHT 2017-2023 STMicroelectronics                     */
/*   Portions Copyright (C) 2013, ChaN, all right reserved               */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various existing      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "diskio.h"
#include "ff_gen_drv.h"
#include "user_diskio_spi.h"

#if defined ( __GNUC__ )
#ifndef __weak
#define __weak __attribute__((weak))
#endif
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern Disk_drvTypeDef  disk;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Gets Disk Status
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS disk_status (
	BYTE pdrv		/* Physical drive number to identify the drive */
)
{
//  DSTATUS stat;
//
//  stat = disk.drv[pdrv]->disk_status(disk.lun[pdrv]);
//  return stat;
	/* USER CODE BEGIN STATUS  */
	return USER_SPI_status(pdrv);
	/* USER CODE END STATUS */
}

/**
  * @brief  Initializes a Drive
  * @param  pdrv: Physical drive number (0..)
  * @retval DSTATUS: Operation status
  */
DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	/* USER CODE BEGIN INIT */
//  DSTATUS stat = RES_OK;
//
//  if(disk.is_initialized[pdrv] == 0)
//  {
//    stat = disk.drv[pdrv]->disk_initialize(disk.lun[pdrv]);
//    if(stat == RES_OK)
//    {
//      disk.is_initialized[pdrv] = 1;
//    }
//  }
//  return stat;

	return USER_SPI_initialize(pdrv);
	/* USER CODE END INIT */
}

/**
  * @brief  Reads Sector(s)
  * @param  pdrv: Physical drive number (0..)
  * @param  *buff: Data buffer to store read data
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to read (1..128)
  * @retval DRESULT: Operation result
  */
DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	LBA_t sector,   /* Sector address in LBA */
	UINT count		/* Number of sectors to read */
)

{
	/* USER CODE BEGIN READ */
//  DRESULT res;
//
//  res = disk.drv[pdrv]->disk_read(disk.lun[pdrv], buff, sector, count);
//  return res;

	return USER_SPI_read(pdrv, buff, sector, count);
	/* USER CODE BEGIN READ */
}

/**
  * @brief  Writes Sector(s)
  * @param  pdrv: Physical drive number (0..)
  * @param  *buff: Data to be written
  * @param  sector: Sector address (LBA)
  * @param  count: Number of sectors to write (1..128)
  * @retval DRESULT: Operation result
  */
#if _USE_WRITE == 1
DRESULT disk_write (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	LBA_t sector,		/* Sector address in LBA */
	UINT count        	/* Number of sectors to write */
)
{
//  DRESULT res;
//
//  res = disk.drv[pdrv]->disk_write(disk.lun[pdrv], buff, sector, count);
//  return res;
	/* USER CODE BEGIN WRITE */
	/* USER CODE HERE */
	return USER_SPI_write(pdrv, buff, sector, count);
	/* USER CODE END WRITE */
}

#endif /* _USE_WRITE == 1 */


/**
  * @brief  I/O control operation
  * @param  pdrv: Physical drive number (0..)
  * @param  cmd: Control code
  * @param  *buff: Buffer to send/receive control data
  * @retval DRESULT: Operation result
  */

#if _USE_IOCTL == 1
DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
  /* USER CODE BEGIN IOCTL */
	return USER_SPI_ioctl(pdrv, cmd, buff);
 /* USER CODE END IOCTL */
}
#endif /* _USE_IOCTL == 1 */


/**
  * @brief  Gets Time from RTC
  * @param  None
  * @retval Time in DWORD
  */
__weak DWORD get_fattime (void)
{
  return 0;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

