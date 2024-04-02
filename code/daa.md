# DAA

## DDA

```cpp
#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawDDALine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++)
    {
        // putpixel((x), (y), WHITE);
        x += Xinc;
        y += Yinc;
        putpixel(floor(x + 0.5), floor(y + 0.5), WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Call drawDDALine with appropriate arguments
    drawDDALine(100, 100, 400, 400);

    getch();
    closegraph();
    return 0;
}
```

## Bresham

```cpp
#include <graphics.h>
#include <conio.h>

void drawBresenhamLine(int x1, int y1, int x2, int y2)
{
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new - (x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {
        putpixel(x, y, WHITE);
        slope_error_new += m_new;
        if (slope_error_new >= 0)
        {
            y++;
            slope_error_new -= 2 * (x2 - x1);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Call drawBresenhamLine with appropriate arguments
    drawBresenhamLine(100, 100, 400, 400);

    getch();
    closegraph();
    return 0;
}
```

## Boundary Fill

```cpp
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void bfill(int x, int y, int fillcolor, int boundrycolor);
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboC3\\BGI");
    setcolor(BLACK);
    circle(300, 200, 40);
    bfill(300, 200, 4, 5);

    getch();
}
void bfill(int x, int y, int fillcolor, int boundrycolor)
{
    if (getpixel(x, y) != boundrycolor && getpixel(x, y) != fillcolor)
    {
        putpixel(x, y, fillcolor);
        bfill(x + 1, y, fillcolor, boundrycolor);
        bfill(x - 1, y, fillcolor, boundrycolor);
        bfill(x, y + 1, fillcolor, boundrycolor);
        bfill(x, y - 1, fillcolor, boundrycolor);
    }
}
```

## Flood Fill

```cpp
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void ff(int sx, int sy, int fc, int oc)
{
    if (getpixel(sx, sy) == oc)
    {
        putpixel(sx, sy, fc);
        ff(sx + 1, sy, fc, oc);
        ff(sx - 1, sy, fc, oc);
        ff(sx, sy + 1, fc, oc);
        ff(sx, sy - 1, fc, oc);
    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
    setcolor(1);
    line(100, 100, 150, 100);
    setcolor(2);
    line(100, 100, 100, 150);
    setcolor(3);
    line(100, 150, 150, 150);
    setcolor(4);
    line(150, 150, 150, 100);
    ff(125, 125, GREEN, 0);
    getch();
}
```

# Android

## Explicit Intent

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
  xmlns:app="http://schemas.android.com/apk/res-auto"
  xmlns:tools="http://schemas.android.com/tools"
  android:layout_width="match_parent"
  android:layout_height="match_parent">

  <Button
      android:id="@+id/launch_button"
      android:layout_width="wrap_content"
      android:layout_height="wrap_content"
      android:text="Launch Second Activity"
      app:layout_constraintBottom_toBottomOf="parent"
      app:layout_constraintLeft_toLeftOf="parent"
      app:layout_constraintRight_toRightOf="parent"
      app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>
```

```java
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.content.Intent;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button launchButton = findViewById(R.id.launch_button);

        launchButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                startActivity(intent);
            }
        });
    }
}
```

## Implicit Intent

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
  xmlns:app="http://schemas.android.com/apk/res-auto"
  xmlns:tools="http://schemas.android.com/tools"
  android:layout_width="match_parent"
  android:layout_height="match_parent">

  <Button
      android:id="@+id/open_web_button"
      android:layout_width="wrap_content"
      android:layout_height="wrap_content"
      android:text="Open Website"
      app:layout_constraintBottom_toBottomOf="parent"
      app:layout_constraintLeft_toLeftOf="parent"
      app:layout_constraintRight_toRightOf="parent"
      app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>
```


```java
import android.content.Intent;
import android.net.Uri;
import android.view.View;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // ... rest of your code for button click handling and opening a website
        Button openWebButton = findViewById(R.id.open_web_button);

        openWebButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Similar functionality to open a website as before
                Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.example.com"));
                startActivity(intent);
            }
        });
    }
}
```

## Linear Layout

```java
import android.os.Bundle;
import android.widget.Button;
import android.widget.LinearLayout;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Find the LinearLayout by its ID
        LinearLayout linearLayout = findViewById(R.id.linearLayout);

        // Create a Button with proper text formatting
        Button button = new Button(this);
        button.setText("Ready for Mid-sem. Exam"); // Use double-quotes for string literals

        // Add the Button to the LinearLayout
        linearLayout.addView(button);
    }
}
```

## ListView

```java
// MainActivity.java
import android.os.Bundle;
import android.app.Activity;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MainActivity extends Activity {
    ListView listView;
    String[] items = {"Item 1", "Item 2", "Item 3", "Item 4"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listView = (ListView) findViewById(R.id.list_view);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, items);
        listView.setAdapter(adapter);
    }
}
```


```xml
<!-- activity_main.xml -->
<ListView
    android:id="@+id/list_view"
    android:layout_width="match_parent"
    android:layout_height="match_parent" />
```


## Toast

```java
// MainActivity.java
import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
    Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button = (Button) findViewById(R.id.my_button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // This is the event handler for the click event
                Toast.makeText(getApplicationContext(), "Button Clicked", Toast.LENGTH_SHORT).show();
            }
        });
    }
}
```