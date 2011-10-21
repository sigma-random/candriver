/// Enable individual mask mode, not supported by MPC5554 and MPC5553, MPC5567?
#define CAN_ENABLE_INDIVIDUAL_MASK    STD_ON
/// set number of used msgboxes, max is 64
#define CAN_NUM_MSGBOXES			  64
/** Enable Development Error Trace. */
#define CAN_DEV_ERROR_DETECT          STD_ON
/** Build version info API. */
#define CAN_VERSION_INFO_API          STD_OFF
/// Enable multiplexed transmission, multiple tx msgboxes per hth
#define CAN_MULTIPLEXED_TRANSMISSION  STD_ON
/// Enable cancelation of tx msgs with lower prio
#define CAN_HW_TRANSMIT_CANCELLATION   STD_OFF
///  Cancellation also cancels equal prio
#define CAN_IDENTICAL_ID_CANCELLATION  STD_OFF
/// Max busy wait time for CAN state transition [ms]
#define CAN_TIMEOUT_DURATION          100
/// general CAN RX callout function, do not define to disable
#define CAN_LPDU_RX_CB                CanLPduReceiveCalloutFunction
/// reference to the oscillator clock freq value
#define CAN_CPU_CLOCK_REFERENCE		  (uint32*)&oscillatorClockFreq

/// base address for the can controller module
void Can_Arc_Write( Can_HwHandleType hth ); // called either from Can_MainFunction_Write or isr
void Can_Arc_Read( Can_HwHandleType hrh );  // called either from Can_MainFunction_Read or isr
void Can_Arc_BusOff( uint8 controller );	// called either from Can_MainFunction_BusOff or isr

typedef enum {
	CanContoroller_CAN_A,
	CanContoroller_CAN_C,
	CanContoroller_CAN_D,
	CAN_NUM_CONTROLLERS
}Can_Arc_ControllerIdType;

typedef enum {
	CAN_HTH_A_1 = 0,
	CAN_HTH_C_1,
	CAN_HRH_A_1,
	CAN_HRH_C_1,
	NUM_OF_HOHS
} Can_Arc_HwHandleType;

extern Can_ConfigType Can_config;

struct FlexCan;
typedef volatile struct FlexCan FlexCanT;

/// Can controller base address, see ref manual for correct value
static FlexCanT* const CAN_CONTROLLER_BASE_ADDRESS[CAN_NUM_CONTROLLERS] = {
	[CanContoroller_CAN_A] = (FlexCanT*)0x12345678,
	[CanContoroller_CAN_C] = (FlexCanT*)0x87654321,
	[CanContoroller_CAN_D] = (FlexCanT*)0x11111111
};
	

static inline void Can_MainFunction_Write( void )
{
	// add all hth without isr
}

static inline void Can_MainFunction_Read( void )
{
	// add all hrh without isr
}

static inline void Can_MainFunction_BusOff( void )
{
	// add all controllers without isr
}

