package com.crotsertech.systemsizerii;

import android.os.Bundle;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import androidx.activity.EdgeToEdge;
import androidx.activity.OnBackPressedCallback;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private WebView SS2;
    private static final String INDEX_URL = "file:///android_asset/index.html";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        SS2 = findViewById(R.id.SS2);
        SS2.getSettings().setJavaScriptEnabled(true);
        SS2.setWebViewClient(new WebViewClient());
        SS2.loadUrl(INDEX_URL);

        // Register custom back button behavior
        getOnBackPressedDispatcher().addCallback(this, new OnBackPressedCallback(true) {
            @Override
            public void handleOnBackPressed() {
                String currentUrl = SS2.getUrl();

                if (currentUrl != null && !currentUrl.equals(INDEX_URL)) {
                    SS2.loadUrl(INDEX_URL); // Go back to home
                } else {
                    // Exit app if already at index.html
                    finish();
                }
            }
        });
    }
}
