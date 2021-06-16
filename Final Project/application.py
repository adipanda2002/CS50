from website import create_app

app = create_app()

app.config["TEMPLATES_AUTO_RELOAD"] = True
    
