package com.crotsertech.systemsizerii;

import android.os.Bundle;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    WebView SS2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        SS2 = findViewById(R.id.SS2);
        SS2.getSettings().setJavaScriptEnabled(true);
        SS2.setWebViewClient(new WebViewClient());
        SS2.loadUrl("https://crotser.us/ss2.html");
    }
}