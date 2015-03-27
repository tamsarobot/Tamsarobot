#ifndef _ROS_odometry4_MyOdometry4_h
#define _ROS_odometry4_MyOdometry4_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace odometry4
{

  class MyOdometry4 : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float Rt_pulse;
      float Lt_pulse;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      int32_t * val_Rt_pulse = (int32_t *) &(this->Rt_pulse);
      int32_t exp_Rt_pulse = (((*val_Rt_pulse)>>23)&255);
      if(exp_Rt_pulse != 0)
        exp_Rt_pulse += 1023-127;
      int32_t sig_Rt_pulse = *val_Rt_pulse;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Rt_pulse<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Rt_pulse>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Rt_pulse>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Rt_pulse<<4) & 0xF0) | ((sig_Rt_pulse>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Rt_pulse>>4) & 0x7F;
      if(this->Rt_pulse < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_Lt_pulse = (int32_t *) &(this->Lt_pulse);
      int32_t exp_Lt_pulse = (((*val_Lt_pulse)>>23)&255);
      if(exp_Lt_pulse != 0)
        exp_Lt_pulse += 1023-127;
      int32_t sig_Lt_pulse = *val_Lt_pulse;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_Lt_pulse<<5) & 0xff;
      *(outbuffer + offset++) = (sig_Lt_pulse>>3) & 0xff;
      *(outbuffer + offset++) = (sig_Lt_pulse>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_Lt_pulse<<4) & 0xF0) | ((sig_Lt_pulse>>19)&0x0F);
      *(outbuffer + offset++) = (exp_Lt_pulse>>4) & 0x7F;
      if(this->Lt_pulse < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t * val_Rt_pulse = (uint32_t*) &(this->Rt_pulse);
      offset += 3;
      *val_Rt_pulse = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Rt_pulse |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Rt_pulse |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Rt_pulse |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Rt_pulse = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Rt_pulse |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Rt_pulse !=0)
        *val_Rt_pulse |= ((exp_Rt_pulse)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->Rt_pulse = -this->Rt_pulse;
      uint32_t * val_Lt_pulse = (uint32_t*) &(this->Lt_pulse);
      offset += 3;
      *val_Lt_pulse = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_Lt_pulse |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_Lt_pulse |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_Lt_pulse |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_Lt_pulse = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_Lt_pulse |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_Lt_pulse !=0)
        *val_Lt_pulse |= ((exp_Lt_pulse)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->Lt_pulse = -this->Lt_pulse;
     return offset;
    }

    const char * getType(){ return "odometry4/MyOdometry4"; };
    const char * getMD5(){ return "207d0e59e086a2e869b58bd38f957849"; };

  };

}
#endif