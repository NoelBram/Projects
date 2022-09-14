import 'package:flutter/material.dart';
import 'package:flutter_markdown/flutter_markdown.dart';

const String _markdownData = """
## Code blocks
Formatted Dart code looks really pretty too:
    ```
    void main() {
      runApp(MaterialApp(
        home: Scaffold(
          body: Markdown(data: markdownData),
        ),
      ));
    }
    ```
""";

class CatVDog extends StatelessWidget {
  const CatVDog({super.key});

  @override
  Widget build(BuildContext context) {
    return const MarkdownBody(
      selectable: true,
      data: _markdownData,
      imageDirectory: 'https://raw.githubusercontent.com',
    );
  }
}
