package com.example.wanger.blueteeth;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Set;

public class MainActivity extends AppCompatActivity {

    private Button On, Off, List, Connect;
    private BluetoothAdapter BA;
    private Set<BluetoothDevice> pairedDevice;
    private ListView lv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        On = (Button) findViewById(R.id.open_button);
        Off = (Button) findViewById(R.id.close_button);
        List = (Button) findViewById(R.id.list_device);
        Connect = (Button) findViewById(R.id.connect_device);
        lv = (ListView) findViewById(R.id.listView);

        BA = BluetoothAdapter.getDefaultAdapter();

        On.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(null == BA)
                    Toast.makeText(getApplicationContext(),
                            "this device doesn't suport Blueteeth",
                            Toast.LENGTH_SHORT).show();
                else{
                    if(!BA.isEnabled())
                    {
                        Intent enableBTIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                        startActivity(enableBTIntent);
                        Toast.makeText(getApplicationContext(), "turned on",
                                Toast.LENGTH_SHORT).show();
                    }
                    else
                        Toast.makeText(getApplicationContext(), "already on ", Toast.LENGTH_SHORT).show();
                }
            }
        });
        Off.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(BA.isEnabled()){
                    BA.disable();
                    Toast.makeText(getApplicationContext(),"Turned off", Toast.LENGTH_SHORT).show();
                }
                else
                {
                    Toast.makeText(getApplicationContext(),"already closed", Toast.LENGTH_SHORT).show();
                }
            }
        });

        List.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                pairedDevice = BA.getBondedDevices();
                ArrayList list_tmp = new ArrayList();

                for (BluetoothDevice bt:pairedDevice)
                    list_tmp.add(bt.getName());

                Toast.makeText(getApplicationContext(), "Show paired device", Toast.LENGTH_SHORT).show();

                final ArrayAdapter adapter = new ArrayAdapter()
                lv.setAdapter(adapter);
            }
        });

    }
}
