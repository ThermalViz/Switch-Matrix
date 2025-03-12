# Switch Matrix Board MUX
# Developed by CID:
- Joshua Chan
- John Juvi De Villa
- Ace Alexander Ilog

# WARNING!
Do not use digitalwrite() unless YOU KNOW WHAT YOU'RE DOING.
manual digitalWrite() can cause problems when power is supplied
to the relays. At worst, the board or DUT can break.

# Keymapping:
<table>
<tr>
  <th>DUT</th>
  <th>Inverting</th>
  <th>Non-Inverting</th>
  <th>Out</th>
  <th>Mode</th>
</tr>
<tr>
  <td>
    DUT_1 <br> <br>
    DUT_2 <br> <br>
    DUT_3 <br> <br>
    DUT_4 
  </td>
  <td>
    I_IN0 <br> <br>
    I_IN1 <br>  <br>
    I_IN2 <br>  <br>
    I_GND 
  </td>
  <td>
    NI_IN0 <br> <br>
    NI_IN1 <br> <br>
    NI_IN2 <br> <br>
    NI_GND
  </td>
  <td>
    OUT_GND <br> <br>
    OUT_FEEDBACK <br> <br>
    DMM <br> <br>
    SCOPE
  </td>
  <td>
    AC_MODE <br> <br>
    DC_MODE
  </td>
</tr>
</table>

# Commands:
### RLAY [Key] [1/0]
manually sets a relay do not use this command unless you know what you're doing!.

Ex: RLAY I_IN1 1   | sets relay I_IN1 to HIGH
### DUTS [Key]
sets the active DUT. Only one DUT can be active at a time

Ex: DUTS DUT_1      | sets DUT_1 as the active DUT.
### INVT [Key] [0/1] 
Sets the inverting input resistors and if input is GND.

Ex: INVT I_IN1 1    | sets the inverting input to the 3rd option and is grounded.
### NINV [Key] [0/1]
Sets the non-inverting input resistors and if input is GND.

Ex: NINV NI_IN1 1   | sets the non-inverting input to the 3rd option and is grounded.
### VOUT [Key]
Sets the output if to GND or to the feedback resistor.

Ex: VOUT OUT_GND      | sets the output to the 1st option which is to ground.
### MEAS [Key]
Sets the instrument measuring to either the DMM or the oscilloscope.

Ex: MEAS SCOPE      | sets the measurement tool to the oscilloscope.
### ALL0
Sets all relays OFF.
