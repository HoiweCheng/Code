package com.example.wanger.telcontroller;


import android.bluetooth.BluetoothAdapter;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.drawable.Drawable;
import android.media.Image;
import android.os.StrictMode;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import com.example.wanger.telcontroller.R;

import java.util.ArrayList;
import java.util.List;

import lecho.lib.hellocharts.formatter.SimpleLineChartValueFormatter;
import lecho.lib.hellocharts.gesture.ZoomType;
import lecho.lib.hellocharts.model.Axis;
import lecho.lib.hellocharts.model.AxisValue;
import lecho.lib.hellocharts.model.Line;
import lecho.lib.hellocharts.model.LineChartData;
import lecho.lib.hellocharts.model.PointValue;
import lecho.lib.hellocharts.model.ValueShape;
import lecho.lib.hellocharts.model.Viewport;
import lecho.lib.hellocharts.view.LineChartView;


public class MainActivity extends AppCompatActivity {

    final String TAG = "DEBUG MainActivity";

    enum Mode_select {NONE, TEMPERATURE, LIGHT, WET}
    private Mode_select modeSelect = Mode_select.NONE;
    private int thresholdValue = 0;
    private ConnectionManager mConnectionManager;

    private LineChartView lineChart;
    private List<PointValue> mPointValues = new ArrayList<>();


    ArrayList<Float> mDataBuffer;
    private LineChartData data = new LineChartData();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setDisplayShowHomeEnabled(true);


        Spinner mSpinner = (Spinner) findViewById(R.id.spinner1);
        final EditText mEditText = (EditText) findViewById(R.id.mode_threshold);
        final ImageButton mSendButton = (ImageButton) findViewById(R.id.send_button);
        ImageButton mSyncButton = (ImageButton) findViewById(R.id.sync);
        final ImageButton mOpenButton = (ImageButton) findViewById(R.id.open);
        final ImageButton mCloseButton = (ImageButton) findViewById(R.id.close);

        lineChart = (LineChartView)findViewById(R.id.line_chart);

        mDataBuffer = new ArrayList<>();
        getAxisPoints();//获取坐标点
        initLineChart();


        mSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                String[] str = getResources().getStringArray(R.array.modes);
                switch(str[i])
                {
                    case "温度":
                        modeSelect = Mode_select.TEMPERATURE;
                        break;
                    case "湿度":
                        modeSelect = Mode_select.WET;
                        break;
                    case "光强":
                        modeSelect = Mode_select.LIGHT;
                        break;
                    default:
                        modeSelect = Mode_select.NONE;
                        break;
                }
                Toast.makeText(MainActivity.this, " you clicked "+ str[i], Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

        mEditText.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView textView, int actionId, KeyEvent keyEvent) {
                if (actionId == EditorInfo.IME_ACTION_DONE)
                {
                    int thres_tmp = 0;
                    mEditText.setCursorVisible(false);
                    String input = mEditText.getText().toString();
                    if(!input.equals(""))
                        thres_tmp = Integer.parseInt(input);
                    if(verifyData(thres_tmp))
                    {thresholdValue = thres_tmp;}
                    InputMethodManager IMM = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
                    IMM.hideSoftInputFromWindow(textView.getWindowToken(), InputMethodManager.HIDE_NOT_ALWAYS);
                }
                return false;
            }
        });

        mSendButton.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                    if(motionEvent.getAction()==MotionEvent.ACTION_DOWN){
                        mSendButton.setBackgroundResource(R.drawable.send_push);
                    }
                    if(motionEvent.getAction()==MotionEvent.ACTION_UP){
                        mSendButton.setBackgroundResource(R.drawable.send);
                        sendMessage("set");
                    }

                return false;
            }
        });

        mSyncButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                sendMessage("sync");
            }
        });

        mOpenButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                sendMessage("open");
                mCloseButton.setVisibility(View.VISIBLE);
                mOpenButton.setVisibility(View.INVISIBLE);
            }
        });

        mCloseButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                sendMessage("close");
                mCloseButton.setVisibility(View.INVISIBLE);
                mOpenButton.setVisibility(View.VISIBLE);
            }
        });

        mConnectionManager = new ConnectionManager(mConnectionListener);

        Intent intent = getIntent();
        String deviceAddress = intent.getStringExtra("DEVICE_ADDR");
        Toast.makeText(getApplicationContext(),deviceAddress, Toast.LENGTH_SHORT).show();
        Log.d(TAG, deviceAddress);

        if(deviceAddress!= null)
            mConnectionManager.connect(deviceAddress);


}

    @Override
    protected void onDestroy(){
        mConnectionManager.disconnect();
        super.onDestroy();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch(item.getItemId())
        {
            case android.R.id.home:
                this.finish();
                break;
        }
        return true;
    }

    private void sendMessage(String command)
    {
        switch(command)
        {
            default:
                Toast.makeText(getApplicationContext(),
                        "please input the right value", Toast.LENGTH_SHORT).show();
                break;
            case "open": {
                mConnectionManager.sendData("c".getBytes());
                try{
                    Thread.currentThread().sleep(1000);
                }
                catch (Exception e){}
                mConnectionManager.sendData("a".getBytes());
                Log.d(TAG,"open");
                try{
                    Thread.currentThread().sleep(5000);
                }
                catch (Exception e){}
                mConnectionManager.sendData("d".getBytes());
            }   break;
            case "close": {
                mConnectionManager.sendData("c".getBytes());
                try{
                    Thread.currentThread().sleep(1000);
                }
                catch (Exception e){}
                mConnectionManager.sendData("b".getBytes());
                Log.d("TAG","Close");
                try{
                    Thread.currentThread().sleep(5000);
                }
                catch (Exception e){}
                mConnectionManager.sendData("d".getBytes());
            }   break;
            case "sync":
            {
                mConnectionManager.sendData("2".getBytes());
                String test = mConnectionManager.readData();
                mConnectionManager.setData_String();
                ConvertDataString(test);

                getAxisPoints();
                lineChart.setLineChartData(data);

              //  Log.d(TAG, test);
            }
                break;
            case "set":
               String sendData = "3";
                switch (modeSelect)
                {
                    case TEMPERATURE:
                        sendData = sendData +"1"+thresholdValue;
                        mConnectionManager.sendData(sendData.getBytes());
                        break;
                    case LIGHT:
                        sendData = sendData +"2"+thresholdValue;
                        mConnectionManager.sendData(sendData.getBytes());
                        break;
                    case WET:
                        sendData = sendData +"3"+thresholdValue;
                        mConnectionManager.sendData(sendData.getBytes());
                        break;
                    default:
                        break;
                }
                break;
        }
    }

    private boolean verifyData(int thresholdValue)
    {
        switch (modeSelect)
        {
            default:
                return  false;
            case TEMPERATURE:
                    return !(thresholdValue < -40 || thresholdValue > 40);
            case LIGHT:
                    return !(thresholdValue < 0 || thresholdValue > 100);
            case WET:
                    return !(thresholdValue < 0 || thresholdValue > 100);
        }
    }

    private void ConvertDataString(String data)
    {

        String[] DataList  = null;
        if(data != null) {
                     DataList = data.split("\t");
                }

        for(String a :DataList)
        {
           Log.i("temperature: ", a);
            try
            {
              Integer B =  Integer.parseInt(a);
                double temp = B / 10.0;
                if(temp>20&&temp<40)
                    mDataBuffer.add((float)temp);
            }
            catch (Exception e)
            {

            }

        }
    }
    private ConnectionManager.ConnectionListener mConnectionListener = new ConnectionManager.ConnectionListener() {
        @Override
        public void onConnectStateChange(int oldState, int State) {

        }

        @Override
        public void onListenStateChange(int oldState, int State) {

        }

        @Override
        public void onSendData(boolean suc, byte[] data) {

        }

        @Override
        public String onReadData(byte[] data) {
            return new String(data);
        }
    };

    private void initLineChart(){
        Line line = new Line(mPointValues).setColor(Color.parseColor("#FFCD41"));  //折线的颜色
        List<Line> lines = new ArrayList<Line>();
        line.setShape(ValueShape.CIRCLE);//折线图上每个数据点的形状  这里是圆形 （有三种 ：ValueShape.SQUARE  ValueShape.CIRCLE  ValueShape.SQUARE）
        line.setCubic(true);//曲线是否平滑
//	    line.setStrokeWidth(3);//线条的粗细，默认是3
        line.setFilled(false);//是否填充曲线的面积
        line.setHasLabels(true);//曲线的数据坐标是否加上备注
//		line.setHasLabelsOnlyForSelected(true);//点击数据坐标提示数据（设置了这个line.setHasLabels(true);就无效）
        line.setHasLines(true);//是否用直线显示。如果为false 则没有曲线只有点显示
        line.setHasPoints(true);//是否显示圆点 如果为false 则没有原点只有点显示
        line.setFormatter(new SimpleLineChartValueFormatter(1));
        lines.add(line);

        data.setLines(lines);

        //坐标轴
        Axis axisX = new Axis(); //X轴
        axisX.setHasTiltedLabels(true);  //X轴下面坐标轴字体是斜的显示还是直的，true是斜的显示
//	    axisX.setTextColor(Color.WHITE);  //设置字体颜色
        axisX.setTextColor(Color.parseColor("#D6D6D9"));//灰色

        /*
//	    axisX.setName("未来几天的天气");  //表格名称
        axisX.setTextSize(11);//设置字体大小
        axisX.setMaxLabelChars(7); //最多几个X轴坐标，意思就是你的缩放让X轴上数据的个数7<=x<=mAxisValues.length
        axisX.setValues(mAxisXValues);  //填充X轴的坐标名称
        data.setAxisXBottom(axisX); //x 轴在底部
//	    data.setAxisXTop(axisX);  //x 轴在顶部
        axisX.setHasLines(true); //x 轴分割线
*/

        Axis axisY = new Axis();  //Y轴
        axisY.setName("");//y轴标注
        axisY.setTextSize(11);//设置字体大小
        data.setAxisYLeft(axisY);  //Y轴设置在左边
        //data.setAxisYRight(axisY);  //y轴设置在右边

        //设置行为属性，支持缩放、滑动以及平移
        lineChart.setInteractive(true);
        lineChart.setZoomType(ZoomType.HORIZONTAL);
        lineChart.setMaxZoom((float) 3);//缩放比例
        lineChart.setLineChartData(data);
        lineChart.setVisibility(View.VISIBLE);

        /**注：下面的7，10只是代表一个数字去类比而已
         * 尼玛搞的老子好辛苦！！！见（http://forum.xda-developers.com/tools/programming/library-hellocharts-charting-library-t2904456/page2）;
         * 下面几句可以设置X轴数据的显示个数（x轴0-7个数据），当数据点个数小于（29）的时候，缩小到极致hellochart默认的是所有显示。当数据点个数大于（29）的时候，
         * 若不设置axisX.setMaxLabelChars(int count)这句话,则会自动适配X轴所能显示的尽量合适的数据个数。
         * 若设置axisX.setMaxLabelChars(int count)这句话,
         * 33个数据点测试，若 axisX.setMaxLabelChars(10);里面的10大于v.right= 7; 里面的7，则
         刚开始X轴显示7条数据，然后缩放的时候X轴的个数会保证大于7小于10
         若小于v.right= 7;中的7,反正我感觉是这两句都好像失效了的样子 - -!
         * 并且Y轴是根据数据的大小自动设置Y轴上限
         * 若这儿不设置 v.right= 7; 这句话，则图表刚开始就会尽可能的显示所有数据，交互性太差
         */
        Viewport v = new Viewport(lineChart.getMaximumViewport());
        v.left = 0;
        v.right= 7;
        lineChart.setCurrentViewport(v);
    }

   /**
     * 图表的每个点的显示
     */
    private void getAxisPoints(){
        for (int i = 0; i < mDataBuffer.size(); i++) {
            mPointValues.add(new PointValue(i, mDataBuffer.get(i)));
        }
    }

}
