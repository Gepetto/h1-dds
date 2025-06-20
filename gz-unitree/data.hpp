#include <algorithm>
#include <cmath>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <cstdlib>

#ifndef GZ_UNITREE_DATA_HPP
#define GZ_UNITREE_DATA_HPP

const int H1_NUM_MOTOR = 27;

template <typename T>
class DataBuffer
{
public:
    void SetData(const T &newData)
    {
        std::unique_lock<std::shared_mutex> lock(mutex);
        data = std::make_shared<T>(newData);
    }

    std::shared_ptr<const T> GetData()
    {
        std::shared_lock<std::shared_mutex> lock(mutex);
        return data ? data : nullptr;
    }

    void Clear()
    {
        std::unique_lock<std::shared_mutex> lock(mutex);
        data = nullptr;
    }

private:
    std::shared_ptr<T> data;
    std::shared_mutex mutex;
};

struct ImuState
{
    std::array<float, 3> rpy = {};
    std::array<float, 3> omega = {};
};

struct MotorCommand
{
    std::array<float, H1_NUM_MOTOR> q_target = {};
    std::array<float, H1_NUM_MOTOR> dq_target = {};
    std::array<float, H1_NUM_MOTOR> kp = {};
    std::array<float, H1_NUM_MOTOR> kd = {};
    std::array<float, H1_NUM_MOTOR> tau_ff = {};
};

struct MotorState
{
    std::array<float, H1_NUM_MOTOR> q = {};
    std::array<float, H1_NUM_MOTOR> dq = {};
};

enum MotorType
{
    GearboxS = 0,
    GearboxM = 1,
    GearboxL = 2
};

std::array<MotorType, H1_NUM_MOTOR> H1MotorType{
    // clang-format off
    // legs
    GearboxM, GearboxM, GearboxM, GearboxL, GearboxS, GearboxS,
    GearboxM, GearboxM, GearboxM, GearboxL, GearboxS, GearboxS,
    // waist
    GearboxM,
    // arms
    GearboxS, GearboxS, GearboxS, GearboxS, GearboxS, GearboxS, GearboxS,
    GearboxS, GearboxS, GearboxS, GearboxS, GearboxS, GearboxS, GearboxS
    // clang-format on
};

enum PRorAB
{
    PR = 0,
    AB = 1
};

enum H1JointIndex
{
    // legs
    LeftHipYaw = 0,
    LeftHipPitch = 1,
    LeftHipRoll = 2,
    LeftKnee = 3,
    LeftAnklePitch = 4,
    LeftAnkleB = 4,
    LeftAnkleRoll = 5,
    LeftAnkleA = 5,
    RightHipYaw = 6,
    RightHipPitch = 7,
    RightHipRoll = 8,
    RightKnee = 9,
    RightAnklePitch = 10,
    RightAnkleB = 10,
    RightAnkleRoll = 11,
    RightAnkleA = 11,
    // torso
    WaistYaw = 12,
    // arms
    LeftShoulderPitch = 13,
    LeftShoulderRoll = 14,
    LeftShoulderYaw = 15,
    LeftElbow = 16,
    LeftWristRoll = 17,
    LeftWristPitch = 18,
    LeftWristYaw = 19,
    RightShoulderPitch = 20,
    RightShoulderRoll = 21,
    RightShoulderYaw = 22,
    RightElbow = 23,
    RightWristRoll = 24,
    RightWristPitch = 25,
    RightWristYaw = 26
};

#endif
