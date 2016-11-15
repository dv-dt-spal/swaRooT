//Package Name
package com.example.swaroop.cstructreader;

//Required imports
import java.nio.BufferUnderflowException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

//Class to handle BLE Advertisement Data
public class BLEDataManager {

    //BLE Advertisement Data Initialize with some default values
    // Device model name
    private String model_name = "";

    // Model range, signed big-endian.
    private short model_range = -1;

    // Firmware rev, unsigned big-endian.
    private short fw_rev = -1;

    // Device serial number, raw bytes.
    private String serial = "";

	//Getter APIs
    // Get Device model name
    public String GetModelName(){ return model_name; }

    //Get Model range
    public short GetModelRange() { return model_range; }

    //Get Firmware rev
    public short GetFwRev() { return fw_rev; }

    //Get Device serial number
    public String GetSerialNo() { return serial; }

    //Function to initialize the class with the BLE Adv received from device and parse it
    public void Init(byte[] p_BLEAdvData){
        
        //Validate Parameter
        if(null == p_BLEAdvData){
            return;
        }

        //Get byte buffer form the byte array
        final ByteBuffer p_BLEAdvDataByteBuffer = ByteBuffer.wrap(p_BLEAdvData);

        //Ensure the Endianess of the byte buffer
        p_BLEAdvDataByteBuffer.order(ByteOrder.BIG_ENDIAN);

        //Parse the data
        try {
            //Array for model name
            byte[] modelnameArr = new byte[7];

            //Get the byte array for the model name
            p_BLEAdvDataByteBuffer.get(modelnameArr, 0, 7);
            model_name = new String(modelnameArr);

            //Get the model range short value
            model_range = p_BLEAdvDataByteBuffer.getShort();

            //Get the fw revision short value
            fw_rev = p_BLEAdvDataByteBuffer.getShort();

            //Array for serial buffer - Assuming the packet sent are serialized
            //Else there would a extra padding here due to c struct packaging
            //And we would have to skip 1 byte to get the serial number
            byte[] serialArr = new byte[6];

            //Get the byte array for the serial
            p_BLEAdvDataByteBuffer.get(serialArr, 0, 6);
            serial = new String(serialArr);
        }
        catch(BufferUnderflowException e){
            e.printStackTrace();
        }
        catch(IndexOutOfBoundsException e){
            e.printStackTrace();
        }
    }
}