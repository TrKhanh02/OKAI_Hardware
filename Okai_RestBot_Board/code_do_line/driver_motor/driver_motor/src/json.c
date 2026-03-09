#include "json.h"

uint8_t parse_json(const char *buf, int *AngleA, int *sAngleA, int *AngleB, int *sAngleB, int *MotorA, int *sMotorA, int *MotorB, int *sMotorB)
{

	const char *p = buf;
	// bỏ qua các ký tự không phải số
	while (*p && (*p < '0' || *p > '9'))
		p++;
	*AngleA = 0;
	while (*p >= '0' && *p <= '9')
	{
		*AngleA = *AngleA * 10 + (*p - '0');
		p++;
	}
	while (*p && (*p < '0' || *p > '9'))
		p++;
	*sAngleA = 0;
	while (*p >= '0' && *p <= '9')
	{
		*sAngleA = *sAngleA * 10 + (*p - '0');
		p++;
	}

	while (*p && (*p < '0' || *p > '9'))
		p++;
	*AngleB = 0;
	while (*p >= '0' && *p <= '9')
	{
		*AngleB = *AngleB * 10 + (*p - '0');
		p++;
	}
	while (*p && (*p < '0' || *p > '9'))
		p++;
	*sAngleB = 0;
	while (*p >= '0' && *p <= '9')
	{
		*sAngleB = *sAngleB * 10 + (*p - '0');
		p++;
	}

	while (*p && (*p < '0' || *p > '9'))
		p++;
	*MotorA = 0;
	while (*p >= '0' && *p <= '9')
	{
		*MotorA = *MotorA * 10 + (*p - '0');
		p++;
	}
	while (*p && (*p < '0' || *p > '9'))
		p++;
	*sMotorA = 0;
	while (*p >= '0' && *p <= '9')
	{
		*sMotorA = *sMotorA * 10 + (*p - '0');
		p++;
	}

	while (*p && (*p < '0' || *p > '9'))
		p++;
	*MotorB = 0;
	while (*p >= '0' && *p <= '9')
	{
		*MotorB = *MotorB * 10 + (*p - '0');
		p++;
	}
	while (*p && (*p < '0' || *p > '9'))
		p++;
	*sMotorB = 0;
	while (*p >= '0' && *p <= '9')
	{
		*sMotorB = *sMotorB * 10 + (*p - '0');
		p++;
	}

	return 1; // parse thành công
}
